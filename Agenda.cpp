#ifndef AGENDA_CPP_INCLUDED
#define AGENDA_CPP_INCLUDED
#include<iostream>
using namespace std;
#include "Agenda.h"
#include "Turno.h"
#include "Validar.h"

void TurnosDispDia()
{
    Fecha f;
    do{
        cout<< "El dia ingresado es fin de semana, Ingrese una nueva fecha: "<<endl;
        f=ValidarFecha(f);
    } while (FinDeSemana(f)==true);

    HorariosDisponiblesDelDia(f);
}

bool operator==(Fecha f, Turno t)
{
    if(t.getFechaTurno().getAnio()!=f.getAnio())return false;
    if(t.getFechaTurno().getMes()!=f.getMes())return false;
    if(t.getFechaTurno().getDia()!=f.getDia())return false;
    return true;
}

bool operator==(Turno t, Hora V)
{
    if(t.getHoraTurno().getHoras()==V.getHoras()&&t.getHoraTurno().getMinutos()==V.getMinutos())return false;
    return true;
}

void HorariosDisponiblesDelDia(Fecha f)
{
    Turno t;
    int i,j,b=0;
    Hora V[24];
    Horarios(V);
    cout<<"Turnos disponibles del dia: "<< DiaDeLaSemana(f)<< " " <<f.getDia()<< "/"<<f.getMes()<< "/"<<f.getAnio()<<endl;
    cout<< ".............................................."<<endl;
    int cantTurnos = CantidadRegistrosTurnos();
    for(i=0; i<cantTurnos; i++)
    {
        t.LeerDeDisco(i);
        if (f==t)
        {
            b++;
            for(j=0; j<24; j++)
            {
                if(t==V[j])
                {
                    cout<<"Hora: "<<V[j].getHoras()<< ":" <<V[j].getMinutos()<<endl;
                }
            }
        }
    }
    if (b==0){
        for(j=0; j<24; j++)
            {
                    cout<<"Hora: "<<V[j].getHoras()<< ":" <<V[j].getMinutos()<<endl;
            }
    }
    cout<< endl;
    system("pause");
}

void TurnosPaciente()
{
    int leg;
    cout<< "ingrese el legajo del paciente: "<<endl;
    cin>> leg;
    Paciente p;
    Turno t;
    int i,j;
    int cantPacientes = cantidadRegistrosPacientes();
    for(i=0; i<cantPacientes; i++)
    {
        p.leerDeDisco(i);
        if(p.getLegajo()==leg){
        int cantTurnos = CantidadRegistrosTurnos();
        for(j=0; j<cantTurnos; j++)
        {
            t.LeerDeDisco(j);
            if (t.getLegajoPaciente()==leg)
            {
                cout<<"Fecha: "<< DiaDeLaSemana(t.getFechaTurno())<< " " <<t.getFechaTurno().getDia()<<"/"<< t.getFechaTurno().getMes()<< "/"<< t.getFechaTurno().getAnio()<<"\t"<<"\t"<< "Id del turno: " <<t.getId()<<"\t"<<"Leg del Profesional: "<<t.getLegajoProfesional()<<"\t"<<"\t"<< "Leg del paciente: "<<t.getLegajoPaciente()<<"\t"<< "Horario: "<< t.getHoraTurno().getHoras()<< ":"<< t.getHoraTurno().getMinutos()<<endl;
            }
        }
        }
    }
    system("pause");
}

void TurnosMes(){
    int mes, anio;
    cout<< "ingrese el anio a consultar: "<<endl;
    cin>> anio;
    cout<< "Ingrese mes a consultar: "<<endl;
    cin>> mes;
    Turno t;
    int i;
    int cantTurnos = CantidadRegistrosTurnos();
    for(i=0; i<cantTurnos; i++)
    {
        t.LeerDeDisco(i);
        if (t.getFechaTurno().getAnio()==anio&&t.getFechaTurno().getMes()==mes){
        cout<<"Fecha: "<< DiaDeLaSemana(t.getFechaTurno())<< " " <<t.getFechaTurno().getDia()<<"/"<< t.getFechaTurno().getMes()<< "/"<< t.getFechaTurno().getAnio()<<"\t"<<"\t"<< "Id del turno: " <<t.getId()<<"\t"<<"Leg del Profesional: "<<t.getLegajoProfesional()<<"\t"<<"\t"<< "Leg del paciente: "<<t.getLegajoPaciente()<<"\t"<< "Horario: "<< t.getHoraTurno().getHoras()<< ":" << t.getHoraTurno().getMinutos()<<endl;
    }
    }
    system("pause");
}

