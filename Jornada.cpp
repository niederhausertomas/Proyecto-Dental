#ifndef Jornada_CPP_INCLUDED
#define Jornada_CPP_INCLUDED
#include<iostream>
using namespace std;
#include "Jornada.h"
#include <string>
#include <cstring>
#include "Profesional.h"
#include "Validar.h"

void Jornada::setId(int Id){
    _Id=Id;
}

void Jornada::setDia(string Dia)
{
    strcpy(_Dia, Dia.c_str());
}

void Jornada::setLegajoDelProfesional(int LegajoDelProfesional){
    _LegajoDelProfesional=LegajoDelProfesional;
}

void Jornada::setEntrada(Hora Entrada){
    _Entrada=Entrada;
}

void Jornada::setSalida (Hora Salida){
    _Salida=Salida;
}

int Jornada::getId(){
    return _Id;
}

string Jornada::getDia(){
    string Dia;
    Dia = _Dia;
    return Dia;
}

int Jornada::getLegajoDelProfesional(){
    return _LegajoDelProfesional;
}

Hora Jornada::getEntrada(){
    return _Entrada;
}

Hora Jornada::getSalida(){
    return _Salida;
}

void Jornada::CargarJornada()
{
    system("cls");
    int hora, minutos;
    int LegajoDelProfesional=0;
    Profesional aux;
    int i,j=0;
    int Id=1;
    Jornada jo;
    int t;
    int cantJornada=CantidadRegistrosJornada();
    for(t=0; t<cantJornada; t++)
    {
        jo.LeerDeDisco(t);
        if(Id<=jo.getId())
        {
            Id=jo.getId()+1;
        }
    }
    cout<< "Id de la Jornada: " <<Id <<endl;
    setId(Id);
    while (LegajoDelProfesional==0){
        LegajoDelProfesional=ValidarLegajoProfesional(LegajoDelProfesional);
    }
    setLegajoDelProfesional(LegajoDelProfesional);
    int opcion=0;
    string Dia;
    while(opcion<1||opcion>5)
    {
        cout<< "seleccione el dia de la semana: "<<endl;
        cout<< "1. Lunes " <<endl;
        cout<< "2. Martes " <<endl;
        cout<< "3. Miercoles " <<endl;
        cout<< "4. Jueves " <<endl;
        cout<< "5. Viernes "<< endl;
        cin>> opcion;
    }
    switch(opcion)
    {
    case 1:
        Dia= "Lunes";
        setDia(Dia);
        break;
    case 2:
        Dia= "Martes";
        setDia(Dia);
        break;
    case 3:
        Dia= "Miercoles";
        setDia(Dia);
        break;
    case 4:
        Dia= "Jueves";
        setDia(Dia);
        break;
    case 5:
        Dia= "Viernes";
        setDia(Dia);
        break;
    }
    cout<< "Indique Hora de entrada: "<<endl;
    cin>> hora;
    cout<< "Indique Minutos de entrada: "<<endl;
    cin>> minutos;
    Hora e;
    e.setHoras(hora);
    e.setMinutos(minutos);
    setEntrada(e);
    cout<< "Indique Hora de salida: "<<endl;
    cin>> hora;
    cout<< "Indique Minutos de salida: "<<endl;
    cin>> minutos;
    e.setHoras(hora);
    e.setMinutos(minutos);
    setSalida(e);
}

bool Jornada::GuardarEnDisco()
{
    FILE *p = fopen("Jornada.dat", "ab");
    if (p==NULL)
    {
        return false;
    }
    bool guardo = fwrite (this, sizeof(Jornada), 1,p);
    fclose(p);
    return guardo;
}

bool Jornada::GuardarEnDisco(int nroRegistro)
{
    FILE *p = fopen("Jornada.dat", "rb+");
    if (p==NULL)
    {
        return false;
    }
    fseek(p,nroRegistro*sizeof(Jornada),SEEK_SET);
    bool guardo = fwrite (this, sizeof(Jornada), 1,p);
    fclose(p);
    return guardo;
}

