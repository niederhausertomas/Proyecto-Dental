#ifndef HORA_CPP_INCLUDED
#define HORA_CPP_INCLUDED
#include<iostream>
using namespace std;
#include "Hora.h"



void Hora::setHoras(int horas)
{
    _horas=horas;
}
void Hora::setMinutos(int minutos)
{
    _minutos=minutos;
}
int Hora::getHoras()
{
    return _horas;
}
int Hora::getMinutos()
{
    return _minutos;
}

void Horarios(Hora V[24])
{
    int i=0,j=8;
    for(i=0; i<24; i+=2)
    {
        V[i].setHoras(j);
        V[i].setMinutos(0);
        V[i+1].setHoras(j);
        V[i+1].setMinutos(30);
        j++;
    }
    return;
}


#endif // HORA_CPP_INCLUDED
