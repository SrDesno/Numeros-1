include <iostream>
#include "numero.h"

using namespace std;

numero::numero()
{
  
}

void numero::setNumero(){
    cout<<"Captura el numero"<<endl;
    cin>>num;
}

int numero::getNumero(){
    return num;
}

int numero::sumaNumeros(int n){

    return num+n;
}

int numero::sumaNumeros(numero n2){
    return num+n2.getNumero();
}
numero::~numero()
{
    //dtor
}