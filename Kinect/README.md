# 1) ¿Que información es capaz de reconocer un kinect?

El `Kinect` es capaz de reconocer el **cuerpo, gestos en el rostro de las personas y la voz** . Se le clasifica como una Interfaz Natural de Usuario (User Natural Interface) pues no requiere de ninguna interfaz de usuario para  interactuar con el sistema o aplicación particular `(ratón, teclado alfanumérico, lápiz óptico, panel táctil, joystick, etcétera)`.   

# 2) ¿Qué otras tecnologías como Kinect existen?

Aunque las siguientes tecnologías usan un mando o Joystick para desarrollar la interacción entre los usuarios y la aplicación, se consideró apropiado clasificarlas como tecnologías alternativas al Kinect dado que surgieron en un intento de Sony y Microsoft de competir contra el éxito comercial que había logrado el WiiMote Control de Nintendo.

## WiiMote control

Este es el control principal del Wii y se usa principalmente para reconocer movimientos de los jugadores o apuntar a zonas de la pantalla.
Utiliza un acelerometro ADXL330 ([datasheet here](https://www.sparkfun.com/datasheets/Components/ADXL330_0.pdf)) para detectar aceleración a lo largo de tres ejes.

![enter image description here](https://upload.wikimedia.org/wikipedia/commons/a/ad/RVL-A-CW.jpg)

Ademas el Wiimote utiliza un control PixArt  ([datasheet here](http://www.pixart.com.tw/upload/PAW3204DB-TJ3R_DS_S_V1.0_20130514150631.pdf)) para detectar la zona de la pantalla a la que están apuntando los jugadores.

> The **PAW3204DB-TJ3R** is a high performance and **ultra-low power CMOS** process **optical mouse sensor** with **DSP integration chip** that serves as a **non-mechanical motion estimation engine** for implementing a **computer wireless mouse**.

## PlayStation Move

![enter image description here](https://upload.wikimedia.org/wikipedia/commons/7/7f/PlayStation_Move_Motion_Controller.jpg)

Este sensor utiliza la `luz ubicada en la punta del dispositivo` y la cámara `PlayStation Eye` para detectar la posición del mando.  Es capaz de reconocer **movimientos, distintos tipos de gestos** a través de computer vision, así como **voz** usando el micrófono integrado en la `PlayStation Eye`.