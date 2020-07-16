# Etapa #1: Análisis del Problema

- **Transcripción del problema:** Dado un año, determinar si es bisiesto o no.
- **Refinamiento del problema e hipótesis de trabajo:**

Se definirá una función que dado un año determinará si es bisiesto o no. El dominio de la función que voy a utilizar es ℕxB. Para determinar si es bisiesto, hice una investigación (por internet) para saber más a detalle sobre este tema. Según fuentes de internet como Wikipedia (https://es.wikipedia.org/wiki/A%C3%B1o_bisiesto) los años bisiestos comenzaron a partir del año 1582, por lo que, tendré en cuenta los años que sean mayores a éste.

## MODELO IPO

<p align="center">
<img src="https://github.com/nataliadamilano/AED/blob/master/03-Bisiesto/modeloIPO-Bisiesto.PNG">
</p>

# Etapa #2 Diseño de la Solución


- **Léxico del algoritmo:** anio ∈ **ℕ**, IsBisiesto() ∈ **ℕxB (bool)**
- **Léxico de la función:** Definiré a la función IsBisiesto(anio) como una proposición compuesta.


Entonces,


   **m** ^ [**p** v (**q** ^ ~ **r**)] donde:
   

  **m**: "anio es mayor a 1582".
  
  
  **p**: "anio dividido 400 tiene resto igual a cero".
  
  
  **q**: "anio dividido 4 tiene resto igual a cero".
  
  
  **r**: "anio dividido 100 tiene resto igual a cero".
    
    
   *El valor de verdad de esta proposición compuesta dependerá del valor que tenga **anio**.*
   
   
   
## **REPRESENTACIÓN DEL ALGORITMO**

<p align="center">
  Representación visual
</p>
<p align="center">
<img src="https://github.com/nataliadamilano/AED/blob/master/03-Bisiesto/DDF-Bisiesto.PNG">
</p>


## **ÁRBOL DE EXPRESIÓN**


<p align="center">
<img src="https://github.com/nataliadamilano/AED/blob/master/03-Bisiesto/ArbolExpr-Bisiesto.png">
</p>
