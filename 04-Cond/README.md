# Etapa #1: Análisis del Problema

- **Transcripción del problema:** Se deben de realizar las siguientes funciones:

1. Valor absoluto.
2. Valor mínimo entre dos valores.
3. Función **F3**, definida por:

                  ^     /
                  |    /
                  |   /
               *  3  o
                \ |
                 \|
         <-----3--0--3----->
                  |\
                  | \
               o -3  *
              /   |
             /    |
            /     v


- **Refinamiento del problema e hipótesis de trabajo:**

Separaríamos como un proyecto individual cada función. 
La función valor absoluto debería respetar un dominio de enteros **ℤ** con una respectiva imagen en **ℤ**.
La función valor mínimo entre dos valores la representaría con reales **ℝ**.
La función por partes **F3** debería de estar definida en los reales **ℝ→ℝ**.

Definiría el prototipo de cada función, asignándole un nombre identificable y con qué tipo de valores trabajaría (si enteros, reales, etc).


Desarrollaría las definiciones de cada prototipo, teniendo en cuenta qué tipo de función es (valor absoluto, función por partes, etc) y el dominio en el que está representada.

En cada proyecto haría pruebas con distintos valores teniendo en cuenta el análisis de cada función a partir de su dominio e imagen (si la hay, en el caso de la función de valor mínimo esto no estaría contemplado ya que solo sería comparar valores) para corroborar que éstas estén desarrolladas y funcionen correctamente.


# Etapa #2 Diseño de la Solución


- **Léxico del Algoritmo:** 

1. Función Valor Absoluto: **Abs: ℤ→ℤ/Abs(x) = |x| = { -x si  x < 0; x e.o.c }**
2. Función valor Mínimo entre dos valores: **Min: a,b ∈ ℝ / Min(a,b) = { a si a < b; b e.o.c}**
3. Función por partes F3: **F3: ℝ→ℝ / F3(x) = { -x si x >= -3 ^ x <= 3; x e.o.c }**
