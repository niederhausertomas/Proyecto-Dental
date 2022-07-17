#ifndef AGENDA_CPP_INCLUDED
#define AGENDA_CPP_INCLUDED
#include<iostream>
using namespace std;
#include "rlutil.h"
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

bool operator==(Turno t, Hora h)
{
    if(t.getHoraTurno().getHoras()==h.getHoras()&&t.getHoraTurno().getMinutos()==h.getMinutos())return true;
    return false;
}


void HorariosDisponiblesDelDia(Fecha f)
{
    Jornada j;
    string D=DiaDeLaSemana(f);
    int ValorDevuelto,i,w,z,q,k=30,y=0;
    Hora Tur;
    Turno aux;
    Tur.setHoras(8);
    Tur.setMinutos(0);
    cout<<"Turnos disponibles del dia: "<< DiaDeLaSemana(f)<< " " <<f.getDia()<< "/"<<f.getMes()<< "/"<<f.getAnio()<<endl;
    cout<< ".............................................."<<endl;
    int cantJornadas=CantidadRegistrosJornada();
    int cantTurnos=CantidadRegistrosTurnos();
    for(i=0; i<cantJornadas; i++)
    {
        j.LeerDeDisco(i);
        ValorDevuelto=strcmp(j.getDia().c_str(),D.c_str());
        if(ValorDevuelto==0)
        {
            j.MostrarJornada();
            for(z=8; z<20; z++)
            {
                for(q=0;q<2;q++){
                    if(k==30){
                        k=0;
                    }else if(k==0){
                    k=30;
                    }
                    Tur.setHoras(z);
                    Tur.setMinutos(k);
                    if(Tur.getHoras()>=j.getEntrada().getHoras()&&Tur.getHoras()<j.getSalida().getHoras())
                    {
                    for(w=0; w<cantTurnos; w++)
                    {
                        aux.LeerDeDisco(w);
                        if(aux.getEstadoTurno()==true&&aux.getLegajoProfesional()==j.getLegajoDelProfesional()&&f==aux&&aux==Tur){
                        y++;
                        }
                    }
                    if(y==0){
                            cout<< Tur.getHoras() << ":" << Tur.getMinutos ()<< "\t" << "Prof. Disp: "<< j.getLegajoDelProfesional() <<endl;
                    }else if(y!=0){
                            cout<< Tur.getHoras() << ":" << Tur.getMinutos ()<< "\t" << "Turno tomado. " <<endl;
                    }
                    y=0;
                    }
                }
            }
            cout<<endl;
        }
    }
    system("pause");
}

void TurnosPaciente()
{
    int leg=0;
    do{
        cout<< "Ingrese el legajo del paciente: "<<endl;
        cin>> leg;
        leg=ValidarLegajoPaciente(leg);
    } while (leg==0);
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
    Jornada j;
    string D=DiaDeLaSemana(f);
    int ValorDevuelto,i,w,z,q,k=30,y=0;
    Hora Tur;
    Turno aux;
    Tur.setHoras(8);
    Tur.setMinutos(0);

    cout<<"Turnos disponibles del dia: "<< DiaDeLaSemana(f)<< " " <<f.getDia()<< "/"<<f.getMes()<< "/"<<f.getAnio()<<endl;
    cout<< "Del Profesional "<< LegProf<<endl;
    cout<< ".............................................."<<endl;
    int cantJornadas=CantidadRegistrosJornada();
    int cantTurnos=CantidadRegistrosTurnos();
    for(i=0; i<cantJornadas; i++)
    {
        j.LeerDeDisco(i);
        ValorDevuelto=strcmp(j.getDia().c_str(),D.c_str());
        if(ValorDevuelto==0&&LegProf==j.getLegajoDelProfesional())
        {
            j.MostrarJornada();
            for(z=8; z<20; z++)
            {
                for(q=0;q<2;q++){
                    if(k==30){
                        k=0;
                    }else if(k==0){
                    k=30;
                    }
                    Tur.setHoras(z);
                    Tur.setMinutos(k);
                    if(Tur.getHoras()>=j.getEntrada().getHoras()&&Tur.getHoras()<j.getSalida().getHoras())
                    {
                    for(w=0; w<cantTurnos; w++)
                    {
                        aux.LeerDeDisco(w);
                        if(aux.getEstadoTurno()==true&&aux.getLegajoProfesional()==j.getLegajoDelProfesional()&&f==aux&&aux==Tur){
                        y++;
                        }
                    }
                    if(y==0){
                            cout<< Tur.getHoras() << ":" << Tur.getMinutos ()<< "\t" << "Prof. Disp: "<< j.getLegajoDelProfesional() <<endl;
                    }else if(y!=0){
                            cout<< Tur.getHoras() << ":" << Tur.getMinutos ()<< "\t" << "Turno tomado. " <<endl;
                    }
                    y=0;
                    }
                }
            }
            cout<<endl;
        }
    }
    system("pause");
}

void DiaProf()
{
    int LegProf=0;
    Fecha f;
    MostrarTodasLasJornadaProf();

    do
    {
        LegProf=ValidarLegajoProfesional(LegProf);
    }
    while (LegProf==0);
    f=ValidarFecha(f);
    while (FinDeSemana(f)==true)
    {
        cout<<endl;
        cout<< "El dia seleccionado es fin de semana, ingrese otra fecha."<<endl;
        f=ValidarFecha(f);
    }
    TurnosDispDiaProf(f,LegProf);
}

