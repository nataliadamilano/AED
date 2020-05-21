/* 02-EjemploTipos
 * Se ingresan los datos para la realización de una compra con tarjeta de débito (nombre, apellido, nro tarjeta, código de seguridad)
   y los valores de los dos items que se van a comprar. Dependiendo de si la factura es de tipo "B" se le hará un descuento al cliente.
 * Natalia Belén Damilano
 * 20/5/2020
 */

#include <iostream>
#include <assert.h>     
#include <string>

using namespace std;

int main()
{
    string const nombre = "Natalia", apellido = "Damilano";
    string nombreCompleto, nroTarjeta;
    char tipoFactura;
    int const codSeguridad = 560;
    double valorItem1, valorItem2, importe, importeFinal;
    unsigned int descuento;
    bool descuentoExiste;

    //Anido nombre y apellido
    nombreCompleto = nombre + "" + apellido;
    //Ingreso nro tarjeta
    nroTarjeta = "2324235643127645";
    //Compruebo que el nro de tarjeta tenga un largo de 16 caracteres
    assert(nroTarjeta.length() == 16);
    //Compruebo que el código de seguridad tenga un "largo" mayor o igual que 100 y menor o igual que 999
    assert((codSeguridad >= 100) || (codSeguridad <= 999));
    //Ingreso el valor del item 1
    valorItem1 = 530.60;
    //Ingreso el valor del item 2
    valorItem2 = 685.33;
    //Compruebo que los valores no sean negativos y que no sean nulos
    assert((valorItem1 > 0) && (valorItem2 > 0));
    //Sumo los valores para que me de el importe a abonar
    importe = valorItem1 + valorItem2;
    //Inicializo importeFinal en cero
    importeFinal = 0;
    //Ingreso tipo factura (A, B, C, etc)
    tipoFactura = 'B';
    //Compruebo el ingreso de la factura
    assert(tipoFactura != '\0');
    //Ingreso el valor del descuento
    descuento = 30;
    //Compruebo que el descuento sea mayor a 0 y menor o igual que 100
    assert((descuento > 0) || (descuento <= 100));

    //Compruebo el tipo de factura para ver si agrego descuento o no utilizando el booleano "descuentoExiste"
    if (tipoFactura == 'B')
    {
        descuentoExiste = true;
        //Verifico si descuentoExiste tiene valor true
        assert(descuentoExiste = true);
        //Si pasa el assert entonces genero el descuento a partir del importe
        importeFinal = importe * descuento / 100;
        //Verifico que el importe final sea distinto de nulo
        assert(importeFinal != 0);
    }
    else
    {
        importeFinal = importe;
        //Verifico que el importe final sea distinto de nulo
        assert(importeFinal != 0);
    }
}