void Jornada::MostrarJornada(){
    Profesional aux;
    int i;
    int cantProfesionales=cantidadRegistrosProfesionales();
    for(i=0; i<cantProfesionales; i++)
    {
        aux.leerDeDisco(i);
        if(getLegajoDelProfesional()==aux.getLegajo())
        {
cout<<"ID jornada: "<<getId()<<" - Legajo: "<<getLegajoDelProfesional()<< " " <<aux.getApellido() <<" - Dias: "<<getDia()<<" Horario de entrada: "<<getEntrada().getHoras()<<":"<<getEntrada().getMinutos()<<" Salida: "<<getSalida().getHoras()<<":"<<getSalida().getMinutos()<<endl;
        }
    }

}

int CantidadRegistrosJornada()
{
    FILE *p= fopen("Jornada.dat","rb");
    if(p==NULL)
    {
        return 0;
    }
    long bytes;
    int cantReg;
    fseek(p,0,SEEK_END);
    bytes=ftell(p);
    cantReg=bytes/sizeof(Jornada);
    return cantReg;
}


void EditarJornada()
{
    int Id;
    cout<<"Ingrese Id de la jornada: ";
    cin>> Id;
    Jornada j;
    int i;
    int cantJornadas=CantidadRegistrosJornada();
    for(i=0; i<cantJornadas; i++)
    {
        j.LeerDeDisco(i);
        if(j.getId()==Id)
        {
            int opcion;
            int _Id;
            string Dia;
            int LegajoDelProfesional;
            int hora, minutos;
            j.MostrarJornada();
            cout<< endl;
            cout<< "Ingrese la opcion que desea modificar: "<<endl;
            cout<< "1. Id: "<<endl;
            cout<< "2. Legajo del Profesional: "<<endl;
            cout<< "3. Dia: "<<endl;
            cout<< "4. Horario de entrada: "<<endl;
            cout<< "5. Horario de salida: "<<endl;
            cin>>opcion;
            switch(opcion)
            {
            case 1:
                cout<< "Ingrese el nuevo Id: "<<endl;
                cin>> Id;
                j.setId(Id);
                j.GuardarEnDisco(i);
                break;
            case 2:
            {
                int t=0,i;
                Jornada aux;
                while (t==0)
                {
                    cout<< "Ingrese el nuevo Legajo del Profesional: "<<endl;
                    cin>>LegajoDelProfesional;
                    int cantProfesionales=cantidadRegistrosProfesionales();
                    for(i=0; i<cantProfesionales; i++)
                    {
                        aux.LeerDeDisco(i);
                        if(aux.getLegajoDelProfesional()==LegajoDelProfesional)
                        {
                            t++;
                        }
                    }
                    if (t==0)
                    {
                        cout<< "El Legajo del Profesional no existe. "<<endl;
                    }
                }
                j.setLegajoDelProfesional(LegajoDelProfesional);
                j.GuardarEnDisco(i);
            }
            break;
            case 3:
            {
                int opcion=0;
                while(opcion<1||opcion>5)
                {
                    cout<< "seleccione el dia de la semana: "<<endl;
                    cout<< "1. Lunes " <<endl;
                    cout<< "2. Martes " <<endl;
                    cout<< "3. Miercoles " <<endl;
                    cout<< "4. Jueves " <<endl;
                    cout<< "5. Viernes "<< endl;
                    cin>> opcion;
                }
                switch(opcion)
                {
                case 1:
                    Dia= "Lunes";
                    j.setDia(Dia);
                    j.GuardarEnDisco(i);
                    break;
                case 2:
                    Dia= "Martes";
                    j.setDia(Dia);
                    j.GuardarEnDisco(i);
                    break;
                case 3:
                    Dia= "Miercoles";
                    j.setDia(Dia);
                    j.GuardarEnDisco(i);
                    break;
                case 4:
                    Dia= "Jueves";
                    j.setDia(Dia);
                    j.GuardarEnDisco(i);
                    break;
                case 5:
                    Dia= "Viernes";
                    j.setDia(Dia);
                    j.GuardarEnDisco(i);
                    break;
                }
            }
            break;
            case 4:
                cout<< "Hora de entrada: "<<endl;
                cin>> hora;
                cout<< "Minutos de entrada: "<<endl;
                cin>> minutos;
                Hora e;
                e.setHoras(hora);
                e.setMinutos(minutos);
                j.setEntrada(e);
                j.GuardarEnDisco(i);
                break;
            case 5:
                cout<< "Indique Hora de salida: "<<endl;
                cin>> hora;
                cout<< "Indique Minutos de salida: "<<endl;
                cin>> minutos;
                e.setHoras(hora);
                e.setMinutos(minutos);
                j.setSalida(e);
                j.GuardarEnDisco(i);
                break;
            case 0:
                return;
                break;
            }
            cout<<endl;
            j.MostrarJornada();
            system("pause");
            return;
        }
    }
    return;
}