void TurnosDelDia(Fecha f){
    Turno t;
    int i=0;
    int cantTurnos = CantidadRegistrosTurnos();
    cout<< "..............Fecha "<< DiaDeLaSemana(f)<< " " << f.getDia()<< "/"<< f.getMes() << "/"<< f.getAnio()<< "..............."<<endl<<endl;
    for(i=0; i<cantTurnos; i++)
    {
        t.LeerDeDisco(i);
        if (t.getFechaTurno().getAnio()==f.getAnio()&&t.getFechaTurno().getMes()==f.getMes()&&t.getFechaTurno().getDia()==f.getDia()){
            cout<< "Id turno: " <<t.getId()<< "\t"<<"Legajo Profesional: "<<t.getLegajoProfesional()<< "\t"<< "\t"<< "Leg del paciente: "<<t.getLegajoPaciente()<< "\t"<< "Horario: "<< t.getHoraTurno().getHoras()<< ":" << t.getHoraTurno().getMinutos() <<endl;
        }
    }
    system("pause");
}

void TurnosProx7Dias(){
    Fecha f;
    f.FechaActual();
    int j;
    for(j=0;j<7;j++){
    f.setDia(f.getDia()+1);
    cout<<endl;
    TurnosDelDia(f);
    cout<<endl;
    }
    system("pause");
}

void TurnosDispDiaProf(Fecha f, int LegProf)
{
    Turno t;
    int i,j,s,b=0;
    Hora V[24];
    Horarios(V);
    cout<<"Turnos disponibles del dia: "<< DiaDeLaSemana(f)<< " " <<f.getDia()<< "/"<<f.getMes()<< "/"<<f.getAnio()<<endl;
    cout<< "Del profesional " << LegProf << ": "<<endl;
    cout<< ".............................................."<<endl;
    int cantTurnos = CantidadRegistrosTurnos();
    for(i=0; i<cantTurnos; i++)
    {
        t.LeerDeDisco(i);
        if (f==t)
        {
            for(j=0; j<24; j++)
            {
                if(t==V[j])
                {
                    if (t.getLegajoProfesional()==LegProf)
                    {
                        b++;
                        cout<<"Hora: "<<V[j].getHoras()<< ":" <<V[j].getMinutos()<<endl;
                    }
                }
            }
        }
    }
    if (b==0)
    {
        for(j=0; j<24; j++)
        {
            cout<<"Hora: "<<V[j].getHoras()<< ":" <<V[j].getMinutos()<<endl;
        }
    }
    cout<< endl;
    system("pause");
}

void DiaProf()
{
    int LegProf;
    Fecha f;
    int anio, mes, dia;
    cout<< "Ingrese legajo profesional: "<<endl;
    cin>> LegProf;
    cout<< "ingrese anio a consultar: "<<endl;
    cin>> anio;
    f.setAnio(anio);
    cout<< "Ingrese mes a consultar: "<<endl;
    cin>> mes;
    f.setMes(mes);
    cout<< "Ingrese dia a consultar: "<<endl;
    cin>> dia;
    f.setDia(dia);
    while (FinDeSemana(f)==true)
    {
        cout<< "El dia seleccionado es fin de semana, ingrese otra fecha."<<endl;
        cout<< "ingrese anio a consultar: "<<endl;
        cin>> anio;
        f.setAnio(anio);
        cout<< "Ingrese mes a consultar: "<<endl;
        cin>> mes;
        f.setMes(mes);
        cout<< "Ingrese dia a consultar: "<<endl;
        cin>> dia;
        f.setDia(dia);
    }
    TurnosDispDiaProf(f,LegProf);
}

