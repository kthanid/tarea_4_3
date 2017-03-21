#include "NodoArbolBinario.h"
#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <list>          // std::list
using namespace std;

//Devuelve la suma de todos los numeros del arbol con la raiz dada.
int suma(NodoArbolBinario* raiz)
{
    if(raiz==NULL)
    return 0;
    int s = raiz->num;
    s += suma(raiz->hijo_der) + suma(raiz->hijo_izq);
    return s;
}

//Devuelve la cantidad de nodos que tiene el arbol con la raiz dada.
int cantidadNodos(NodoArbolBinario* raiz)
{
    int c =0;
    if(raiz==NULL)
    return 0;
    c++;
    c+= cantidadNodos(raiz->hijo_der)+cantidadNodos(raiz->hijo_izq);
    return c;
}

//Devuelve el promedio de los numeros que tiene el arbol con la raiz dada.
int promedio(NodoArbolBinario* raiz)
{
    return suma(raiz)/cantidadNodos(raiz);
}

//Devuelve la cantidad de pasos que tiene que dar el algoritmo para llegar a un numero dado.
//Ejemplo: http://www.comp.nus.edu.sg/~stevenha/visualization/bst.html
//Para llegar al nodo 7 se ocupan 3 pasos (15,6,7)
//Para llegar al nodo 5 se ocupan 4 pasos (15,6,4,5)
//Para llegar al nodo 15 se ocupa 1 paso (15)
int cuantosPasos(NodoArbolBinario* raiz,int num)
{
    int c =1;
    if(raiz==NULL)
    return c;
    if(raiz->num == num)
        return c;
    if(num>raiz->num)
        c += cuantosPasos(raiz->hijo_der,num);
    if(num<raiz->num)
        c += cuantosPasos(raiz->hijo_izq,num);
    return c;
}

//Devuelve la cantidad de hojas que tiene el arbol con la raiz dada
int sumaHojas(NodoArbolBinario* raiz)
{
   if (raiz==NULL)
    {return 0;}
    if ((raiz->hijo_der ==NULL)&&(raiz->hijo_izq ==NULL))
    return 1;
    else
    return sumaHojas(raiz->hijo_izq) + sumaHojas(raiz->hijo_der);
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 1;
}
