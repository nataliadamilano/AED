/*
Este es un trabajo que tiene como fin abarcar el uso de conceptos tales como Structs y Arrays, realizados con el lenguaje C++.
Se podría tomar como contexto de este trabajo el hecho de que es el comienzo de una enciclopedia metalera,
en donde un aficionado por el género busca analizar cada grupo musical basándose en la información que recopila de cada banda,
esta info serían los años de inicio y fin (si existiera en el momento) de cada banda, algunos de sus álbumes, año de lanzamiento de ellos
y como para empezar, analizar las primeras canciones de cada uno de ellos, teniendo en cuenta su posición en el álbum.
*/

#include <string>
#include <array>
#include <ctime>
#include <iostream>
#include <cassert>

using namespace std;


time_t t = time(NULL); // time_t es un alias de un tipo aritmético que representa tiempos, igual que los que devuelve la función time. Devuelve valores int.
tm* timePtr = localtime(&t); // La función localtime() toma como argumento un puntero de tipo time_t y devuelve un objeto puntero de estructura tm.
// El valor devuelto por la función localtime() es la hora local. En este caso, voy a utilizar uno de los valores que tiene dentro el objeto tm
// para los años, que es "tm_year". Dato: el valor de tm_year empieza a partir de 1900.

// Constantes
const string EN_ACTIVIDAD = "En Actividad";
const string ACTIVA = "La banda está activa actualmente.";
const string INACTIVA = "La banda ha dejado de estar activa.";
const string MISMA_ANTIGUEDAD = "Las dos bandas tienen la misma antigüedad.";

//Enums, Structs y Arrays
enum struct Generos { heavyMetal, powerMetal, rock, thrashMetal };

struct Cancion { string nombre; unsigned posicion; };
using Canciones = array<Cancion, 4>;

struct Album { string nombre; unsigned anioLanzamiento; Canciones canciones; };
using Albumes = array<Album, 4>;

using ArrayAlbumes = array<Albumes, 5>;

struct Banda { string nombre, anioInicio, anioFin; Generos genero; Albumes albumes; };
using Bandas = array<Banda, 5>;

#pragma region Funciones

void GetAlbumes(const Banda& banda);

bool IsMismoGenero(const Banda& banda1, const Banda& banda2);

//void GetAniosActividad(const Banda& banda);

int GetAniosActividad(const Banda& banda);

string GetBandaMasAntigua(const Banda& banda1, const Banda& banda2);

string IsEnActividad(const Banda& banda);

void GetAlbumPorAnio(const unsigned& anio, const Banda& banda);

ArrayAlbumes GetListaAlbumes();

Bandas GetBandas();

#pragma endregion Funciones


