# Especificaciones tipo de dato Punto

## Conjunto de operaciones

### **Función IsIgual**

*IsIgual: Punto x Punto -> **B** *

**IsIgual(punto1, punto2) = { true si (punto1.x == punto2.x) && (punto1.y == punto2.y), false e.o.c  }**


### **Función GetDistancia**

*GetDistancia: Punto x Punto -> **R** *

**GetDistancia(punto1, punto2) = √(punto2.x - punto1.x)^2 + (punto2.y - punto1.y)^2**


### **Función GetDistanciaAlOrigen**

*GetDistanciaAlOrigen: Punto -> **R** *



### **Función GetRho**

*GetRho: Punto -> **R** *


### **Función GetPhi**

*GetPhi: Punto -> **R** *



### **Función GetCuadrante**

*GetCuadrante: Punto -> Cuadrante *



### **Función GetEje**

*GetEje: **R** -> **R** *


### **Función GetEje2**

*GetEje2: Punto, **R** -> Eje *


### **Función Mover**

*Mover: Punto x Punto -> Punto *


## Conjunto de valores

Punto = {x,y / x pertenece a **R**, y pertenece a **R**}

Eje = {X, Y / X pertenece a **enum**, Y pertenece a **enum**}

Cuadrante = {I, II, III, IV, Origen / pertenecen a **enum**}
