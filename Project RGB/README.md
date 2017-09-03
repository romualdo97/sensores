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