int main() {

#pragma region AlbumesyBandas

    Albumes albumesJudasPriest{ { "Painkiller", 1990, {{ {"Painkiller", 1}, {"Hell Patrol", 2}, {"All Guns Blazing", 3}, {"Leather Rebel", 4} }},
        { "Firepower", 2018, {{ { "Firepower", 1 }, { "Lightning Strike", 2 }, { "Evil Never Dies", 3 }, {"Never The Heroes", 4} }} },
        { "British Steel", 1980, {{ {"Breaking The Law", 1}, {"Rapid Fire", 2}, {"Metal Gods", 3}, {"Grinder", 4} }} },
        { "Turbo", 1986, {{ {"Turbo Lover", 1}, {"Locked In", 2}, {"Private Property", 3}, {"Parental Guidance", 4} }} } }
    };

    Albumes albumesMegadeth{ { "Rust In Peace", 1990, {{ {"Holy Wars... The Punishment Due", 1}, {"Hangar 18", 2}, {"Take No Prisoners", 3}, {"Five Magics", 4} }},
        { "Youthanasia", 1994, {{ {"Reckoning Day", 1}, {"Train Of Consequences", 2}, {"Addicted To Chaos", 3}, {"A Tout Le Monde", 4} }} },
        { "Peace Sells... But Who's Buying?", 1986, {{ {"Wake Up Dead", 1}, {"The Conjuring", 2}, {"Peace Sells", 3}, {"Devil's Island", 4} }} },
        { "Countdown To Extinction", 1992, {{ {"Skin O' My Teeth", 1}, {"Symphony Of Destruction", 2}, {"Architecture Of Aggression", 3}, {"Foreclosure Of A Dream", 4} }} } }
    };

    Albumes albumesHelloween{ { "Walls Of Jericho", 1985, {{ {"Starlight", 1}, {"Murderer", 2}, {"Warrior", 3}, {"Victim Of Fate", 4} }},
        { "Keepers Of The Seven Keys Part I", 1987, {{ {"Initiation", 1}, {"I'm Alive", 2}, {"A Little Time", 3}, {"Twilight Of The Gods", 4} }} },
        { "Keepers Of The Seven Keys Part II", 1988, {{ {"Invitation", 1}, {"Eagle Fly Free", 2}, {"You Always Walk Alone", 3}, {"Rise And Fall", 4} }} },
        { "The Time Of The Oat", 1996, {{ {"We Burn", 1}, {"Steel Tormentor", 2}, {"Wake Up The Mountain", 3}, {"Power", 4} }} } }
    };

    Albumes albumesMotorhead{ { "Ace Of Spades", 1980, {{ {"Ace Of Spades", 1}, {"Love Me Like A Reptile", 2}, {"Shoot You In The Back", 3}, {"Live To Win", 4} }},
        { "Overkill", 1979, {{ {"Overkill", 1}, {"Stay Clean", 2}, {"I Won't Pay Your Price", 3}, {"I'll Be Your Sister", 4} }} },
        { "Iron Fist", 1982, {{ {"Iron Fist", 1}, {"Heart Of Stone", 2}, {"I'm The Doctor", 3}, {"Go To Hell", 4} }} },
        { "Bastards", 1993, {{ {"On Your Feet Or On Your Knees", 1}, {"Burner", 2}, {"Death Or Glory", 3}, {"I Am The Sword", 4} }} } }
    };

    Albumes albumesIronMaiden{ { "Ace Of Spades", 1980, {{ {"Ace Of Spades", 1}, {"Love Me Like A Reptile", 2}, {"Shoot You In The Back", 3}, {"Live To Win", 4} }},
        { "Overkill", 1979, {{ {"Overkill", 1}, {"Stay Clean", 2}, {"I Won't Pay Your Price", 3}, {"I'll Be Your Sister", 4} }} },
        { "Iron Fist", 1982, {{ {"Iron Fist", 1}, {"Heart Of Stone", 2}, {"I'm The Doctor", 3}, {"Go To Hell", 4} }} },
        { "Bastards", 1993, {{ {"On Your Feet Or On Your Knees", 1}, {"Burner", 2}, {"Death Or Glory", 3}, {"I Am The Sword", 4} }} } }
    };

    Bandas bandas{ {"Judas Priest", "1969", EN_ACTIVIDAD, Generos::heavyMetal, albumesJudasPriest,
                   {"Megadeth", "1983", EN_ACTIVIDAD, Generos::thrashMetal, albumesMegadeth},
                   {"Helloween", "1984", EN_ACTIVIDAD, Generos::powerMetal, albumesHelloween},
                   {"Motorhead", "1975", "2015", Generos::rock, albumesMotorhead },
                   {"Iron Maiden", "1975", EN_ACTIVIDAD, Generos::heavyMetal, albumesIronMaiden} }
    };

#pragma endregion AlbumesyBandas

#pragma region Invocaciones

    //IsMismoGenero(GetBandas().at(0), GetBandas().at(2));

    //GetAniosActividad(GetBandas().at(3));

    //GetAlbumes(GetBandas().at(0));

    //IsEnActividad(GetBandas().at(3));

    //GetAlbumPorAnio(1980, GetBandas().at(0));

    //GetBandaMasAntigua(GetBandas().at(1), GetBandas().at(3));

#pragma endregion Invocaciones

#pragma region Asserts

    //Asserts a partir de la función "IsMismoGenero"

    assert(not IsMismoGenero(GetBandas().at(0), GetBandas().at(1)));

    assert(not IsMismoGenero(GetBandas().at(2), GetBandas().at(3)));

    assert(not IsMismoGenero(GetBandas().at(0), GetBandas().at(3)));

    assert(IsMismoGenero(GetBandas().at(0), GetBandas().at(4)));

    //Asserts a partir de la función "GetAniosActividad"

    assert(GetAniosActividad(GetBandas().at(3)) == 40);

    assert(GetAniosActividad(GetBandas().at(3)) != 30);

    assert(GetAniosActividad(GetBandas().at(0)) == 51);

    assert(GetAniosActividad(GetBandas().at(0)) != 40);

    assert(GetAniosActividad(GetBandas().at(4)) == 45);

    assert(GetAniosActividad(GetBandas().at(4)) != 50);

    //Asserts a partir de la función "IsEnActividad"

    assert(IsEnActividad(GetBandas().at(2)) == ACTIVA);

    assert(IsEnActividad(GetBandas().at(3)) == INACTIVA);

    assert(IsEnActividad(GetBandas().at(0)) != INACTIVA);

    //Asserts a partir de la función "GetBandaMasAntigua"

    assert(GetBandaMasAntigua(GetBandas().at(2), GetBandas().at(0)) == GetBandas().at(0).nombre);

    assert(GetBandaMasAntigua(GetBandas().at(3), GetBandas().at(4)) == MISMA_ANTIGUEDAD);

    assert(GetBandaMasAntigua(GetBandas().at(1), GetBandas().at(2)) == GetBandas().at(1).nombre);

#pragma endregion Asserts

}

