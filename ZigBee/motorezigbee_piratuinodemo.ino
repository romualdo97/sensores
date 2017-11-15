#include <XBee.h>

#define debugSerial Serial
#define xbeeSerial Serial1

XBee xbee = XBee();

//uint8_t payload[] = {0x54, 0x65, 0x73, 0x74};
uint8_t payload[] = {'H', 'o', 'l', 'i'};
// router 64bit addrs: 0013A2004052DABF

// SH + SL Address of receiving XBee, arguments are (MSB, LSB) of address
XBeeAddress64 addr64 = XBeeAddress64(0x00000000, 0x00000000);
ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));
ZBTxStatusResponse txStatus = ZBTxStatusResponse();

//Object to parse the AT command response.
AtCommandResponse atCommandResoponse = AtCommandResponse();
// At command
AtCommandRequest atCommand = AtCommandRequest("CH");

// Variables to receive packets
ZBRxResponse rx = ZBRxResponse();
ModemStatusResponse msr = ModemStatusResponse();

/*  
 * Prueba piratuino
 *
 * Sensores reflex
 * Iz => D11
 * Ce => D12
 * De => D8
 *
 * De luz
 * LIz => A0
 * LDe => A1
 *
 * Llama
 * Fr => A2
 *
 * Control Motores
 * DIR_M_A => D4
 * PWM_M_A => D5
 * DIR_M_B => D6
 * PWM_M_B => D7 
 */

unsigned char motorState = 0;
unsigned char motorPower = 128;

void setup() {
  //reflex
  pinMode(11, INPUT);
  pinMode(12, INPUT);  
  pinMode(8, INPUT);  
  pinMode(4, OUTPUT);  
  pinMode(5, OUTPUT);  
  pinMode(6, OUTPUT);  
  pinMode(7, OUTPUT);  
  
  debugSerial.begin(9600);
  xbeeSerial.begin(9600);
  //while (!debugSerial);
  xbee.setSerial(xbeeSerial);
}

