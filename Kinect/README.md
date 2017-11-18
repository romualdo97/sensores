
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

# 4) ¿Que información transmite un Kinect?

El dispositivo **Kinect es un periférico** que **puede transmitir a un sistema central** información como color a través de una `cámara RGB`, `mapa de profundidad` gracias a su `sensor de profundidad` y `audio gracias` a su `micrófono integrado`, sin embargo cuando esta información es recibida en el **dispositivo de procesamiento principal muchas más cosas se pueden hacer**, como el anteriormente introducido algoritmo de reconocimiento de poses en tiempo real, reconocimiento facial y reconocimiento de voz, entre otros.

> The Kinect contains a regular color camera, sending images of 640*480 pixels 30 times a second. It also contains an active-sensing depth camera using a structured light approach (using what appears to be an infrared LED laser and a micromirror array), which also sends (depth) images of 640*480 pixels 30 times a second (although it appears that not every pixel is sampled on every frame). 
>  [read more here.](http://idav.ucdavis.edu/~okreylos/ResDev/Kinect/MainPage.html)


# 5) ¿Cuáles son los distintos tipos de Kinect?

## Kinect 1414

The **original Kinect-for-Xbox**, released in November 2010, with **model number 1414**. Until version 2.8 of the **Kinect package**, this was the only supported Kinect model.

![enter image description here](https://i.imgur.com/d9FLrsn.jpg)

## Kinect 1473

The new Kinect-for-Xbox, **model number 1473**. This was an **upgrade to make the Kinect-for-Xbox compatible with the then-new Kinect-for-Windows**. First supported in Kinect package version 2.8.

## Kinect 1517 (aka Kinect for Windows version 1.0)  

The **Kinect-for-Windows, model number 1517**. First supported in **Kinect package version 2.8.**

![enter image description here](https://i.imgur.com/BWf94su.png)

## Kinect 1520 (aka Kinect for Windows version 2.0)

The Kinect 2.0, **released together with the Xbox One** in November 2013. Experimentally supported by the Kinect package starting with version number 3.2.

![enter image description here](https://i.imgur.com/sBBSDCf.jpg)

---

The **main difference between models 1414** on the one hand, **and models 1473 and 1517** on the other hand, **is the arrangement of the Kinect's sub-devices** (camera, microphone array, tilt motor, internal USB hub). In model 1414, the camera was the "main" device, and had the Kinect's serial number attached to it. In models 1473 and 1517, the serial number is now attached to the microphone device, and the camera device's serial number is bogus.

**The second-generation Kinect-for-Xbox-One**, or Kinect v2 for short, **is a completely new device that has very little in common with the first-generation Kinect-for-Xbox-360**. Most importantly, **its 3D sensing capabilities are no longer based on stereo reconstruction from a pattern of projected laser dots**, but on measuring the time-of-flight of photons from an emitter on the device, to surfaces in the environment, and back to the device's IR camera. It does this in a very clever way that's worthwhile writing up in detail at some unspecified point in the future.

A continuacion **una breve comparación entre Kinect v1.0 y v2.0** tomadas de [aquí.](https://edwinnui.wordpress.com/2015/02/05/diferencias-entre-kinect-v1-y-kinect-v2-2/)

| Capacidad     | Kinect V1.0     | Kinect V2.0|
| ------------- |:-----| :-----|
| **Video**     | 640×480 @30 fps; 1280×960 @12 fps| 1920×1080 @30 fps High Definition |							
| **Profundidad**| 320×240, 640×480; Distancias 0.8 a 4 metros en modo default.; Distancias de 0.4 a 3 metros en modo cercano (Near mode)| 512×424; Distancias 0.5 a 4.5 metros|
| **Rastreo del cuerpo** | Capacidad para detectar 6 personas, pero solo dos se pueden rastrear completamente; Por cuerpo rastreado, capaz de identificar 20 articulaciones      |Capacidad para detectar 6 cuerpos, todos completamente rastreados.; Por cuerpo rastreado, capaz de identificar 25 articulaciones|
| **Motor de Inclinación**     | Si. Motor puede graduarse entre +27 grados y –27 grados.| No. Tiene mayor ángulo de visión. Sin embargo, en caso de que se requiera, se puede graduar manualmente su inclinación. |
| **USB**     | 2.0 | 3.0; Controlador dedicado |