bool IsMismoGenero(const Banda& banda1, const Banda& banda2)
{
    return banda1.genero == banda2.genero;
}

int GetAniosActividad(const Banda& banda)
{
    int aniosActividad;

    if (banda.anioFin == EN_ACTIVIDAD)
    {
        aniosActividad = ((timePtr->tm_year) + 1900) - stoi(banda.anioInicio);
    }
    else
    {
        aniosActividad = stoi(banda.anioFin) - stoi(banda.anioInicio);
    }
    return aniosActividad;

    //if (banda.anioFin == EN_ACTIVIDAD)
    //{
    //    cout << "Banda: " << banda.nombre << '\n' << "Años en actividad: " << ((timePtr->tm_year) + 1900) - stoi(banda.anioInicio) << '\n' << '\n';
    //}
    //else
    //{
    //    cout << "Banda: " << banda.nombre << '\n' << "Años en actividad: " << stoi(banda.anioFin) - stoi(banda.anioInicio) << '\n' << '\n';
    //}
}

string GetBandaMasAntigua(const Banda& banda1, const Banda& banda2)
{
    string bandaMasAntigua;

    banda1.anioInicio < banda2.anioInicio ? bandaMasAntigua = banda1.nombre
        : banda1.anioInicio == banda2.anioInicio ? bandaMasAntigua = MISMA_ANTIGUEDAD
        : bandaMasAntigua = banda2.nombre;

    return bandaMasAntigua;

    //banda1.anioInicio < banda2.anioInicio ? cout << banda1.nombre << " es más antigua." << '\n' << '\n'
//    : cout << banda2.nombre << " es más antigua" << '\n' << '\n';

}

string IsEnActividad(const Banda& banda)
{
    string respuesta;
    banda.anioFin == EN_ACTIVIDAD ? respuesta = ACTIVA
        : respuesta = INACTIVA;
    return respuesta;
}

void GetAlbumPorAnio(const unsigned& anio, const Banda& banda)
{
    for (size_t i = 0; i < banda.albumes.size(); i++)
    {
        if (banda.albumes[i].anioLanzamiento == anio)
        {
            cout << "Album: " << banda.albumes[i].nombre << '\n' << "Lanzamiento: " << anio << '\n' << '\n';

            for (size_t j = 0; j < banda.albumes.data()->canciones.size(); j++)
            {
                cout << banda.albumes[i].canciones[j].posicion << ". " << banda.albumes[i].canciones[j].nombre << '\n';
            }
        }
    }
    cout << '\n';
}

void GetAlbumes(const Banda& banda)
{
    for (size_t i = 0; i < banda.albumes.size(); i++)
    {
        cout << banda.albumes[i].nombre << endl;
    }
}

