# Etapa #1: Análisis del Problema

- **Transcripción del problema:** Se deben de realizar las siguientes funciones:

1. Valor absoluto.
2. Valor mínimo entre dos valores.
3. Función F3, definida por:

                  ^    /
                  |   /
                  |  /
               *  3 o
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



# Etapa #2 Diseño de la Solución


- **Léxico del Algoritmo:** num1, num2, continuar ∈ **Z**



    Inicio
    
    continuar = 0

    Mientras continuar != 1


      Mostrar "Ingrese dos numeros enteros por pantalla, por favor"
  
  
      Mostrar "Primer número: "
  
  
      Leer num1
  
  
      Mostrar "Segundo número: 
  
  
      Leer num2
  
  
      Mostrar "El resultado de la suma es: " num1 + num2
  
  
      Mostrar "¿Desea continuar generando adiciones? Ingrese 0 si la respuesta es SI, de lo contrario ingrese un 1."
  
  
      Leer continuar
  
  
      Mientras continuar < 0 ó continuar > 1
  
  
        Mostrar "ERROR. Debe de ingresar una de las opciones sugeridas anteriormente para continuar."
    
    
        Leer continuar
    
    
      Fin Mientras
  
  
    Fin Mientras
    
    Fin
