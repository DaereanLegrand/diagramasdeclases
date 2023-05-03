#include <string>
#include <vector>

using std::string;
using std::vector;

struct DATE {
    int day;
    int month;
    int year;
} DATE;

int GetHash();
struct DATE GetDate();

class Usuario;
class Biblioteca;
class Carrito;
class Juego;
class Compra;
class Pago;

int
main()
{

}

class Usuario {
    int idUsuario;
    int nombre;
    string correo;
    string contraseña;

public:
    Usuario(int idUsuarioParams, int nombreParams, string correoParams, string contraseñaParams) :
        idUsuario(idUsuarioParams), nombre(nombreParams), correo(correoParams), contraseña(contraseñaParams) 
    {  }

    int
    getId()
    {
        return idUsuario;
    }
};

class Juego {
    int idJuego;
    string nombre;
    string descripción;
    float precio;
    string categoría;

public:
    Juego(string nom, string desc, int prix, string categ) :
        nombre(nom), descripción(desc), precio(prix), categoría(categ)
    {
        idJuego = GetHash();
    }
};

class Biblioteca {
    int idBiblioteca;
    int idUsuario;
    vector<Juego*> vecJuegos;
   
public:
    Biblioteca(Usuario usuario)
    {
        idUsuario = usuario.getId();
        idBiblioteca = GetHash();
    }

    void 
    agregarJuego(Juego juego)
    {
        vecJuegos.push_back(&juego);
    }
};

class Carrito {
    int idCarrito;
    vector<Juego*> vecJuegos;

public:
    Carrito (int id) :
        idCarrito(id)
    {  }

    void agregarJuego(Juego juego)
    {
        vecJuegos.push_back(&juego);
    }

    vector<Juego*> getvecJuegos();
};


class Pago {
    int idPago;
    int monto;
    struct DATE fecha;

public:
    Pago(int montoParams, struct DATE fechaParams):
        monto(montoParams), fecha(fechaParams)
    { 
        idPago = GetHash();
    }

    ~Pago()
    {  }
};

class Compra {
private:
    int idCompra;
    struct DATE date;
    Usuario* usuario;
    vector<Juego*> vecJuegos;
    Pago* pago;

public:
    Compra(Carrito carrito, Pago* pagoParam, Usuario* user):
        usuario(user), pago(pagoParam)
    {
        idCompra = GetHash();
        date = GetDate();
        vecJuegos = carrito.getvecJuegos();
    }

    ~Compra()
    {
        delete pago;
    }
};