ArrayAlbumes GetListaAlbumes()
{
    ArrayAlbumes arrayAlbumes{ { { "Painkiller", 1990, {{ {"Painkiller", 1}, {"Hell Patrol", 2}, {"All Guns Blazing", 3}, {"Leather Rebel", 4} }},
        { "Firepower", 2018, {{ { "Firepower", 1 }, { "Lightning Strike", 2 }, { "Evil Never Dies", 3 }, {"Never The Heroes", 4} }} },
        { "British Steel", 1980, {{ {"Breaking The Law", 1}, {"Rapid Fire", 2}, {"Metal Gods", 3}, {"Grinder", 4} }} },
        { "Turbo", 1986, {{ {"Turbo Lover", 1}, {"Locked In", 2}, {"Private Property", 3}, {"Parental Guidance", 4} }} } },

        {{ "Rust In Peace", 1990, {{ {"Holy Wars... The Punishment Due", 1}, {"Hangar 18", 2}, {"Take No Prisoners", 3}, {"Five Magics", 4} }},
        { "Youthanasia", 1994, {{ {"Reckoning Day", 1}, {"Train Of Consequences", 2}, {"Addicted To Chaos", 3}, {"A Tout Le Monde", 4} }} },
        { "Peace Sells... But Who's Buying?", 1986, {{ {"Wake Up Dead", 1}, {"The Conjuring", 2}, {"Peace Sells", 3}, {"Devil's Island", 4} }} },
        { "Countdown To Extinction", 1992, {{ {"Skin O' My Teeth", 1}, {"Symphony Of Destruction", 2}, {"Architecture Of Aggression", 3}, {"Foreclosure Of A Dream", 4} }} } }
        },

        {{ "Walls Of Jericho", 1985, {{ {"Starlight", 1}, {"Murderer", 2}, {"Warrior", 3}, {"Victim Of Fate", 4} }},
        { "Keepers Of The Seven Keys Part I", 1987, {{ {"Initiation", 1}, {"I'm Alive", 2}, {"A Little Time", 3}, {"Twilight Of The Gods", 4} }} },
        { "Keepers Of The Seven Keys Part II", 1988, {{ {"Invitation", 1}, {"Eagle Fly Free", 2}, {"You Always Walk Alone", 3}, {"Rise And Fall", 4} }} },
        { "The Time Of The Oat", 1996, {{ {"We Burn", 1}, {"Steel Tormentor", 2}, {"Wake Up The Mountain", 3}, {"Power", 4} }} } }
        },

        {{ "Ace Of Spades", 1980, {{ {"Ace Of Spades", 1}, {"Love Me Like A Reptile", 2}, {"Shoot You In The Back", 3}, {"Live To Win", 4} }},
        { "Overkill", 1979, {{ {"Overkill", 1}, {"Stay Clean", 2}, {"I Won't Pay Your Price", 3}, {"I'll Be Your Sister", 4} }} },
        { "Iron Fist", 1982, {{ {"Iron Fist", 1}, {"Heart Of Stone", 2}, {"I'm The Doctor", 3}, {"Go To Hell", 4} }} },
        { "Bastards", 1993, {{ {"On Your Feet Or On Your Knees", 1}, {"Burner", 2}, {"Death Or Glory", 3}, {"I Am The Sword", 4} }} }}
        },

        {{ "Ace Of Spades", 1980, {{ {"Ace Of Spades", 1}, {"Love Me Like A Reptile", 2}, {"Shoot You In The Back", 3}, {"Live To Win", 4} }},
        { "Overkill", 1979, {{ {"Overkill", 1}, {"Stay Clean", 2}, {"I Won't Pay Your Price", 3}, {"I'll Be Your Sister", 4} }} },
        { "Iron Fist", 1982, {{ {"Iron Fist", 1}, {"Heart Of Stone", 2}, {"I'm The Doctor", 3}, {"Go To Hell", 4} }} },
        { "Bastards", 1993, {{ {"On Your Feet Or On Your Knees", 1}, {"Burner", 2}, {"Death Or Glory", 3}, {"I Am The Sword", 4}} } } } }}
    };

    return arrayAlbumes;
}

Bandas GetBandas()
{
    Bandas bandas{ {"Judas Priest", "1969", EN_ACTIVIDAD, Generos::heavyMetal,  GetListaAlbumes().at(0),
               {"Megadeth", "1983", EN_ACTIVIDAD, Generos::thrashMetal, GetListaAlbumes().at(1)},
               {"Helloween", "1984", EN_ACTIVIDAD, Generos::powerMetal, GetListaAlbumes().at(2)},
               {"Motorhead", "1975", "2015", Generos::rock, GetListaAlbumes().at(3) },
               {"Iron Maiden", "1975", EN_ACTIVIDAD, Generos::heavyMetal, GetListaAlbumes().at(4)} }
    };

    return bandas;
}