bool Jornada::LeerDeDisco(int nroRegistro)
{
    FILE *p = fopen("Jornada.dat", "rb");
    if (p==NULL)
    {
        return false;
    }
    fseek(p,nroRegistro*sizeof(Jornada),SEEK_SET);
    bool ok=fread(this, sizeof(Jornada),1,p);
    fclose(p);
    return ok;
}

int BuscarJornadaPorLegajoProfesional()
{
    int Leg;
    cout<<"Ingrese legajo del profesional: ";
    cin>> Leg;
    Jornada j;
    int i;
    int cantJornadas=CantidadRegistrosJornada();
    for(i=0; i<cantJornadas; i++)
    {
        j.LeerDeDisco(i);
        if(j.getLegajoDelProfesional()==Leg)
        {
            return Leg;
        }
    }
    cout<<"No hay jornadas para el profesional."<<endl;
}

void MostrarJornadaProf()
{
    int Leg;
    cout<<"Ingrese legajo del profesional: ";
    cin>> Leg;
    Jornada j;
    int i,b=0;
    int cantJornadas=CantidadRegistrosJornada();
    for(i=0; i<cantJornadas; i++)
    {
        j.LeerDeDisco(i);
        if(j.getLegajoDelProfesional()==Leg)
        {
            j.MostrarJornada();
            cout<<endl;
            b++;
        }

    }
    if(b==0){
    cout<<"No hay jornadas para el profesional."<<endl;}
system("pause");
}

void MostrarTodasLasJornadaProf(){

    Jornada j;
    int i,b=0;
    int cantJornadas=CantidadRegistrosJornada();
    for(i=0; i<cantJornadas; i++)
    {
        j.LeerDeDisco(i);
            j.MostrarJornada();
            cout<<endl;
            b++;
    }
    if(b==0){
    cout<<"No hay jornadas para el profesional."<<endl;}
system("pause");
}

bool ProfDisponibleDia(Fecha FechaTurno)
{
    int b=0;
    string D=DiaDeLaSemana(FechaTurno);
    Jornada j;
    int i;
    int ValorDevuelto;
    int cantJornadas=CantidadRegistrosJornada();
    cout<<endl;
    cout<< "Profesionales que trabajan el dia "<<D<< ": " <<endl;
    for(i=0; i<cantJornadas; i++)
    {
        j.LeerDeDisco(i);
        ValorDevuelto=strcmp(j.getDia().c_str(),D.c_str());
        if(ValorDevuelto==0)
        {
            j.MostrarJornada();
            b++;
            cout<<endl;
        }
    }
    if (b==0)
    {
        cout<< "No hay profesionales que trabajen ese dia: "<<endl;
        system("pause");
        return false;
    }
    else
    {
        return true;
    }
}

int ProfParaTurno(Fecha FechaTurno, int Leg){
    string D=DiaDeLaSemana(FechaTurno);
    Jornada j;
    int i, b=0, ValorDevuelto;
    int cantJornadas=CantidadRegistrosJornada();
    for(i=0; i<cantJornadas; i++)
    {
        j.LeerDeDisco(i);
        ValorDevuelto=strcmp(j.getDia().c_str(),D.c_str());
        if(ValorDevuelto==0&&j.getLegajoDelProfesional()==Leg)
        {
            b++;
            return Leg;
        }
    }
    if (b==0)
    {
        cout<< "El profesional ingresado no trabaja el dia elegido: "<<endl;
        system("pause");
        return 0;
    }
}
#endif // JORNADA_CPP_INCLUDED