void TurnosDispProx7Prof(){
    Fecha f;
    f.FechaActual();
    int LegProf, i;
    cout<< "Ingrese legajo del profesional: "<<endl;
    cin>> LegProf;
    f.setDia(f.getDia()-1);
    for (i=0;i<7;i++){
        f.setDia(f.getDia()+1);
        while(FinDeSemana(f)==true){
            f.setDia(f.getDia()+1);
        }
        TurnosDispDiaProf(f,LegProf);
    }
}

void TurnosDispPorProf(){
    int opcion;
    int i=0;
    while(i==0)
    {
        system("cls");
        cout<< "....... Turnos por profesional ......."<<endl;
        cout<< "1. Mostrar Turnos disponibles por dia: "<<endl;
        cout<< "2. Mostrar Turnos disponibles de los proximos 7 dias: "<<endl;
        cout<< "0. Volver a menu principal: "<<endl;
        cout<< ".................................."<<endl<<endl;
        cout<< "Ingrese opcion: ";
        cin>>opcion;
        switch(opcion)
        {
        case 1:
            system("cls");
            cout<< "1. Mostrar Turnos disponibles del dia: "<<endl;
            cout<< "........................................."<<endl;
            DiaProf();
            break;
        case 2:
            system("cls");
            cout<< "2. Mostrar Turnos disponibles de los proximos 7 dias: "<<endl;
            cout<< "..................................................."<<endl<<endl;
            TurnosDispProx7Prof();
            break;
        case 0:
            i=1;
            break;
        }
    }
}

void TurnosDispProx7Dias(){
    Fecha f;
    f.FechaActual();
    int i;
    f.setDia(f.getDia()-1);
    for (i=0;i<7;i++){
        f.setDia(f.getDia()+1);
        while(FinDeSemana(f)==true){
            f.setDia(f.getDia()+1);
        }
        HorariosDisponiblesDelDia(f);
    }
}

void MenuAgenda()
{
    int opcion;
    int i=0;
    while(i==0)
    {
        system("cls");
        cout<< "....... Menu Agenda ......."<<endl;
        cout<< "1. Turnos del dia: "<<endl;
        cout<< "2. Turnos de los proximos 7 dias: "<<endl;
        cout<< "3. Turnos por mes: "<<endl;
        cout<< "4. Turnos por paciente: "<<endl;
        cout<< "5. Turnos disponibles por dia: "<<endl;
        cout<< "6. Turnos disponibles de los proximos 7 dias: "<<endl;
        cout<< "7. Turnos disponibles por profesional: "<<endl;
        cout<< "0. Volver a menu principal: "<<endl;
        cout<< ".................................."<<endl<<endl;
        cout<< "Ingrese opcion: ";
        cin>>opcion;
        switch(opcion)
        {
        case 1:{
            system("cls");
            cout<< "1. Turnos del dia: "<<endl<<endl;
            Fecha f;
            f.FechaActual();
            if (FinDeSemana(f)==true){
                cout<<"Hoy es fin de semana. y no hay turnos."<<endl;
                system("pause");
                break;
            }
            TurnosDelDia(f);}
            break;
        case 2:
            system("cls");
            cout<< "2. Turnos de los proximos 7 dias: "<<endl;
            cout<< ".................................."<<endl<<endl;
            TurnosProx7Dias();
            break;
        case 3:
            system("cls");
            cout<< "3. Turnos por mes: "<<endl;
            cout<< ".................................."<<endl<<endl;
            TurnosMes();
            break;
        case 4:
            system("cls");
            cout<< "4. Turnos por paciente: "<<endl;
            cout<< ".................................."<<endl<<endl;
            TurnosPaciente();
            break;
        case 5:
            system("cls");
            cout<< "5. Turnos disponibles por dia: "<<endl;
            cout<< ".................................."<<endl<<endl;
            TurnosDispDia();
            break;
        case 6:
            system("cls");
            cout<< "6. Turnos disponibles de los proximos 7 dias: "<<endl;
            cout<< ".................................."<<endl<<endl;
            TurnosDispProx7Dias();
            break;
        case 7:
            cout<< "7. Turnos disponibles por profesional: "<<endl;
            cout<< ".................................."<<endl<<endl;
            TurnosDispPorProf();
            break;
        case 0:
            i=1;
            break;
        }
    }
}

#endif // AGENDA_CPP_INCLUDED