void TurnosDispProx7Prof()
{
    Fecha f;
    f.FechaActual();
    int LegProf, i;
    cout<< "Ingrese legajo del profesional: "<<endl;
    cin>> LegProf;
    f.setDia(f.getDia()-1);
    for (i=0; i<7; i++)
    {
        f.setDia(f.getDia()+1);
        while(FinDeSemana(f)==true)
        {
            f.setDia(f.getDia()+1);
        }
        TurnosDispDiaProf(f,LegProf);
    }
}

void TurnosDispPorProf()
{
    int y=1;
    int i=0;
    rlutil::cls();
    while(i==0)
    {
        rlutil::locate(30,10);
        cout<< "....... Turnos por profesional ......."<<endl;
        rlutil::locate(30,11);
        cout<< "1. Mostrar Turnos disponibles por dia: "<<endl;
        rlutil::locate(30,12);
        cout<< "2. Mostrar Turnos disponibles de los proximos 7 dias: "<<endl;
        rlutil::locate(30,13);
        cout<< "0. Volver a menu principal: "<<endl;
        rlutil::locate(30,14);
        cout<< ".................................."<<endl<<endl;
        rlutil::locate(28,10+y);
        cout<< (char)175<<endl;

        switch(rlutil::getkey())
        {
        case 14: //up
            rlutil::locate(28,10+y);
            cout<< " "<<endl;
            y--;
            if(y<1)
            {
                y=1;
            }
            break;
        case 15: //down
            rlutil::locate(28,10+y);
            cout<< " "<<endl;
            y++;
            if(y>3)
            {
                y=3;
            }
            break;
        case 1: //enter
            switch(y)
            {
            case 1:
                rlutil::cls();
                cout<< "1. Mostrar Turnos disponibles del dia: "<<endl;
                cout<< "........................................."<<endl;
                DiaProf();
                rlutil::cls();
                break;
            case 2:
                rlutil::cls();
                cout<< "2. Mostrar Turnos disponibles de los proximos 7 dias: "<<endl;
                cout<< "..................................................."<<endl<<endl;
                TurnosDispProx7Prof();
                rlutil::cls();
                break;
            case 3:
                i=1;
                rlutil::cls();
                break;
            }
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
        system("cls");
    }
}

void MenuAgenda()
{
    int i=0;
    int y=1;
    rlutil::cls();
    while(i==0)
    {
        rlutil::locate(30,10);
        cout<< "....... Menu Agenda ......."<<endl;
        rlutil::locate(30,11);
        cout<< "1. Turnos del dia: "<<endl;
        rlutil::locate(30,12);
        cout<< "2. Turnos de los proximos 7 dias: "<<endl;
        rlutil::locate(30,13);
        cout<< "3. Turnos por mes: "<<endl;
        rlutil::locate(30,14);
        cout<< "4. Turnos por paciente: "<<endl;
        rlutil::locate(30,15);
        cout<< "5. Turnos disponibles por dia: "<<endl;
        rlutil::locate(30,16);
        cout<< "6. Turnos disponibles de los proximos 7 dias: "<<endl;
        rlutil::locate(30,17);
        cout<< "7. Turnos disponibles por profesional: "<<endl;
        rlutil::locate(30,18);
        cout<< "0. Volver a menu principal: "<<endl;
        rlutil::locate(30,19);
        cout<< ".................................."<<endl;
        rlutil::locate(28,10+y);
        cout<< (char)175<<endl;

        switch(rlutil::getkey())
        {
        case 14: //up
            rlutil::locate(28,10+y);
            cout<< " "<<endl;
            y--;
            if(y<1)
            {
                y=1;
            }
            break;
        case 15: //down
            rlutil::locate(28,10+y);
            cout<< " "<<endl;
            y++;
            if(y>8)
            {
                y=8;
            }
            break;
        case 1: //enter
            switch(y)
            {
            case 1:
            {
                rlutil::cls();
                cout<< "1. Turnos del dia: "<<endl<<endl;
                Fecha f;
                f.FechaActual();
                if (FinDeSemana(f)==true)
                {
                    cout<<"Hoy es fin de semana. y no hay turnos."<<endl;
                    system("pause");
                    rlutil::cls();
                    break;
                }
                TurnosDelDia(f);
            }
            rlutil::cls();
            break;
            case 2:
                rlutil::cls();
                cout<< "2. Turnos de los proximos 7 dias: "<<endl;
                cout<< ".................................."<<endl<<endl;
                TurnosProx7Dias();
                rlutil::cls();
                break;
            case 3:
                rlutil::cls();
                cout<< "3. Turnos por mes: "<<endl;
                cout<< ".................................."<<endl<<endl;
                TurnosMes();
                rlutil::cls();
                break;
            case 4:
                rlutil::cls();
                cout<< "4. Turnos por paciente: "<<endl;
                cout<< ".................................."<<endl<<endl;
                TurnosPaciente();
                rlutil::cls();
                break;
            case 5:
                rlutil::cls();
                cout<< "5. Turnos disponibles por dia: "<<endl;
                cout<< ".................................."<<endl<<endl;
                TurnosDispDia();
                rlutil::cls();
                break;
            case 6:
                rlutil::cls();
                cout<< "6. Turnos disponibles de los proximos 7 dias: "<<endl;
                cout<< ".................................."<<endl<<endl;
                TurnosDispProx7Dias();
                rlutil::cls();
                break;
            case 7:
                rlutil::cls();
                cout<< "7. Turnos disponibles por profesional: "<<endl;
                cout<< ".................................."<<endl<<endl;
                TurnosDispPorProf();
                rlutil::cls();
                break;
            case 8:
                i=1;
                rlutil::cls();
                break;
            }
        }
    }
}

#endif // AGENDA_CPP_INCLUDED
