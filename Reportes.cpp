#ifndef REPORTES_CPP_INCLUDED
#define REPORTES_CPP_INCLUDED
#include<iostream>
using namespace std;
#include "rlutil.h"





void Reportes(){
        rlutil::cls();
        rlutil::locate(30,10);
        cout<< "..........Reportes.........."<<endl;
        rlutil::locate(30,11);
        cout<< "- Promedio de inasistencias mensuales: "<<endl;
        rlutil::locate(30,12);
        cout<< "- Promedio de turnos mensuales: "<<endl;
        rlutil::locate(30,13);
        cout<< "- Turnos asignados a cada profesional en porcentaje: "<<endl;
        rlutil::locate(30,14);
        cout<< "- Promedio de Turnos cancelados: "<<endl;
        rlutil::locate(30,15);
        cout<< "..........Reportes.........."<<endl;
        rlutil::locate(30,20);
        system("pause");
        rlutil::cls();
}



#endif // REPORTES_CPP_INCLUDED
