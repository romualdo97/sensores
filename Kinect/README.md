
# 1) ¿Que información es capaz de reconocer un kinect?

El `Kinect` es capaz de reconocer el **esqueleto humano y posicionarlo en un plano 2D, también reconoce gestos en el rostro de las personas y mensajes de voz** . Se le clasifica como una Interfaz Natural de Usuario (User Natural Interface) pues no requiere de ninguna interfaz de usuario para  interactuar con el sistema o aplicación particular `(ratón, teclado alfanumérico, lápiz óptico, panel táctil, joystick, etcétera)`.   

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

# 3) ¿Como funciona un Kinect?

El **Kinect** funciona haciendo uso de un **sensor de profundidad** (para el `pose recognition`), **una cámara RGB** (Para el `facial recognition`), un **array de micrófonos** (Para el `voice message recognition`) y **sensor de infrarrojos** (emisor y receptor), a continuación se intentará registrar únicamente los algoritmos relacionados al reconocimiento de poses en tiempo real, según lo expuesto en el paper `Real-Time Human Pose Recognition in Parts from a Single Depth Image`, escrito por los investigadores de Microsoft durante el desarrollo del Kinect y [publicado el 2011 en Microsoft Research](https://www.microsoft.com/en-us/research/publication/real-time-human-pose-recognition-in-parts-from-a-single-depth-image/?from=http://research.microsoft.com/apps/pubs/default.aspx?id=145347).

El equipo de investigación del `human pose recognition` en Microsoft propuso un método para predecir rápidamente y con precisión la posición de las articulaciones del cuerpo sin necesidad de usar información dependiente del tiempo, ellos convirtieron el problema del `reconocimiento de pose` en un problema de `computer vision` y `machine learning`, uno de los principales objetivos del algoritmo desarrollado fue poder **estimar un conjunto de posiciones 3D para cada articulación del esqueleto usando simplemente una única imagen de profundidad**, esta imagen es capturada usando una cámara de profundidad en tiempo real (**aka depth sensor**).

El algoritmo de reconocimiento se inspiro en trabajos que habían sido realizados previamente en el **2003** (`Object class recognition by unsupervised scale-invariant learning`) y **2006** (`The layout consistent random field for recognizing and segmenting partially occluded objects`) relacionados al **reconocimiento de objetos dividiéndolos en partes**.

![enter image description here](https://i.imgur.com/Q9VWPqV.png)
> Figure 1. Overview. From a single input depth image, a per-pixel body part distribution is inferred. (Colors indicate the most likely part labels at each pixel, and correspond in the joint proposals). Local modes of this signal are estimated to give high-quality proposals for the 3D locations of body joints, even for multiple users.

El **logro principal** de la investigación fue **tratar la estimación de pose como un problema de reconocimiento de objetos** usando una técnica de `representación de cuerpos divididos en partes` diseñada para localizar las articulaciones de interés a un bajo costo computacional a través de otros algoritmos de `parallel computing` y `computer vision` usando la `GPU`.