

# Análisis del Problema

- **Transcripción del problema:** Diseñar un tipo Color basado en el modelo RGB, con tres canales de 8 bits. Todo color está compuesto por tres componentes: intensidad de red (rojo), de green (verde), y de blue (azul). Cada intensidad está en el rango [0, 255]. Definir los valores para rojo, azul, verde, cyan, magenta, amarillo, negro, y blanco. Dos colores se pueden mezclar, lo cual produce un nuevo color que tiene el promedio de intensidad para cada componente.


- **Refinamiento del problema e hipótesis de trabajo:**

    Se definirá un tipo de dato Color que estará compuesto por los tres canales de 8 bits del modelo RGB que representarán el rojo (R), verde (G) y azul (B). Deberé definir los colores primarios, secundarios, blanco y negro de manera que no sean modificables. A partir de las funciones que se piden en los puntos extra, deberé tener en cuenta que en alguno de ellos tendré que establecer la intensidad de cada color en el rango [0, 255], para eso me es conveniente establecerlos como constantes ya que al ser un rango ya definido, tendré que respetarlo.


# ¿Porqué se debe usar uint8_t?

Como estamos trabajando con una representación de color a partir del modelo RGB, que, al tener tres canales de colores de 8 bits cada uno, y además estamos trabajando en un sistema en donde el número de bits por caracter es 8, el usar int8_t permite abarcar el ancho de cada unidad direccionable con exactamente 8 bits de valor y sin bits de relleno. Esto significa que uint8_t va a tener un valor máximo de 255, que es el rango establecido en cada canal del modelo RGB.

# Si no es posible usar uint8_t, ¿es correcto usar unsigned char y no char?

Sí. Unsigned char también representa un rango que tiene como valor máximo 255 y, aunque puedan ser vistos como tipos de caracteres, también son tipos enteros ya que el estándar de C++ establece que lo son.
