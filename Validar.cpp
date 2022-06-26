#ifndef Validar_CPP_INCLUDED
#define Validar_CPP_INCLUDED
#include<iostream>
using namespace std;

int ValidarDia(int Dia){
    cout<< "Ingrese dia: "<<endl;
    cin>>Dia;
while(Dia<1||Dia>31){
    cout<< "Dia ingresado no valido: "<<endl;
    cout<< "Ingrese un numero de dia valido: "<<endl;
    cin>> Dia;
}
    return Dia;
}

int ValidarMes(int Mes){
    cout<< "Ingrese Mes: "<<endl;
    cin>>Mes;
while(Mes<1||Mes>12){
    cout<< "El mes ingresado no es valido: "<<endl;
    cout<< "Ingrese un numero de mes valido: "<<endl;
    cin>> Mes;
}
    return Mes;
}

int ValidarAnio(int Anio){
    cout<< "Ingrese Anio: "<<endl;
    cin>>Anio;
while(Anio<2021){
    cout<< "El anio ingresado no es valido: "<<endl;
    cout<< "Ingrese un numero de anio valido: "<<endl;
    cin>> Anio;
}
    return Anio;
}


#endif // JORNADA_CPP_INCLUDED
