# Etapa #1: Análisis del Problema

- **Transcripción del problema:** Dado un año, determinar si es bisiesto o no.
- **Refinamiento del problema e hipótesis de trabajo:**

Se definirá una función que dado un año determinará si es bisiesto o no. El dominio de la función que voy a utilizar es ℕxℕ. Para determinar si es bisiesto, hice una investigación (por internet) para saber más a detalle sobre este tema. Según fuentes de internet como Wikipedia (https://es.wikipedia.org/wiki/A%C3%B1o_bisiesto) los años bisiestos comenzaron a partir del año 1582, por lo que, tendré en cuenta los años que sean mayores a éste.


<p align="center">
<img src="https://github.com/nataliadamilano/AED/blob/master/03-Bisiesto/modeloIPO-Bisiesto.PNG">
</p>

# Etapa #2 Diseño de la Solución


- **Léxico del algoritmo:** anio ∈ **ℕ**, IsBisiesto() ∈ **B (bool)**
- **Léxico de la función:** Definiré a la función IsBisiesto(anio) como una proposición compuesta.


Entonces,


   **m** ^ **p** v **q** ^ ~ **r** 
   

  **m**: "anio es mayor a 1582".
  
  
  **p**: "anio dividido 400 tiene resto igual a cero".
  
  
  **q**: "anio dividido 4 tiene resto igual a cero".
  
  
  **r**: "anio dividido 100 tiene resto igual a cero".
    
    
   *El valor de verdad de esta proposición compuesta dependerá del valor que tenga **anio**.*
   
   
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
