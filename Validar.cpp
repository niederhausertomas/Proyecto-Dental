#ifndef Validar_CPP_INCLUDED
#define Validar_CPP_INCLUDED
#include<iostream>
using namespace std;
#include "Profesional.h"
#include "Paciente.h"

bool ValidarFechaPasado(Fecha f)
{
    Fecha a;
    a.FechaActual();
    if(f.getAnio()<a.getAnio()||(f.getAnio()>=a.getAnio()&&f.getMes()<a.getMes())||(f.getAnio()==a.getAnio()&&f.getMes()==a.getMes()&&f.getDia()<a.getDia()))
    {
       cout<< "La fecha indicada esta en el pasado! "<<endl;
        return false;
    }
        return true;
}

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

Fecha ValidarFecha(Fecha f){
        int Dia, Mes, Anio;
        Dia=ValidarDia(Dia);
        f.setDia(Dia);
        Mes=ValidarMes(Mes);
        f.setMes(Mes);
        Anio=ValidarAnio(Anio);
        f.setAnio(Anio);
    return f;
}

int ValidarLegajoProfesional(int Leg)
{
    cout<<"Ingrese legajo del profesional: ";
    cin>> Leg;
    int b=0;
    Profesional aux;
    int i;
    int cantProfesionales=cantidadRegistrosProfesionales();
    for(i=0; i<cantProfesionales; i++)
    {
        aux.leerDeDisco(i);
        if(aux.getLegajo()==Leg)
        {
            b++;
            return Leg;
        }
    }
    if (b==0){
    cout<<"No existe el profesional."<<endl;
    return 0;
    }
}

int ValidarHora(int hora){
    cout<< "Ingrese Hora del turno: ";
    cin>>hora;
    while (hora<8||hora>20){
        cout<< "La hora ingresada esta fuera del horario de atencion (8 a 20 hs.)"<<endl;
        cout<< "Ingrese Hora del turno: ";
        cin>>hora;
    }
    return hora;
}

int ValidarMinutos(int minutos){
    cout<< "Ingrese minutos del turno: ";
    cin>>minutos;
    while (minutos!=0&&minutos!=30){
        cout<< "Solo se aceptan horarios en punto o y media."<<endl;
        cout<< "Ingrese minutos del turno: ";
        cin>>minutos;
    }
    return minutos;
}

int ValidarLegajoPaciente(int Leg){

    Paciente aux;
    int i;
    int cantPacientes=cantidadRegistrosPacientes();
    for(i=0; i<cantPacientes; i++)
    {
        aux.leerDeDisco(i);
        if(aux.getLegajo()==Leg)
        {
            return Leg;
        }
    }
    cout<<"No existe el paciente."<<endl;
    return 0;
}

#endif // JORNADA_CPP_INCLUDED
