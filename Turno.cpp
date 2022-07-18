#ifndef TURNO_CPP_INCLUDED
#define TURNO_CPP_INCLUDED
#include<iostream>
using namespace std;
#include "rlutil.h"
#include "Turno.h"
#include <string.h>
#include "Validar.h"
#include "Profesional.h"


void Turno::setId(int Id)
{
    _Id=Id;
}

void Turno::setEstadoTurno(int EstadoTurno)
{
    _EstadoTurno=EstadoTurno;
}

void Turno::setFechaTurno(Fecha FechaTurno)
{
    _FechaTurno=FechaTurno;
}

void Turno::setHoraTurno (Hora HoraTurno)
{
    _HoraTurno=HoraTurno;
}

void Turno::setLegajoPaciente(int LegajoPaciente)
{
    _LegajoPaciente=LegajoPaciente;
}

void Turno::setLegajoProfesional(int LegajoProfesional)
{
    _LegajoProfesional=LegajoProfesional;
}

void Turno::setMotivo(string Motivo)
{
    strcpy(_Motivo, Motivo.c_str());
}

int Turno::getId()
{
    return _Id;
}

int Turno::getEstadoTurno()
{
    return _EstadoTurno;
}

Fecha Turno::getFechaTurno()
{
    return _FechaTurno;
}

Hora Turno::getHoraTurno()
{
    return _HoraTurno;
}

int Turno::getLegajoPaciente()
{
    return _LegajoPaciente;
}

int Turno::getLegajoProfesional()
{
    return _LegajoProfesional;
}

string Turno::getMotivo()
{
    string Motivo;
    Motivo=_Motivo;
    return Motivo;
}

int Turno::GenerarIdTurno(){
    int Id=1;
    int i;
    int cantTurnos=CantidadRegistrosTurnos();
    for(i=0; i<cantTurnos; i++)
    {
        LeerDeDisco(i);
        if(Id<=getId())
        {
            Id=getId()+1;
        }
    }
    return Id;
}

void Turno::Cargar()
{
    int LegajoPaciente;
    string Motivo;
    setId(GenerarIdTurno());
    setEstadoTurno(1);
    setLegajoProfesional(0);
    do
    {
        rlutil::cls();
        setFechaTurno(ValidarFecha(getFechaTurno()));
        rlutil::cls();
    }
    while (ValidarFechaPasado(getFechaTurno())==false || FinDeSemana(getFechaTurno())==true );
    setFechaTurno(getFechaTurno());
    cout<< "1. Cargar nuevo turno para el : "<< getFechaTurno().getDia()<< "/"<<getFechaTurno().getMes()<< "/"<<getFechaTurno().getAnio() <<endl;
    cout<< "........................................"<<endl<<endl;
    while (getLegajoProfesional()==0)
    {
        if (ProfDisponibleDia(getFechaTurno())==true)
        {
            setLegajoProfesional(ValidarLegajoProfesional(getLegajoProfesional()));
        }
        setLegajoProfesional(ProfParaTurno(getFechaTurno(), getLegajoProfesional()));
    }
    setLegajoProfesional(getLegajoProfesional());
    do
    {
        cout<< "Ingrese legajo del paciente: ";
        cin>> LegajoPaciente;
    }
    while (ValidarLegajoPaciente(LegajoPaciente)==0);
    setLegajoPaciente(LegajoPaciente);
    do
    {
        setHoraTurno(ValidarHorario());
        setHoraTurno (ValidarHorarioConLegJornada(getHoraTurno(), getLegajoProfesional(), getFechaTurno()));
    }
    while(getHoraTurno().getHoras()==0);
    cout<< "Ingrese motivo: ";
    cin.ignore();
    getline(cin,Motivo);
    setMotivo(Motivo);
}

