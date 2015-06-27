#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Nodo.h"
using namespace std;


template <typename Tipo>
class Lista
{
public:
    Nodo<Tipo>* inicio;

    Lista()
    {
        inicio = NULL;
    }

    void imprimir()
    {
        for(Nodo<Tipo>* temp = inicio;
            temp!=NULL;
            temp = temp->sig)
        {
            cout<<temp->num<<endl;
        }
    }

    void agregarAlInicio(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            nuevo->sig = inicio;
            inicio = nuevo;
        }
    }

    void agregarAlFinal(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            Nodo<Tipo>*temp = inicio;
            while(temp->sig!=NULL)
            {
                temp=temp->sig;
            }
            temp->sig = nuevo;
        }
    }

    void borrar(Tipo valor_a_borrar)
    {
        if(inicio->num == valor_a_borrar)
        {
            Nodo<Tipo>* borrar = inicio;
            inicio = inicio->sig;
            delete borrar;
        }else
        {
            Nodo<Tipo>* temp = inicio;
            while(temp->sig->num!=valor_a_borrar)
            {
                temp=temp->sig;
                if(temp->sig==NULL)
                    return;
            }
            Nodo<Tipo>* borrar = temp->sig;
            temp->sig = temp->sig->sig;
            delete temp->sig;
        }
    }

    //Devuelve true si la lista esta vacia, de lo contrario devuelve false
    bool estaVacia()
    {
        if (inicio==NULL)
            return true;
        else
            return false;
    } //mediante el if verificamos si el inicio esta nulo, si lo esta es que la lista esta vacia & retornamor true de lo contrario se retorna false

    //Devuelve el valor almacenado en el primer nodo de la lista
    Tipo obtenerPrimerValor()
    {
        return inicio->valor;
    } // retornamos el valor inicial de la lista

    //Devuelve el valor almacenado en el ultimo nodo de la lista
    Tipo obtenerUltimoValor()
    {
        Tipo n;
        for(Nodo<Tipo>* iterator=inicio;
        iterator!=NULL;
        iterator=iterator->sig)
        {
            n=iterator->valor;
        }
        return n;
    } //recorremos toda la lista & almacenamos el valor enla variable n que es tipo 'Tipo', al final retornamos n

    //Devuelve el valor mayor almacenado en la lista
    Tipo obtenerMayor()
    {
        Tipo n=NULL;
        for(Nodo<Tipo>* iterator=inicio;
        iterator!=NULL;
        iterator=iterator->sig)
        {
            if(iterator->valor>n)
            n=iterator->valor;
        }
        return n;
    } //recorremos toda la lista con un for & mediante el if comparamos si el valor que tenemos es mayor que el que ya teniamos almacenado en n, variable que inicializamos vaica como NULL, una vez finalizado el ciclo devolvemos el valor que esta en n que seria el mayor
};
#endif // LISTA_H
