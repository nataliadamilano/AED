struct Punto { double x, y; };

enum struct Cuadrante { I, II, III, IV, Origen };

enum struct Eje { X, Y };

bool IsIgual(Punto punto1, Punto punto2);

double GetDistancia(Punto punto1, Punto punto2);

double GetDistanciaAlOrigen(Punto punto);

double GetRho(Punto punto);

double GetPhi(Punto punto);

Cuadrante GetCuadrante(Punto punto);

double GetEje(double ejePunto);

Eje GetEje2(Punto punto, double ejePunto);

Punto Mover(Punto& puntoAMover, Punto nuevoPunto);