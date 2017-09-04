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

# 13) ¿Cuál es la diferencia entre una comunicación serial sincrónica y asíncrona?

Todos los dispositivos en una interfaz serial sincrónica comparten el mismo reloj (estas interfaces pueden ser mas rápidas en la transmisión pero requieren un cable extra para transmitir datos), en contraste con los circuitos asíncronos donde por lo general cada dispositivo utiliza su propio reloj.

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