void Turno::Mostrar()
{
    cout<< "Id: " <<getId()<<endl;
    cout<< "Estado del turno: ";
    if(getEstadoTurno()==1)
    {
        cout<< " Activo. ";
    }
    else if(getEstadoTurno()==2)
    {
        cout<< " Falta. ";
    }else if(getEstadoTurno()==3)
    {
        cout<< " Cancelado con anticipacion. ";
    }
    cout<<endl;
    cout<< "Fecha: "<< DiaDeLaSemana(getFechaTurno())<< " " ;
    cout<<getFechaTurno().getDia()<< "/" <<getFechaTurno().getMes()<< "/" <<getFechaTurno().getAnio()<<endl;
    cout<< "Hora del turno: "<<getHoraTurno().getHoras()<< ":" <<getHoraTurno().getMinutos() <<endl;
    cout<< "Legajo del paciente: "<<getLegajoPaciente()<<endl;
    cout<< "Profesional: "<<getLegajoProfesional()<<endl;
    cout<< "Motivo: "<<getMotivo()<<endl;
}

bool Turno::GuardarEnDisco()
{
    FILE *p = fopen("Turnos.dat", "ab");
    if (p==NULL)
    {
        return false;
    }
    bool guardo = fwrite (this, sizeof(Turno), 1,p);
    fclose(p);
    return guardo;
}

bool Turno::GuardarEnDisco(int NroRegistro)
{
    FILE *p = fopen("Turnos.dat", "rb+");
    if (p==NULL)
    {
        return false;
    }
    fseek(p,NroRegistro*sizeof(Turno),SEEK_SET);
    bool guardo = fwrite (this, sizeof(Turno), 1,p);
    fclose(p);
    return guardo;
}

bool Turno::LeerDeDisco(int NroRegistro)
{
    FILE *p = fopen("Turnos.dat", "rb");
    if (p==NULL)
    {
        return false;
    }
    fseek(p,NroRegistro*sizeof(Turno),SEEK_SET);
    bool ok=fread(this, sizeof(Turno),1,p);
    fclose(p);
    return ok;
}

int CantidadRegistrosTurnos()
{
    FILE *p= fopen("Turnos.dat","rb");
    if(p==NULL)
    {
        return 0;
    }
    long bytes;
    int cantReg;
    fseek(p,0,SEEK_END);
    bytes=ftell(p);
    cantReg=bytes/sizeof(Turno);
    return cantReg;
}

void ListarTurnos()
{
    Turno aux;
    int i;
    int cantTurnos=CantidadRegistrosTurnos();
    for(i=0; i<cantTurnos; i++)
    {
        aux.LeerDeDisco(i);
        aux.Mostrar();
        cout<<endl;
    }
    cout<< "Cantidad total de turnos: "<< cantTurnos<<endl;
}

