#ifndef Validar_CPP_INCLUDED
#define Validar_CPP_INCLUDED
#include<iostream>
using namespace std;
#include "Validar.h"
#include "Profesional.h"
#include "Paciente.h"
#include "Jornada.h"
#include "rlutil.h"

void ValidarEstado(bool estado){
    if(estado==true)
    {
        cout<<" Activo";
    }
    else if(estado==false)
    {
        cout<<"inactivo";
    }
    cout<<endl;

}

int ValidarDniExistente(int DNI){
    Paciente aux;
    int i;
    int cantPacientes=cantidadRegistrosPacientes();
    for(i=0; i<cantPacientes; i++)
    {
        aux.leerDeDisco(i);
        if(DNI==aux.getDni())
        {
            rlutil::setColor(rlutil::RED);
            cout<< "El DNI ingresado ya existe! "<<endl;
            DNI=0;
            rlutil::setColor(rlutil::WHITE);
            return DNI;
        }
    }
    return DNI;
}

int ValidarDni(int DNI){
    int c=14;
    cout<< "Ingrese DNI: "<<endl;
    rlutil::locate(43,14);
    cin>>DNI;
    rlutil::locate(60,14);
    DNI=ValidarDniExistente(DNI);
    while(DNI>60000000||DNI<=0||cin.fail()==true){
        rlutil::locate(90,c);
        cout<< "El dato ingresado no es valido"<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
        c++;
        rlutil::locate(30,c);
        cout<< "Ingrese DNI: "<<endl;
        rlutil::locate(43,c);
        cin>>DNI;
        rlutil::locate(60,c);
        DNI=ValidarDniExistente(DNI);
    }
    return DNI;
}

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
    int c=11;
    rlutil::locate(30,c);
    c++;
    cout<< "Ingrese dia: "<<endl;
    rlutil::locate(30,c);
    c++;
    cin>>Dia;
while(Dia<1||Dia>31){
    rlutil::locate(30,c);
    c++;
    rlutil::setColor(rlutil::RED);
    cout<< "Dia ingresado no valido: "<<endl;
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(30,c);
    c++;
    cout<< "Ingrese un numero de dia valido: "<<endl;
    rlutil::locate(30,c);
    c++;
    cin>> Dia;
}
    return Dia;
}

int ValidarMes(int Mes){
    int c=11;
    rlutil::locate(30,c);
    c++;
    cout<< "Ingrese Mes: "<<endl;
    rlutil::locate(30,c);
    c++;
    cin>>Mes;
while(Mes<1||Mes>12){
    rlutil::locate(30,c);
    c++;
    rlutil::setColor(rlutil::RED);
    cout<< "El mes ingresado no es valido: "<<endl;
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(30,c);
    c++;
    cout<< "Ingrese un numero de mes valido: "<<endl;
    rlutil::locate(30,c);
    c++;
    cin>> Mes;
}
    return Mes;
}

int ValidarAnio(int Anio){
    int c=11;
    rlutil::locate(30,c);
    c++;
    cout<< "Ingrese Anio: "<<endl;
    rlutil::locate(30,c);
    c++;
    cin>>Anio;
while(Anio<1900||Anio>2100){
    rlutil::locate(30,c);
    c++;
    rlutil::setColor(rlutil::RED);
    cout<< "El anio ingresado no es valido: "<<endl;
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(30,c);
    c++;
    cout<< "Ingrese un numero de anio valido: "<<endl;
    rlutil::locate(30,c);
    c++;
    cin>> Anio;
}
    return Anio;
}

Fecha ValidarFecha(Fecha f){
        int Dia, Mes, Anio;
        Dia=ValidarDia(Dia);
        f.setDia(Dia);
        rlutil::cls();
        rlutil::locate(30,10);
        cout<< "Fecha de Nacimiento: "<<endl;
        Mes=ValidarMes(Mes);
        f.setMes(Mes);
        rlutil::cls();
        rlutil::locate(30,10);
        cout<< "Fecha de Nacimiento: "<<endl;
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

Hora ValidarHorario(){
Hora h;
h.setHoras(ValidarHora());
h.setMinutos(ValidarMinutos());
return h;
}

Hora ValidarHorarioConLegJornada(Hora HoraTurno, int LegajoProfesional,Fecha FechaTurno )
{
    string D=DiaDeLaSemana(FechaTurno);
    Jornada j;
    int i, b=0, ValorDevuelto;
    int cantJornadas=CantidadRegistrosJornada();
    for(i=0; i<cantJornadas; i++)
    {
        j.LeerDeDisco(i);
        ValorDevuelto=strcmp(j.getDia().c_str(),D.c_str());
        if(ValorDevuelto==0&&j.getLegajoDelProfesional()==LegajoProfesional&&j.getEntrada().getHoras()<=HoraTurno.getHoras()&&j.getSalida().getHoras()>HoraTurno.getHoras())
        {
            b++;
            return HoraTurno;
        }
    }
    if (b==0)
    {
        cout<< "El profesional no trabaja en el horario ingresado: "<<endl;
        system("pause");
        HoraTurno.setHoras(0);
        return HoraTurno;
    }
}

int ValidarHora(){
    int hora;
    cout<< "Ingrese Hora: ";
    cin>>hora;
    while (hora<8||hora>20){
        cout<< "La hora ingresada esta fuera del horario de atencion (8 a 20 hs.)"<<endl;
        cout<< "Ingrese Hora: ";
        cin>>hora;
    }
    return hora;
}

int ValidarMinutos(){
    int minutos;
    cout<< "Ingrese minutos: ";
    cin>>minutos;
    while (minutos!=0&&minutos!=30){
        cout<< "Solo se aceptan horarios en punto o y media."<<endl;
        cout<< "Ingrese minutos: ";
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
