#include <iostream>
using namespace std;

struct nodo// mal 
{
    float valor;
    nodo *siguiente = NULL;
    nodo *anterior = NULL;
};

nodo *inicio;
nodo *final = NULL;

void Mostrar()
{
    nodo *aux = inicio;
    if (inicio == NULL)
    {
        cout << endl << "Su lista esta vacia." << endl;
    }
    else
    {
        cout << endl << "Su lista es: ";
        cout << aux -> valor;
        aux = aux -> siguiente;

        while (aux != inicio)
        {
            cout << " -> " << aux -> valor;
            aux = aux -> siguiente;
        }
        cout << endl;
    }
}
void InsertarFinal(int value)
{
    if(final == NULL)
    {
        nodo *aux = new nodo;
        aux -> valor = value;
        final = aux;
        inicio = aux;
    }
    else
    {
        nodo *aux= new nodo;
        final -> siguiente = aux;
        aux -> valor = value;
        aux -> siguiente = NULL;
        aux -> anterior = final;
        final = aux;
        final -> siguiente = inicio;
        inicio -> anterior = final;
    }
    cout << endl << "Elemento anadido correctamente." << endl;
}
void InsertarInicio(int value)
{
    nodo *aux = new nodo;
    if(inicio == NULL)
    {
        aux -> valor = value;
        aux -> siguiente = aux;
        aux -> anterior = aux;
        inicio = aux;
        final = aux;
    }
    else
    {
        inicio -> anterior = aux;
        aux -> valor = value;
        aux -> siguiente = inicio;
        aux -> anterior = NULL;
        inicio = aux;
        final -> siguiente = inicio;
        inicio -> anterior = final;
    }
    cout << endl << "Elemento anadido correctamente." << endl;
}
void InsertarElegida(int position, int value)
{
    nodo *aux = inicio;
    nodo *predecesor = new nodo;
    predecesor -> siguiente = aux;

    for (int i = 0; i < position - 1; i++)
    {
        predecesor = predecesor -> siguiente;
        aux = aux -> siguiente;
        if (aux == inicio)
        {
            i = position;
            cout << "La lista es demasiado corta y no alcanza la posicion solicitada." << endl;
            cout << "El nuevo elemento se ha anadido en la ultima posicion." << endl;
        }
    }
    aux = new nodo;
    aux -> siguiente = predecesor -> siguiente;
    aux -> anterior = predecesor;
    predecesor -> siguiente = aux;
    aux -> valor = value;
    aux = aux -> siguiente;
    aux -> anterior = predecesor -> siguiente;
    if (aux -> siguiente == inicio) { final = aux; }

    cout << endl << "Elemento anadido correctamente." << endl;
}
void HallarMayor()
{
    nodo *aux = inicio;
    float mayor = -99999;
    int i = 0;
    if (inicio == NULL) { cout << endl << "La lista esta vacia." << endl; }
    else
    {
        do
        {
            if (aux -> valor > mayor)
            {
                mayor = aux -> valor;
                i = 1;
            }
            else if (aux -> valor == mayor) { i++; }
            aux = aux -> siguiente;
        } while (aux != inicio);
        cout << endl << "El mayor elemento es " << mayor << " y se ha encontrado " << i << " ve";
        if (i == 1) { cout << "z." << endl; } else { cout << "ces." << endl; }
    }
}
void SumarTodo()//mal esta funciom
{
    nodo *aux = inicio;
    float sumatorio = 0;
    if (inicio == NULL) { cout << endl << "La lista esta vacia." << endl; }
    else
    {
        do
        {
            sumatorio += aux -> valor;
            aux = aux -> siguiente;
        } while (aux != inicio);
        cout << endl << "La suma de todos los elementos es " << sumatorio << endl;
    }
}
void ComprobarOrdenada()
{
    if (inicio == NULL) { cout << endl << "La lista esta vacia." << endl; }
    else
    {
        string ordenada = "SI";
        nodo *aux = inicio -> siguiente;
        do
        {
            if (aux -> valor < aux -> anterior -> valor)
            {
                ordenada = "NO";
                aux = final;
            }
            aux = aux -> siguiente;
        } while (aux != inicio);

        cout << endl << "La lista " << ordenada << " esta ordenada" << endl;
    }
}
void Eliminar(int value)
{
    nodo *aux = inicio;

    int i = 0;
    if (inicio == NULL) { cout << endl << "Su lista esta vacia." << endl; }
    else
    {
        do
        {
            if (aux -> valor == value)
            {
                if (inicio == final)
                {
                    delete aux;
                    aux = NULL;
                    inicio = NULL;
                    final = NULL;
                    i++;
                }
                else
                {
                    nodo *predecesor = aux -> anterior;
                    aux -> anterior -> siguiente = aux -> siguiente;
                    aux -> siguiente -> anterior = aux -> anterior;
                    if (aux == inicio) { inicio = aux -> siguiente; }
                    else if (aux == final) { final = aux -> anterior; }
                    delete aux;
                    aux = predecesor -> siguiente;
                    i++;
                }
            }
            else
            {
                aux = aux -> siguiente;
            }
        } while (aux != inicio);
        cout << endl << "El valor " << value << " se ha eliminado en " << i << " ocasion";
        if (i != 1) { cout << "es." << endl; } else { cout << "." << endl; }
    }
}
void Invertir()
{
    nodo *aux = final;
    nodo *sig;

    do
    {
        sig = aux -> siguiente;
        aux -> siguiente = aux -> anterior;
        aux -> anterior = sig;
        aux = aux -> siguiente;
    } while (aux != final);
    inicio = inicio -> siguiente;
    final = final -> siguiente;

    cout << endl << "Lista invertida correctamente" << endl;
}
void Intercambiar(int pos1, int pos2) //unlink los dos nodos y luego link'em en la pos del otro
{
    nodo *aux1, *aux2;
    for (int i = 1; i <= pos1; i++) // antes, comparar cual es menor (pos1 o pos2) para que no se vayan las posiciones a la puta
    {
        aux1 = aux1 -> siguiente;
    }
    aux1 -> anterior -> siguiente = aux1 -> siguiente;
    aux1 -> siguiente -> anterior = aux1 -> anterior;
    for (int i = 1; i <= pos2; i++)
    {
        aux2 = aux2 -> siguiente;
    }
    aux2 -> anterior -> siguiente = aux2 -> siguiente;
    aux2 -> siguiente -> anterior = aux2 -> anterior;
}
int main() // probar tambien: *final siempre es *inicio -> anterior (podria prescindir de uno de ellos?)
{
    float value = 0;
    int eleccion;
    do
    {
        cout << endl << "o o o o o o o o o o MENU o o o o o o o o o o" << endl;
        cout << "[1]  Mostrar la lista" << endl;                                 // Funciona bien
        cout << "[2]  Insertar elemento al principio" << endl;                   // Funciona bien
        cout << "[3]  Insertar elemento al final" << endl;                       // Funciona bien
        cout << "[4]  Insertar elemento en la posicion elegida" << endl;         // Funciona bien
        cout << "[5]  Hallar el valor mayor" << endl;                            // Funciona bien
        cout << "[6]  Mostrar la suma todos los elementos" << endl;              // Funciona bien
        cout << "[7]  Comprobar si la lista esta ordenada" << endl;              // Funciona bien
        cout << "[8]  Eliminar elemento elegido y sus iguales" << endl;          // Funciona bien
        cout << "[9]  Invertir la lista" << endl;                                // Funciona bien
        cout << "[10] Intercambiar 2 elementos elegidos" << endl;                //
        cout << "[0]  SALIR" << endl;                                            // Funciona bien
        cout << "INGRESE SU ELECCION: ";
        cin >> eleccion;

        switch (eleccion)
        {
            case 0: break;
            case 1: Mostrar(); break;
            case 2:
                cout << "Indique el valor del nuevo elemento: ";
                cin >> value;
                InsertarInicio(value);
                break;
            case 3:
                cout << "Indique el valor del nuevo elemento: ";
                cin >> value;
                InsertarFinal(value);
                break;
            case 4:
                int posicion;
                cout << "Indique la posicion en la que desea almacenar el valor: ";
                cin >> posicion;
                cout << "Indique el valor del nuevo elemento: ";
                cin >> value;
                if (posicion == 1) { InsertarInicio(value); }
                else { InsertarElegida(posicion, value); }
                break;
            case 5: HallarMayor(); break;
            case 6: SumarTodo(); break;
            case 7: ComprobarOrdenada(); break;
            case 8:
                cout << "Indique el valor que desea eliminar: ";
                cin >> value;
                Eliminar(value);
                break;
            case 9: Invertir(); break;
            case 10:
                int pos1, pos2;
                cout << "Indique la posicion del primer elemento a cambiar: ";
                cin >> pos1;
                cout << "Indique la posicion del segundo elemento a cambiar: ";
                cin >> pos2;
                Intercambiar(pos1, pos2);
                break;
            default:
                cout << "El dato introducido no es valido, intentelo de nuevo" << endl << endl;
                break;
        }
    } while(eleccion != 0);
    cout << endl << "Acaba de abandonar el programa. Saludos.";
}
