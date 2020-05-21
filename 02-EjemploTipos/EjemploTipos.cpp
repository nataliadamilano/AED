/* 02-EjemploTipos
 * 
 * Natalia Belén Damilano
 * 20/5/2020
 */

#include <iostream>
#include <assert.h>     /* assert */

using namespace std;

int main()
{
    string nombre, apellido, nombreCompleto, nroTarjeta;
    char tipoFactura;
    int codSeguridad;
    double valorItem1, valorItem2, importe, importeFinal;
    unsigned int descuento;
    bool descuentoExiste;

    //Ingreso nombre
    nombre = "Natalia";
    //Ingreso apellido
    apellido = "Damilano";
    //Compruebo que nombre y apellido no sean vacíos con Assert
    assert(apellido != apellido.empty);
    assert(nombre != nombre.empty);
    //Anido nombre y apellido
    nombreCompleto = nombre + "" + apellido;
    //Ingreso nro tarjeta
    nroTarjeta = "2324235643127645";
    //Ingreso cod seguridad
    codSeguridad = 560;
    //Compruebo que el nro de tarjeta tenga un largo de 16 caracteres
    assert(nroTarjeta.length = 16);
    //Compruebo que el código de seguridad tenga un "largo" mayor o igual que 100 y menor o igual que 999
    assert((codSeguridad >= 100) && (codSeguridad <= 999));
    //Ingreso el valor del item 1
    valorItem1 = 530.60;
    //Ingreso el valor del item 2
    valorItem2 = 685.33;
    //Compruebo que los valores no sean negativos y que no sean nulos
    assert(valorItem1 > 0 && (valorItem1 != NULL));
    assert(valorItem2 > 0 && (valorItem2 != NULL));
    //Sumo los valores para que me de el importe a abonar
    importe = valorItem1 + valorItem2;
    //Ingreso el importe final hasta el momento
    importeFinal = importe;
    //Ingreso tipo factura (A, B, C, etc)
    tipoFactura = 'B';
    //Compruebo el ingreso de la factura
    assert(tipoFactura <> NULL);
    //Ingreso el valor del descuento
    descuento = 30;
    //Compruebo que el descuento sea mayor a 0 y menor o igual que 100
    assert((descuento > 0) && (descuento <= 100));

    //Compruebo el tipo de factura para ver si agrego descuento o no utilizando el booleano "descuentoExiste"
    if (tipoFactura == 'B')
    {
        descuentoExiste = true;
        //Verifico si descuentoExiste tiene valor true
        assert(descuentoExiste = true);
        //Si pasa el assert entonces genero el descuento a partir del importe
        importeFinal *= descuento / 100;
        //Verifico que el importe final sea distinto de nulo
        assert(importeFinal <> NULL);
    }
}
