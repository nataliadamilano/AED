# Etapa #1: Análisis del Problema

- **Transcripción del problema:** Se pide al usuario que ingrese por teclado dos números, luego se deberá de mostrar por pantalla la suma de estos.
- **Refinamiento del problema e hipótesis de trabajo:**

Primero se pedirá que el usuario ingrese por teclado dos números, elegí trabajar con números de tipo entero. Para ello, declararé dos variables de tipo int. Luego, imprimiré por pantalla un texto que le pida al usuario el ingreso de estos dos números enteros. Le indicaré al usuario cuándo estaría ingresando el primer número y por consiguiente, el segundo.
Cuando el usuario ingrese el primer número, se guardará el valor que ingresó en la primer variable que se ha declarado. Lo mismo con el segundo número.


Para finalizar el problema, se imprime por pantalla un mensaje que muestra la suma entre los números que se ingresaron por teclado. La suma se realizaría directamente en el momento en que se muestra dicho mensaje.
**Acá terminaría la resolución del ejercicio** , siendo una hipótesis y una resolución válida, pero pensé en agregar dos bloques de iteración cuya finalidad es:


**1**- El while principal que contiene todo el proceso de ingreso, muestra y suma de enteros lo utilizaré para que el usuario tenga la posibilidad de repetir una adición si quiere (esto se le pregunta por pantalla, en el caso de que desee seguir operando, se le pide ingresar el número '0', sino deberá ingresar un '1'). Antes de que comience este ciclo, agregaré una variable de tipo int que voy a inicializar con el valor '0'. Este ciclo "while" se rompe si el usuario ingresa un '1'.


**2**- El while que está contenido dentro del primero, verificaría que el usuario respete las opciones que se le otorgaron para continuar o salir del programa. Este ciclo se rompería si el usuario ingresa un valor menor que '0' ó mayor que '1'.

<p align="center">
<img src="https://user-images.githubusercontent.com/50343556/80669330-69a65700-8aa4-11ea-991b-1fc9240a54c0.png">
</p>

# Etapa #2 Diseño de la Solución


- **Léxico del Algoritmo:** num1, num2, continuar ∈ **Z**

- **Representación del Algoritmo:**

<p align="center">
  Representación visual
</p>
<p align="center">
<img src="https://user-images.githubusercontent.com/50343556/80672894-2650e600-8aae-11ea-8b0f-e460e0f53ef0.png">
</p>


<p align="center">
  Representación textual
</p>


    **Mientras continuar != 1**


      **Mostrar "Ingrese dos numeros enteros por pantalla, por favor"**
  
  
      **Mostrar "Primer número: "**
  
  
      **Leer num1**
  
  
      **Mostrar "Segundo número: **
  
  
      **Leer num2**
  
  
      **Mostrar "El resultado de la suma es: " num1 + num2**
  
  
      **Mostrar "¿Desea continuar generando adiciones? Ingrese 0 si la respuesta es SI, de lo contrario ingrese un 1."**
  
  
      **Leer continuar**
  
  
      **Mientras continuar < 0 ó continuar > 1**
  
  
        **Mostrar "ERROR. Debe de ingresar una de las opciones sugeridas anteriormente para continuar."**
    
    
        **Leer continuar**
    
    
      **Fin Mientras**
  
  
    **Fin Mientras**