void loop() {
  if (debugSerial.available()) {
    uint8_t data = debugSerial.read();
    if (data == '1') xbee.send(zbTx);
    if (data == '2') xbee.send(atCommand);
  }
  xbee.readPacket();
  if (xbee.getResponse().isAvailable()) { // Returns true if the response has been successfully parsed and is complete and ready for use
    uint8_t apiID = xbee.getResponse().getApiId();

    if (apiID == ZB_TX_STATUS_RESPONSE) {
      xbee.getResponse().getZBTxStatusResponse(txStatus);
      debugSerial.print(F("REMOTE ADDRESS: "));
      debugSerial.println(txStatus.getRemoteAddress(), HEX);
      debugSerial.print(F("RETRY COUNT: "));
      debugSerial.println(txStatus.getTxRetryCount());
      debugSerial.print(F("DELIVERY STATUS: "));
      debugSerial.println(txStatus.getDeliveryStatus(), HEX);
      debugSerial.print(F("DISCOVERY STATUS: "));
      debugSerial.println(txStatus.getDiscoveryStatus(), HEX);
    } else if (apiID == AT_COMMAND_RESPONSE) {
      xbee.getResponse().getAtCommandResponse(atCommandResoponse);
      debugSerial.print(F("STATUS: "));
      debugSerial.println(atCommandResoponse.getStatus());
      debugSerial.print(F("CHANNEL: "));
      uint8_t *pdata = atCommandResoponse.getValue();
      debugSerial.println(pdata[0], HEX);
    } else if (apiID == ZB_RX_RESPONSE) {
      // now fill our zb rx class
      xbee.getResponse().getZBRxResponse(rx);

      debugSerial.print(F("RX FROM: "));
      XBeeAddress64& addressFrom = rx.getRemoteAddress64();
      debugSerial.print(addressFrom.getMsb(),HEX);
      debugSerial.println(addressFrom.getLsb(),HEX);
      debugSerial.print(F("RX FROM: "));
      debugSerial.println(rx.getRemoteAddress16());
      
      // MOTOR CONTROL
      unsigned char serialData;
      if (rx.getOption() == ZB_PACKET_ACKNOWLEDGED) {
        // the sender got an ACK
        debugSerial.println(F("SENDER GOT AN ACK"));
        serialData = rx.getData(0);
        debugSerial.println(serialData);
        /*for (uint8_t i = 0; i < rx.getDataLength(); i++) {
          debugSerial.write(rx.getData(i));
        }*/
        
        if(serialData >= '1' && serialData <= '5'){
          switch(serialData){
            case '1':
              motorPower = 50;
            break;
            case '2':
              motorPower = 100;
            break;
            case '3':
              motorPower = 150;
            break;
            case '4':
              motorPower = 200;
            break;
            case '5':
              motorPower = 255;
            break;
          }
        }
        else
        {
          motorState =  serialData;
        }
           
        // WARNING: LAS DIRECCIONES ESTAN PRESENTANDO COMPORTAMNIENTOS ANOMALOS
        // EL SIGUIENTE CODIGO SE AJUSTA A LAS ANOMALIAS Y PODRIA NO FUNCIONAR
        // EN UN MOTOR QUE SI FUNCIONE BIEN
        switch(motorState){
          case 'F':
            analogWrite(5, motorPower);
            analogWrite(6, motorPower);
            digitalWrite(4, 1);
            digitalWrite(7, 0);
            
            /*analogWrite(5,motorPower);
            analogWrite(6,motorPower);
            digitalWrite(4,1);
            digitalWrite(7,1);*/
            Serial.println(F("Adelante"));
          break;
      
          case 'B':
            analogWrite(5, motorPower);
            analogWrite(6, motorPower);
            digitalWrite(4, 0);
            digitalWrite(7, 1);
            
            /*analogWrite(5,motorPower);
            analogWrite(6,motorPower);
            digitalWrite(4,0);
            digitalWrite(7,0);*/
            Serial.println(F("Atras"));
          break;
      
          case 'R':
            /*analogWrite(5,motorPower);
            analogWrite(6,0);
            digitalWrite(4,1);
            digitalWrite(7,0);*/
            // ROTACIONES MAS RAPIDAS
            analogWrite(5, motorPower);
            analogWrite(6, motorPower);
            digitalWrite(4, 1);
            digitalWrite(7, 1);
            Serial.println(F("Derecha"));
          break;
      
          case 'L':
            /*analogWrite(5,0);
            analogWrite(6,motorPower);
            digitalWrite(4,0);
            digitalWrite(7,1);*/
            analogWrite(5, motorPower);
            analogWrite(6, motorPower);
            digitalWrite(4, 0);
            digitalWrite(7, 0);
            Serial.println(F("Izquierda"));
          break;
          case 'S':
            analogWrite(5,0);
            analogWrite(6,0);
            digitalWrite(4,0);
            digitalWrite(7,0);
            Serial.println(F("Detenido"));
          break;
          /*default:
            analogWrite(5,0);
            analogWrite(6,0);
            digitalWrite(4,0);
            digitalWrite(7,0);
            Serial.println(F("Detenido"));   */ 
          
          break;
          
        }
        debugSerial.println();
      } else {
        // we got it (obviously) but sender didn't get an ACK
        debugSerial.println(F("SENDER DIDN'T GET AN ACK"));
      }

    } else if (apiID == MODEM_STATUS_RESPONSE) {
      xbee.getResponse().getModemStatusResponse(msr);
      // the local XBee sends this response on certain events, like association/dissociation
      if (msr.getStatus() == ASSOCIATED) {
        // yay this is great.  flash led
        debugSerial.println(F("ASSOCIATED"));

      } else if (msr.getStatus() == DISASSOCIATED) {
        debugSerial.println(F("DISASSOCIATED"));
      } else {
        // another status
        debugSerial.println(F("another status"));
      }
    }
    else {
      debugSerial.print("API ID: ");
      debugSerial.println(apiID);
    }
  }
  else if (xbee.getResponse().isError()) { // returns true if the response contains errors
    // There is an error on the frame
    debugSerial.print("Error code: ");
    debugSerial.println(xbee.getResponse().getErrorCode());
  }

}

