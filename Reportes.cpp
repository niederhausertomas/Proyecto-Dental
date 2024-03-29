#ifndef REPORTES_CPP_INCLUDED
#define REPORTES_CPP_INCLUDED
#include<iostream>
using namespace std;
#include "rlutil.h"
#include "Turno.h"
#include "Fecha.h"
#include "Validar.h"


float PromedioDeTrunos(Fecha f)
{
    Turno aux;
    int i, cant=0;
    float promedio;
    int cantTurnos=CantidadRegistrosTurnos();
    for(i=0; i<cantTurnos; i++)
    {
        aux.LeerDeDisco(i);
        if(aux.getFechaTurno().getAnio()==f.getAnio()&&aux.getFechaTurno().getMes()==f.getMes())
        {
            cant++;
            if(aux.getEstadoTurno()==1||aux.getEstadoTurno()==2)
            {
                cant++;
            }
        }
    }
    promedio=(cant/20.0);
    return promedio;
}

float InasistenciasConAviso(Fecha f)
{
    Turno aux;
    int i,inasistencias=0, cant=0;
    int cantTurnos=CantidadRegistrosTurnos();
    for(i=0; i<cantTurnos; i++)
    {
        aux.LeerDeDisco(i);
        if(aux.getFechaTurno().getAnio()==f.getAnio()&&aux.getFechaTurno().getMes()==f.getMes())
        {
            cant++;
            if(aux.getEstadoTurno()==3)
            {
                inasistencias++;
            }
        }
    }
    inasistencias=inasistencias*100/cant;
    return inasistencias;
}

float InasistenciasSinAviso(Fecha f)
{
    Turno aux;
    int i,inasistencias=0, cant=0;
    int cantTurnos=CantidadRegistrosTurnos();
    for(i=0; i<cantTurnos; i++)
    {
        aux.LeerDeDisco(i);
        if(aux.getFechaTurno().getAnio()==f.getAnio()&&aux.getFechaTurno().getMes()==f.getMes())
        {
            cant++;
            if(aux.getEstadoTurno()==2)
            {
                inasistencias++;
            }
        }
    }
    inasistencias=inasistencias*100/cant;
    return inasistencias;
}

void Reportes()
{
    rlutil::cls();
    Fecha f;
    rlutil::locate(30,9);
    cout<< "Ingrese anio y mes a consultar: "<<endl;
    rlutil::locate(30,10);
    cout<< "..................................."<<endl;
    f.setAnio(ValidarAnio(f.getAnio()));
    rlutil::cls();
    rlutil::locate(30,9);
    cout<< "Ingrese anio y mes a consultar: "<<endl;
    rlutil::locate(30,10);
    cout<< "..................................."<<endl;
    f.setMes(ValidarMes(f.getMes()));
    float a=InasistenciasSinAviso(f);
    float b=InasistenciasConAviso(f);
    float c=PromedioDeTrunos(f);

    rlutil::cls();
    rlutil::locate(30,10);
    cout<< "........Reportes del mes "<< f.getMes()<< " del anio " << f.getAnio()<< "........"  <<endl;
    rlutil::locate(30,11);
    cout<< "- Promedio de inasistencias sin aviso: "<< a <<" %"<<endl;
    rlutil::locate(30,12);
    cout<< "- Promedio de turnos cancelados con aviso: "<< b <<" %"<<endl;
    rlutil::locate(30,13);
    cout<< "- Promedio de turnos mensuales: "<< c <<endl;
    rlutil::locate(30,14);
    cout<< "............................................."<<endl;
    rlutil::locate(30,15);
    system("pause");
    rlutil::cls();
}


#endif // REPORTES_CPP_INCLUDED
