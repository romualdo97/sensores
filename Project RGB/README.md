[5mm led tecnical spec](https://info.pcboard.ca/led-specifications/5mm-led-technical-specifications/)
# 1) ¿Qué consideraciones debe tener en cuenta para seleccionar un LED?

Es importante saber sí el led es de luz difusa *(diffuse leds)* o luz limpia "(clear leds)" pues los primeros son por lo general mas útiles para fines indicativos mientras que los segundos son mejores en tareas de iluminación de superficies. Ademas también puede ser de gran interés conocer la intensidad luminosa del led así como la caída de voltaje provocada por el led, la temperatura a la que opera y la cantidad de corriente recomendada durante el funcionamiento.

---

# 2) ¿Qué aplicaciones pueden tener los LED en aplicaciones interactivas? (se vale buscar referentes diferente a los de las lecturas)

**Indicar fuerza de golpe**

![enter image description here](https://i.imgur.com/3NMfyvK.jpg)

**Indicar fuerza de tackleo**

![enter image description here](https://www.marketingdirecto.com/wp-content/uploads/2012/06/salta.jpg)

**Animar un camino**

![enter image description here](https://static.webshopapp.com/shops/001680/files/002975793/reflector-del-camino-led-solar.jpg)

---

# 3) ¿Cómo es el circuito de acondicionamiento de un LED a un microcontrolador?. 

**EXPLICAR** y mostrar un ejemplo donde se calcule el circuito de acondicionamiento. Seleccione un LED (de algún fabricante) y busque la hoja de datos del mismo. Utilice los datos de la hoja de datos para realizar los cálculos. Señale exactamente qué parte de la hoja de datos consultó para extraer los datos del LED.


![enter image description here](http://fritzing.org/media/fritzing-repo/projects/p/piscar-um-led/images/Piscar%20um%20Led_2Ue4kOL.png)
> Circuito de acondicionamiento de led a microcontrolador 

**Calculando circuito**

![enter image description here](https://i.imgur.com/ZojhWFA.jpg)

**Señalando hoja de datos**
Los datos de voltaje en la resistencia son calculados a partir de la KVL teniendo en cuenta los valores `promedio`, `typ.`, y `max` de `forward voltage` en la [hoja de características](https://cdn-shop.adafruit.com/datasheets/WP7113SRD-D.pdf) del led rojo.

![enter image description here](https://i.imgur.com/2keUqZc.jpg)

---

# 4) ¿Por qué no se debería conectar un LED directamente a un microcontrolador sin un circuito de acondicionamiento?

Porque pasaría mas corriente de la que puede soportar el led provocando que este deje de ser funcional.

---

# 5) ¿Cómo es posible variar el brillo de un LED utilizando resistencias variables?

Se sabe que entre mas corriente circule a través de un LED mayor será su intensidad lumínica, ademas también es bien conocido de los circuitos en serie que entre menos resistencia posean estos, mas corriente circulara. Ahora, si nos plantemos el caso de un circuito en serie en el que la resistencia varia descubrimos el caso donde la corriente a través del circuito también es variable y por tanto la intensidad lumínica del LED.

---

# 6) ¿Cómo es posible variar el brillo o la intensidad de un LED utilizando una señal de PWM?

Variar el brillo o la intensidad lumínica de un led es posible haciendo que este prenda y apague mas o menos veces por unidad de tiempo.
El led lucira menos brillante cuando permanece mas tiempo apagado durante un ciclo y mas brillante en el caso contrario. Nuestro ojo no es capaz de percibir dicho cambio de estado (led prendido, led apagado) pues ocurre a gran velocidad y en su defecto realiza una integración a la función digital que describe este fenómeno.

---

# 7) ¿Cómo es posible generar diferentes colores utilizando señales de PWM?

Los leds RGB son en realidad un led rojo, verde y azul que funcionan exactamente igual a los leds que han sido descritos anteriormente, entendido esto, podemos notar que sí aplicamos el principio descrito en el punto 6, donde la intensidad lumínica de un led podía ser variada dependiendo del numero de veces que este era apagado y encendido en un periodo de tiempo muy corto, hallamos que la variación de la intensidad lumínica de forma independiente en cada uno de los tres leds que conforman el diodo RGB produce un espacio de color RGB estándar, donde el negro esta descrito como la ausencia de luz.

---

# 8) ¿El programa del micro-controlador es igual sin importar que el LED sea de cátodo o ánodo común? Explique claramente.

No se usa el mismo programa para leds de catodo y anodo común como se puede evidenciar en el siguiente snippet [extraido de adafruit](https://learn.adafruit.com/adafruit-arduino-lesson-3-rgb-leds/arduino-sketch).

    void setColor(int red, int green, int blue)
	{
	  #ifdef COMMON_ANODE
	    red = 255 - red;
		green = 255 - green;
	    blue = 255 - blue;
	  #endif
	  analogWrite(redPin, red);
	  analogWrite(greenPin, green);
	  analogWrite(bluePin, blue);  
	}

La razón de esto es que un led de `cátodo común` utiliza `niveles lógicos positivos` para encender mientras que un led de ánodo común es todo lo contrario, es decir, estos encienden con los `niveles lógicos negativos`, por eso es necesario invertir los parámetros `red`, `green` y `blue`de tal forma que un nivel lógico positivo en el programa, también represente un nivel lógico positivo en el led.

---

# 9) ¿Qué es el duty cycle de una señal de PWM?

Es la fracción de periodo donde la señal PWM esta activa o en un estado logico positivo. El periodo se entiende como el tiempo que le toma a la onda completar un ciclo de encendido y apagado.

![enter image description here](https://wikimedia.org/api/rest_v1/media/math/render/svg/5026ed7ee0beef6b4280d2013485823f8264f2ee)

![enter image description here](https://upload.wikimedia.org/wikipedia/commons/0/02/PWM_duty_cycle_with_label.gif)
> El `duty cycle` es la razón `D` entre la duración del pulso ó `pulse width (PW)`
> y el periodo `(T)` de una onda.

---

# 10) ¿Cómo se calcula el periodo y la frecuencia de una señal de PWM?

Para calcular tanto el periodo como la frecuencia de una señal PWM es necesario un osciloscopio capaz de leer los niveles de voltaje, Lo más importante es poder medir o el periodo o la frecuencia (no las dos), pues si se conoce el periodo hallar la frecuencia es muy fácil y viceversa.

¿Qué pasa si la frecuencia del PWM con la que se controla el LED es muy alta o muy baja?

---

# 11) ¿Qué pasa si la frecuencia del PWM con la que se controla el LED es muy alta o muy baja?

Cuando la frecuencia de PWM es muy alta el periodo es bajo, y por este motivo el brillo será menor *(para más detalles leer punto 6 y 7)*, en cambio cuando la frecuencia es baja el periodo sera alto ocasionando que el brillo en el led sea mayor.

---

# 12) ¿Cuál es la diferencia entre una interfaz paralela y una interfaz serial?

La interfaz serial puede enviar una sola unidad de información a la vez mientras que la interfaz paralela envía ***n*** unidades de información por ciclo.



![enter image description here](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a6/Parallel_and_Serial_Transmission.gif/300px-Parallel_and_Serial_Transmission.gif)

> Comparación entre interfaz paralela y serial.

---

# 13) ¿Cuál es la diferencia entre una comunicación serial sincrónica y asíncrona?

Todos los dispositivos en una interfaz serial sincrónica comparten el mismo reloj (estas interfaces pueden ser mas rápidas en la transmisión pero requieren un cable extra para transmitir datos), en contraste con los circuitos asíncronos donde por lo general cada dispositivo utiliza su propio reloj.

---

# 14) ¿Cuáles son los niveles lógicos del microcontrolador ATmega328P (arduino UNO)? 

> ### TTL Logic Levels
A majority of systems we use rely on 5 V TTL Logic Levels. TTL is an acronym for Transistor-Transistor Logic. It relies on circuits built from bipolar transistors to achieve switching and maintain logic states.
>
>Here is another way of looking at the input / output tolerances for a generic TTL device.
>
![enter image description here](https://cdn.sparkfun.com/assets/6/d/7/7/4/515385fdce395f0905000000.png)
>
>- VOH – Minimum OUTPUT Voltage level a TTL device will provide for a HIGH signal.
>- VIH – Minimum INPUT Voltage level to be considered a HIGH.
>- VOL – Maximum OUTPUT Voltage level a device will provide for a LOW signal.
>- VIL – Maximum INPUT Voltage level to still be considered a LOW.
>### V CMOS Logic Levels
>As technology has advanced, we have created devices that require lower power consumption and run off a lower base voltage (Vcc = 3.3 V instead of 5 V).
>
In order to ensure general compatibility, you will notice that most of the voltage levels are almost all the same as 5 V devices. A 3.3 V device can interface with a 5V device without any additional components. For example, a logic 1 (HIGH) from a 3.3 V device will be at least 2.4 V. This will still be interpreted as a logic 1 (HIGH) to a 5V system because it is above the VIH of 2 V.

>***Extracted from:***  [SparkFun explanation of Logic Levels](https://learn.sparkfun.com/tutorials/logic-levels)

[PAGINA 365, 366 Atmega328P datasheet](http://www.atmel.com/Images/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf):

![enter image description here](https://i.imgur.com/zEBxI4c.png)
![.](https://i.imgur.com/jLCJjkU.png)
![enter image description here](https://i.imgur.com/FQ29TP8.png)
![enter image description here](https://i.imgur.com/t1bRdYX.png)

---

# 15) En base a la respuesta anterior qué debe considerar al conectar, por medio de una interfaz serial, un micro-controlador que opera a 5V con un sensor o actuador que opera a 3V o 3.3V


Es necesario hacer coincidir los rangos de voltaje en los dos dispositivos por ejemplo, el `voh` del microcontolador que opera a 5v deberá ser reducido aproximadamente a menos de 3.3 voltios de tal forma que el sensor de 3.3v no se dañe.


![enter image description here](https://cdn.sparkfun.com/r/400-400/assets/3/a/a/9/7/518d5681ce395f1e11000000.png) ![enter image description here](https://cdn.sparkfun.com/assets/f/4/e/d/2/518d4d55ce395f035c000000.png)

---

# 16) ¿Qué son los bits de sincronización, datos y paridad en una comunicación serial? Explique y muestre además un diagrama de tiempos que ilustre su respuesta.

Los datos son un conjunto de entre 5 a 9 bits que describen la información que desea ser transmitida a otro dispositivo.
Los bits de sincronización son los encargados de marcar el inicio y final de un paquete de bits de datos.
El bit de paridad es opcional en la transmisión de información y se usa para detección de errores, aunque disminuye la velocidad de transmisión, Consiste básicamente en sumar los dígitos del paquete de datos y determinar si hay una cantidad par o impar de unos.

---

# 17) ¿Qué es y ejemplifique el baud rate?

El baud rate es un número que indica que tan rápido están siendo enviados o recibidos los datos a través de la linea serial *(su unidad es el bit-per-second)*.
Por ejemplo un sensor que envia 9600 bits cada segundo por medio de una interfaz serial a un microcontrolador tendrá un baud de 9600.

![enter image description here](https://cdn.sparkfun.com/assets/f/c/6/2/4/52ddb2d5ce395f59658b4567.png)
> Example of a serial interface, transmitting one bit every clock pulse!

---

# 18) ¿Cómo se aplica el concepto de endian cuando se realiza una comunicación serial?

Haciendo acuerdo entre los dispositivos de enviar primero el bit mas significativo o el menos significativo.

![enter image description here](https://upload.wikimedia.org/wikipedia/commons/thumb/5/54/Big-Endian.svg/400px-Big-Endian.svg.png)

![enter image description here](https://upload.wikimedia.org/wikipedia/commons/thumb/e/ed/Little-Endian.svg/400px-Little-Endian.svg.png)

> La nomenclatura de los criterios little-endian y big-endian proviene de la novela Los viajes de Gulliver de Jonathan Swift, hace referencia a una sociedad donde había dos grupos enemistados, uno sostenía que los huevos duros se tenían que empezar a comer por el extremo grande (big end) o otros por el pequeño (little end). De ahí que big endian se debe entender como "de comienzo por el extremo mayor" y little endian como "de comienzo por el extremo pequeño", aunque es propenso a confundirse con "acaba en grande" y "acaba en pequeño". Su etimología proviene de un juego de palabras en inglés con los términos compuestos little-end-in y big-end-in. 
> ***Extracted from:***  [Endianness](https://es.wikipedia.org/wiki/Endianness)

---

# 19) Realice un diagrama de tiempo donde muestre cómo se vería el mensaje hola mundo enviado desde el Arduino UNO con la función Serial.println(“Hola Mundo”) a otro arduino UNO.

![enter image description here](https://i.imgur.com/LkyUAf8.png)

![enter image description here](https://i.imgur.com/8pfliHr.png)

![enter image description here](https://i.imgur.com/K2EFH4h.png)

![enter image description here](https://i.imgur.com/Cxiovsp.png)

![enter image description here](https://i.imgur.com/ViYeJtM.png)

![enter image description here](https://i.imgur.com/NffWSm3.png)

---

# 20) Muestre un diagrama que ilustre cómo se realizaría la conexión a nivel de hardware entre los dos arduinos del punto anterior.

![enter image description here](http://robotic-controls.com/sites/default/files/learn/Arduino-ArduinoSerial.png)

---

# 21) Descargue el diagrama esquemático de un arduino UNO R3. 

**IDENTIFIQUE**: cómo se conecta al computador, cómo se conectan el puerto serial a los conectores externos de la tarjeta.

![enter image description here](https://i.imgur.com/JLek0yM.png)

Los pines diferenciales D+ y D- de la interfaz USB-B se conectan a los pines 30 y 29 del ATMEGA16U2. 

![enter image description here](https://i.imgur.com/Bib4UtP.png)

Los conectores externos 0 y 1 de la tarjeta arduino están conectados a los pines RXD (pin 2 del ATMEGA328P)  y TXD (pin 3 del ATMEGA328P) respectivamente, así mismo los conectores externos están conectados también a los pines 9 y 8 del ATMEGA16U2 que funciona como un puente entre la interfaz USB del computador y el procesador principal del puerto serial en el ATMEGA328P.

---

# 22) ¿Cuál es la diferencia entre comunicaciones seriales TTL y comunicaciones seriales RS232?

La capa física de las interfaces TTL tiene 2 pines mientras que las del RS232 posee 9 pines, los niveles lógicos de voltajes son mayores en el RS232 **[-5v, 5v]** o **[-12v, 12v]** con respecto al TTL **[0v, 5v]** o **[0v, 3.3v]**, ademas el RS232 utiliza lógica inversa.

---

# 23) ¿Qué es una UART?

![enter image description here](http://www.circuitbasics.com/wp-content/uploads/2016/01/Introduction-to-UART-Data-Transmission-Diagram.png)

Las siglas significan *Universal Asynchronous Receiver-Transmitter*, en español: **Transmisor-Receptor Asíncrono Universal** no es un protocolo de comunicación como SPI o I2C pero si un circuito electrónico físico, su tarea principal es enviar y recibir datos en serial.

En las comunicaciones con UARTs se necesitan dos UARTs, la UART que transmite convierte datos paralelos desde algún dispositivo controlador como una CPU en datos seriales. La UART receptora luego convierte los datos seriales en paralelos para el dispositivo receptor.

![enter image description here](http://www.circuitbasics.com/wp-content/uploads/2016/01/Introduction-to-UART-Basic-Connection-Diagram-300x147.png)
> solo se necesitan dos cables para transmitir información entre las UARTs

Las UARTs transmiten los datos de forma paralela, es decir que no se usan señales de reloj para sincronizar los datos, en vez de esto los paquetes de información son enviados con un par de bits que indican el inicio de la transmisión y el final.

---

# 24) Explique ¿Cuáles son los errores más comunes a la hora de conectar dispositivos por puerto serial?

Intentar conectar dos dispositivos al mismo puerto serial y tener baud rates distintos entre los dispositivos seriales.

---

# 25) ¿Qué sensores utiliza el proyecto 2 del texto guía?

El proyecto 2 del texto guia utiliza *2 flex sensor resistors* que permiten medir qué tanto se dobla una superficie.

---

# 26) ¿Cómo funcionan los sensores del punto anterior? 

[Flex Sensor Hookup Guide](https://learn.sparkfun.com/tutorials/flex-sensor-hookup-guide)

One side of the sensor is printed with a polymer ink that has conductive particles embedded in it.
Un lado del sensor está pintado con una tinta que tiene partículas conductivas.

![enter image description here](https://cdn.sparkfun.com/assets/learn_tutorials/5/1/1/how-it-works-straight.png)

Cuando el sensor no esta doblado las partículas conductivas estan mas proximas y por tanto la resistencia es menor.

![enter image description here](https://cdn.sparkfun.com/assets/learn_tutorials/5/1/1/how-it-works-bent.png)

Cuando el sensor se dobla las partículas conductivas se separan y por tanto aumenta la resistencia.

---

# 27) ¿Qué usos pueden tener los sensores del punto anterior en aplicaciones de interacción? 

Podrían ser usados como sensor para conocer qué tanto se abre una puerta y provocar un sonido tenebroso dependiendo del nivel de apertura, o también para simular el acelerador de un automóvil y aumentar la cantidad de viento que percibe el usuario.

---

# 28) Explique ¿Cuál es la diferencia entre los métodos println y write utilizados con el objetos Serial? Muestre ejemplos con código que ilustren la diferencia.

    Serial.println(48); // prints 48\n (52, 57, 10) into serial monitor 
	Serial.write(48); // prints 0 into serial monitor (sin salto de linea)
	
	Serial.println("A"); // prints A\n (65, 10) into serial monitor
	Serial.println("A"); // prints A (65) into serial monitor (sin salto de linea)

---

# 29) Explique el protocolo de comunicación, utilizado en el proyecto 2 del texto guía, para comunicar el arduino con processing.

> 284,284,1,1,

Los primeros tres números indicaran el nivel de flexión del primer brazo del monkey, los siguientes tres números  indicaran lo mismo para el brazo izquierdo del monkey, los últimos dos números indican si reiniciar el juego o servir la pelotita de pong.

---

# RETO PROTOCOLO RGB

## **Vídeo**

[Ver vídeo aquí](https://youtu.be/L6jDSlN3500)

![enter image description here](https://i.imgur.com/ttazoJV.png)
> En el vídeo se muestra como variando tres sliders podemos seleccionar un color del espacio de color RGB

## **Esquemático**

![enter image description here](https://i.imgur.com/6VYxIFI.png)

> Se conecta el TX de la uart del bluetooth con el RX de la uart del arduino (Esta implementación no necesita que el arduino transmita datos a la tableta android).

## **Aplicación**

Es necesario mover los slider R, G y B para poder recorrer el susodicho espacio de color.

![enter image description here](https://i.imgur.com/tNrk5ud.png)

![enter image description here](https://i.imgur.com/1yQ8TKf.png)

![enter image description here](https://i.imgur.com/a5Kutnm.png)


## **Código fuente en AppInventor**

Iniciamos variables globales para mantener el estado de las componentes del vector de color RGB.

![enter image description here](https://i.imgur.com/uyRdPou.png)

Definimos una función para decidir que pantalla tener encendida.

![enter image description here](https://i.imgur.com/H5YbLmf.png)

Definimos una función encargada de todas las acciones de dibujo y visualizacion.

![enter image description here](https://i.imgur.com/UIkYa7L.png)

Hacemos que la pantalla cero sea visible cuando inicia la aplicación

![enter image description here](https://i.imgur.com/i5FXdvK.png)

Mostramos una lista de conexiones disponibles.

![enter image description here](https://i.imgur.com/gZQKCRE.png)

Nos conectamos al arduino mediante Bluetooth

![enter image description here](https://i.imgur.com/aQvjO91.png)

Escuchamos por cambios en la posición del slider rojo.

![enter image description here](https://i.imgur.com/afjPwPO.png)

Escuchamos por cambios en la posición del slider verde.

![enter image description here](https://i.imgur.com/qc4mrwv.png)

Escuchamos por cambios en la posición del slider azul.

![enter image description here](https://i.imgur.com/3oGcTgn.png)

## **Código fuente en Arduino Leanoardo**

El siguiente programa se encarga de gestionar los mensajes que recibe, es decir gestionar los mensajes del protocolo RGB y guardar los cambios en la memoria EEPROM del Arduino.

    #include <string.h>
	#include <EEPROM.h>
	
	#define DEBUG_MODE
	// #define DEBUG_MODE_4_SERIAL1
	
	#define MAX_BUFF_SIZE 16  // (RGB=123,123,123\n).size() == 16
	
	#define PIN_4_RED 5
	#define PIN_4_GREEN 6
	#define PIN_4_BLUE 9
	
	byte red_val = 0;
	byte green_val = 0;
	byte blue_val = 0;
	
	// find the number of digits in the array arr 
	// of length len
	uint8_t get_num_of_digits(char *arr)
	{
	  uint8_t num_dig = 0; // num of digits
	  
	  if (isDigit(arr[0])) 
	  {    
	    num_dig++;
	  }
	  if (isDigit(arr[0]) && isDigit(arr[1]) ) 
	  {    
	    num_dig++;
	  }
	  if (isDigit(arr[0]) && isDigit(arr[1]) && isDigit(arr[2])) 
	  {    
	    num_dig++;
	  }
	  return num_dig;
	}
	
	bool is_usage_error(char *myBuff)
	{
	  // return a pointer to the first occurence of characters "RGB=" in storage_buffer
	  char *RGB_tag = strchr(myBuff, 'R');
	  bool isNoRGB_tag = RGB_tag[0] != 'R' || RGB_tag[1] != 'G' || RGB_tag[2] != 'B' || RGB_tag[3] != '=';
	  if (isNoRGB_tag) 
	  {
	    #ifdef DEBUG_MODE
	    Serial.println("ERROR::USAGE::NO_RGB_TAG_FOUND");
	    #endif
	    return true;
	  }
	  return false;
	}
	
	byte get_chanel_value(uint8_t num_digits, char *arr)
	{
	  byte chnl_value = 0;
	  for (int i=0; i < num_digits; i++)
	  {
	    chnl_value *= 10;
	    chnl_value += arr[i] - 48;
	  }
	  
	  return chnl_value;
	}
	
	void process_buffer(const char *myBuff)
	{
	  #ifdef DEBUG_MODE
	  Serial.println(myBuff);
	  #endif
	  
	  if (is_usage_error(myBuff))
	  {
	    #ifdef DEBUG_MODE
	    Serial.println("This running");
	    #endif
	    return;
	  }
	  
	  // return a pointer to the first occurence of character '=' in storage_buffer
	  char *q = strchr(myBuff, '=');
	
	  // find num of digits for RED channel
	  char *red_ch = q + 1; // array for red channe.
	  uint8_t num_dig = get_num_of_digits(red_ch);
	  red_val = get_chanel_value(num_dig, red_ch);
	  #ifdef DEBUG_MODE
	  Serial.print("Red val: ");
	  Serial.print(red_val); Serial.print("\n");
	  #endif
	  analogWrite(PIN_4_RED, red_val);
	  EEPROM.update(3, red_val);
	
	  // find num of digits for GREEN channel
	  char *green_ch = red_ch + num_dig + 1;
	  num_dig = get_num_of_digits(green_ch);
	  green_val = get_chanel_value(num_dig, green_ch);
	  #ifdef DEBUG_MODE
	  Serial.print("Green val: ");
	  Serial.print(green_val); Serial.print("\n");
	  #endif
	  analogWrite(PIN_4_GREEN, green_val);
	  EEPROM.update(4, green_val);
	
	  // find num of digits for BLUE channel
	  char *blue_ch = green_ch + num_dig + 1;
	  num_dig = get_num_of_digits(blue_ch);
	  blue_val = get_chanel_value(num_dig, blue_ch);
	  #ifdef DEBUG_MODE
	  Serial.print("Blue val: ");
	  Serial.print(blue_val); Serial.print("\n");
	  #endif
	  analogWrite(PIN_4_BLUE, blue_val);
	  EEPROM.update(5, blue_val);
	}
	
	void process_incoming_byte(const char inByte)
	{
	  static char storage_buffer[MAX_BUFF_SIZE];
	  static uint8_t count = 0;
	  // if end then add null char
	  // else add the incoming byte to buffer
	  if (inByte == 0x0A) // inByte == New Line
	  {
	    storage_buffer[count] = 0;
	    process_buffer(storage_buffer);
	    storage_buffer[0] = '\0';
	    count = 0;
	  }
	  else 
	  {
	    storage_buffer[count] = inByte;
	    count++;
	  }
	}
	
	void setup() 
	{
	  EEPROM.get(3, red_val);
	  EEPROM.get(4, green_val);
	  EEPROM.get(5, blue_val);
	  
	  pinMode(PIN_4_RED, OUTPUT);
	  pinMode(PIN_4_GREEN, OUTPUT);
	  pinMode(PIN_4_BLUE, OUTPUT);
	
	  analogWrite(PIN_4_RED, red_val);
	  analogWrite(PIN_4_GREEN, green_val);
	  analogWrite(PIN_4_BLUE, blue_val);
	  
	  Serial.begin(9600);
	  Serial1.begin(9600);
	}
	
	void loop() 
	{
	  while (Serial1.available())
	  {
	    byte data = Serial1.read();
	    #ifdef DEBUG_MODE_4_SERIAL1
	    Serial1.write(data);
	    #endif
	    #ifdef DEBUG_MODE
	    Serial.write(data);
	    #endif
	    process_incoming_byte(data);
	  }
	}