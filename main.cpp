#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct tm fecha;

struct nodo{
    string nombre;
    int numExp;
    int dia = fecha.tm_mday;
    int mes = fecha.tm_mon;
    int ano = fecha.tm_year;
    nodo *sgt;
};
nodo *peek = NULL;
void push(int numExp, string nombre, int dia, int mes, int ano){
   nodo *nvox =  new nodo;
   nvox->numExp=numExp,nvox->sgt=peek;
   nvox ->nombre = string(nombre);
   nvox ->dia = dia;
   nvox ->mes = mes;
   nvox ->ano = ano;
   peek=nvox;
}
void pop(){
    if(peek==NULL)
        cout<<"Nada que imprimir, Stack vacia \n";
    else
    peek=peek->sgt;
}
void prt(){
     nodo *aux = peek;
     if(aux==NULL)
         cout<<"Nada que imprimir, Stack vacia\n";
     else
         while(aux!=NULL){
             cout<<aux->numExp<<" -> ";
             cout<<aux->nombre<<"->";
             cout<<aux->dia<<"/";
             cout<<aux->mes<<"/";
             cout<<aux->ano<<"/";
             aux=aux->sgt;
         }
}
int main(){
    int op, numExp, dia, mes, ano;
    string nombre = "";
    do{
        cout<<"\n(1) Push    (2) Pop    (3) Print   (4) Salir \n ";
        cout<<"\n Elija ppcion  ?: ",cin>>op;
        switch (op){
            case 1:
                cout<<"Introduzca el numero de expediente : ??  ",cin>>numExp;
                cout<<"Introduzca el nombre : ??  ",cin>>nombre;
                cout<<"Introduzca el dia, (fecha nacimiento) : ??  ",cin>>dia;
                cout<<"Introduzca el mes, (fecha nacimiento) : ??  ",cin>>mes;
                cout<<"Introduzca el ano, (fecha nacimiento) : ??  ",cin>>ano;
                push(numExp, nombre, dia, mes, ano);
                break;
            case 2:
                cout<<"Eliminando ..... : ";
                pop();
                break;
            case 3:
                cout<<"Imprimiendo..... : ";
                prt();
                break;
            case 4:
                cout<<"------Bye--------";
        }
    }while(op!=4);
}

