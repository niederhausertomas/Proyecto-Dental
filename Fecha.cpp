#ifndef FECHA_CPP_INCLUDED
#define FECHA_CPP_INCLUDED
#include<iostream>
using namespace std;
#include "Fecha.h"
#include <ctime>
#include "string.h"
#include <string>

void Fecha::setDia(int dia)
{
    _dia=dia;
}
void Fecha:: setMes(int mes)
{
    _mes=mes;
}
void Fecha::setAnio(int anio)
{
    _anio=anio;
}
int Fecha::getDia()
{
    return _dia;
}
int Fecha::getMes()
{
    return _mes;
}
int Fecha::getAnio()
{
    return _anio;
}

void Fecha::cargrarFehca()
{
    int dia, mes, anio;
    cout<< "Ingrese dia: "<<endl;
    cin>> dia;
    setDia(dia);
    cout<< "Ingrese mes: "<<endl;
    cin>> mes;
    setMes(mes);
    cout<< "Ingrese anio: "<<endl;
    cin>> anio;
    setAnio(anio);
}

Fecha::Fecha(int dia, int mes, int anio)
{
    _dia=dia;
    _mes=mes;
    _anio=anio;
}

Fecha::Fecha()
{
    _dia=0;
    _mes=0;
    _anio=0;
}

void Fecha::FechaActual()
{
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    _dia= timeinfo->tm_mday;
    _mes= timeinfo->tm_mon + 1;
    _anio= timeinfo->tm_year + 1900;
    return;
}

string DiaDeLaSemana(Fecha f)
{
    char v[7][10]= {"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
    //Congruencia de Zeller
    int a = (14-f.getMes())/12;
    int y = f.getAnio()-a;
    int m = f.getMes()+12*a-2;
    int d = (f.getDia()+y+y/4-y/100+y/400+(31*m)/12)%7;
    string V1=v[d];
    return V1;
}

bool FinDeSemana(Fecha f)
{
    char v1[10]="Domingo";
    char v2[10]="Sabado";
    char v3[10];
    string v4=DiaDeLaSemana(f);
    int ValorDevuelto;
    strcpy(v3, v4.c_str());
    ValorDevuelto=strcmp(v3,v1);
    if (ValorDevuelto==0)
    {
        cout<< "El dia ingresado es fin de semana, ingrese una fecha valida. "<<endl;
        return true;
    }
    ValorDevuelto=strcmp(v3,v2);
    if (ValorDevuelto==0)
    {
        cout<< "El dia ingresado es fin de semana, ingrese una fecha valida. "<<endl;
        return true;
    }
    return false;
}

#endif // FECHA_CPP_INCLUDED
