# Análisis del Problema

- **Transcripción del problema:** Diseñar un programa C++ que ejemplifique la aplicación de los tipos de datos vistos en clases.
- **Refinamiento del problema e hipótesis de trabajo:** Primero he decidido recrear lo que sería una compra con tarjeta. Ingresaré los datos personales (nombre, apellido) y el número de tarjeta y código de seguridad.
A partir de cierto importe verificaré qué tipo de factura es la que se asignó para saber si deberé de agregar un descuento al importe final o no.

# Crédito Extra
¿Son esos realmente todos los tipos que vimos en clase?
Justifique.

# Crédito Extra
No utilice cout y sí utilice assert para las pruebas.

No, al dar la definición de tipos de variables sabemos que es un conjunto de valores establecidos en un dominio y un conjunto de operaciones con las cuales se puede operar.
Un ejemplo sería el tipo de dato *color*. Su dominio son todos los colores. El conjunto de operaciones pueden ser la adición, sustracción, mezcla, multiplicación, división, etc.

# Etapa #2 Diseño de la Solución


- **Léxico del Algoritmo:** 

nombre, apellido, nroTarjeta ∈ **const string**.


nombreCompleto ∈ **string**.

tipoFactura ∈ **const char**.


codSeguridad ∈ **const int**.


valorItem1, valorItem2,  ∈ **const double**.


importe, importeFinal ∈ **double**.


descuento ∈ **const unasigned int**.


descuentoExiste ∈ **bool**.

- **Representación del Algoritmo:**

<p align="center">
  Representación textual
</p>

   Inicio
    
    //Ingreso nombre
    nombre = "Natalia";
    
    //Ingreso apellido
    apellido = "Damilano";
    
    //Anido nombre y apellido
    nombreCompleto = nombre + "" + apellido;
    
    //Ingreso nro tarjeta
    nroTarjeta = "2324235643127645";
    
    //Ingreso cod seguridad
    codSeguridad = 560;
    
    //Ingreso el valor del item 1
    valorItem1 = 530.60;
    
    //Ingreso el valor del item 2
    valorItem2 = 685.33;
    
    //Sumo los valores para que me de el importe a abonar
    importe = valorItem1 + valorItem2;
    
    //Inicializo importeFinal en cero
    importeFinal = 0;
    
    //Ingreso tipo factura (A, B, C, etc)
    tipoFactura = 'B';
    
    //Ingreso el valor del descuento
    descuento = 30;

    //Compruebo el tipo de factura para ver si agrego descuento o no utilizando el booleano "descuentoExiste"
      Si (tipoFactura == 'B') Entonces
    
        descuentoExiste = true;
      
        //Genero el descuento a partir del importe
        importeFinal = importe * descuento / 100;

      SiNo
    
        importeFinal = importe;
        
      Fin Si
    
    Fin