void EditarTurno()
{
    int Id;
    cout<<"Ingrese ID del Turno: ";
    cin>> Id;
    Turno aux;
    int i;
    int cantTurnos=CantidadRegistrosTurnos();
    for(i=0; i<cantTurnos; i++)
    {
        aux.LeerDeDisco(i);
        if(aux.getId()==Id)
        {
            int opcion;
            int id;
            int EstadoTurno=4;
            Fecha FechaTurno;
            int Dia, Mes,Anio;
            Hora HoraTurno;
            int Hora,Minutos;
            int LegajoPaciente;
            int LegajoProfesional;
            string Motivo;
            aux.Mostrar();
            cout<<endl;
            cout<< "Ingrese la opcion que desea modificar: "<<endl;
            cout<< "........................................"<<endl;
            cout<< "1. Id de Turno: "<<endl;
            cout<< "2. Estado de turno: "<<endl;
            cout<< "3. Fecha de Turno: "<<endl;
            cout<< "4. Hora del turno: "<<endl;
            cout<<"5. Legajo del paciente: "<<endl;
            cout<<"6. Legajo profesional : "<<endl;
            cout<<"7. Motivo: "<<endl;
            cout<< "0. Salir de modificacion: "<<endl;
            cin>>opcion;
            switch(opcion)
            {
            case 1:
                cout<< "Ingrese Id del Turno: ";
                cin>> Id;
                aux.setId(Id);
                aux.GuardarEnDisco(i);
                break;
            case 2:
                while (EstadoTurno==4){
                cout<< "Ingrese estado del turno (1- activo; 2- Falta; 3-Cancelacion con 2 dias de anticipacion.): "<<endl;
                cin>> EstadoTurno;
                if(EstadoTurno<1&&EstadoTurno>3){
                    rlutil::setColor(rlutil::RED);
                    cout<< "El estado ingresado no es valido!!"<<endl;
                    rlutil::setColor(rlutil::WHITE);
                    EstadoTurno=4;
                }
                }
                aux.setEstadoTurno(EstadoTurno);
                aux.GuardarEnDisco(i);
                break;
            case 3:
                cout<< "Ingrese dia del turno: ";
                cin>> Dia;
                FechaTurno.setDia(Dia);
                cout<< "Ingrese mes del turno: ";
                cin>> Mes;
                FechaTurno.setMes(Mes);
                cout<< "Ingrese anio del turno: ";
                cin>> Anio;
                FechaTurno.setAnio(Anio);
                aux.setFechaTurno(FechaTurno);
                aux.GuardarEnDisco(i);
                break;
            case 4:
                cout<< "Ingrese Hora del turno: ";
                cin>>Hora;
                HoraTurno.setHoras(Hora);
                cout<< "Ingrese minutos del turno: ";
                cin>>Minutos;
                HoraTurno.setMinutos(Minutos);
                aux.setHoraTurno(HoraTurno);
                aux.GuardarEnDisco(i);
                break;
            case 5:
                cout<< "Ingrese legajo del paciente: ";
                cin>> LegajoPaciente;
                aux.setLegajoPaciente(LegajoPaciente);
                aux.GuardarEnDisco(i);
                break;
            case 6:
                cout<< "Ingrese legajo profesional: ";
                cin>> LegajoProfesional;
                aux.setLegajoProfesional(LegajoProfesional);
                aux.GuardarEnDisco(i);
                break;
            case 7:
                cout<< "Ingrese motivo: ";
                cin.ignore();
                getline(cin,Motivo);
                aux.setMotivo(Motivo);
                aux.GuardarEnDisco(i);
                break;
            case 0:
                break;
            }
            aux.Mostrar();
            cout<<endl;
            system("pause");
        }
    }
}

void MenuTurnos()
{
    int y=1;
    Turno t;
    bool i=true;
    rlutil::cls();
    while(i)
    {
        rlutil::locate(30,10);
        cout<< "....... Menu Turnos ......."<<endl;
        rlutil::locate(30,11);
        cout<< "1. Cargar nuevo turno: "<<endl;
        rlutil::locate(30,12);
        cout<< "2. Listado de turnos: "<<endl;
        rlutil::locate(30,13);
        cout<< "3. Editar Turno: "<<endl;
        rlutil::locate(30,14);
        cout<< "4. Mostrar Todas las Jornadas: "<<endl;
        rlutil::locate(30,15);
        cout<< "0. Volver a menu principal: "<<endl;
        rlutil::locate(30,16);
        cout<< ".................................."<<endl<<endl;
        rlutil::locate(28,10+y);
        cout<<(char)175<<endl;

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
            if(y>5)
            {
                y=5;
            }
            break;
        case 1: //enter
        switch(y)
        {
        case 1:
            rlutil::cls();
            cout<< "1. Cargar nuevo turno: "<<endl;
            cout<< ".................................."<<endl<<endl;
            t.Cargar();
            if (t.GuardarEnDisco()==true)
            {
                cout<< "Turno guardado correctamente. "<<endl;
            }
            else
            {
                cout<< "No se pudo guardar."<<endl;
            };
            system("pause");
            rlutil::cls();
            break;
        case 2:
            rlutil::cls();
            cout<< "2. Listado de Turnos: "<<endl;
            cout<< ".................................."<<endl<<endl;
            ListarTurnos();
            system("pause");
            rlutil::cls();
            break;
        case 3:
            rlutil::cls();
            EditarTurno();
            rlutil::cls();
            break;
        case 4:
            rlutil::cls();
            cout<<endl;
            cout<< " Todas las jornadas: "<<endl;
            cout<< "-------------------------"<<endl;
            MostrarTodasLasJornadaProf();
            rlutil::cls();
            break;
        case 5:
            i=false;
            rlutil::cls();
            break;
        }
    }
}
}
#endif // TURNO_CPP_INCLUDED
