# Especificaciones tipo de dato Polígono

## Conjunto de operaciones

### **Función AddVertice**

*AddVertice: Poligono, Punto -> Poligono.vertices[poligono.n++] = Punto*


### **Función GetVertice**

*GetVertice: Poligono, **Z** -> Punto*


### **Función SetVertice**

*SetVertice: Poligono, **Punto** actual x **Punto** nuevo -> Poligono.vertices[poligono.n == posición(actual)] = nuevo*



### **Función RemoveVertice**

*RemoveVertice: Poligono -> Poligono.vertices[poligono.n-1]*


### **Función GetCantidadLados**

*GetCantidadLados: Poligono -> **Z** *



### **Función GetPerimetroPoligono**

*GetPerimetroPoligono: Poligono -> **R** *



### **Función GetDistancia**

*GetDistancia: Punto x Punto -> **R** *


## Conjunto de valores

U = {x / x pertenece a **Z**; 0 <= x <= 255 };

n = { x / x pertenece a **Z** };

vertices = { r / r pertenece a **array<Punto, MAX>**};

red = {s / s pertenece a **Z**; 0 <= s <= 255};

green = {q / q pertenece a **Z**; 0 <= q <= 255};

blue = {t / t pertenece a **Z**; 0 <= t <= 255};

Color = {red X green X blue}

Poligono = {n X vertices X Color}
