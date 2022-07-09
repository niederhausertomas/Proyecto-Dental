#include <iostream>
#include <cstring>
#include <cstdlib>
#include "rlutil.h"
using namespace std;
#include "Persona.h"
#include "Paciente.h"
#include "Profesional.h"
#include "Fecha.h"
#include "Hora.h"
#include "Turno.h"
#include "Agenda.h"
#include "Validar.h"
#include "Reportes.h"

int main()
{
    rlutil::setBackgroundColor(rlutil::DARKGREY);
    rlutil::setColor(rlutil::WHITE);
    int y=1;
    char confirmarCerrar;
    rlutil::hidecursor();
    rlutil::cls();
    while(true)
    {
        rlutil::locate(30,10);
        cout<< "..............Menu................"<<endl;
        rlutil::locate(30,11);
        cout<< "1. Pacientes: "<<endl;
        rlutil::locate(30,12);
        cout<< "2. Profesionales: "<<endl;
        rlutil::locate(30,13);
        cout<< "3. Turnos: "<<endl;
        rlutil::locate(30,14);
        cout<< "4. Agenda: "<<endl;
        rlutil::locate(30,15);
        cout<< "5. Reportes: "<<endl;
        rlutil::locate(30,16);
        cout<< "0. Cerrar sistema: "<<endl;
        rlutil::locate(30,17);
        cout<< ".................................."<<endl<<endl;
        rlutil::locate(28,10+y);
        cout<< (char)175<<endl;

        switch(rlutil::getkey())
        {
        case 14: //up
            rlutil::locate(28,10+y);
            cout<< " "<<endl;
            y--;
            if(y<1){
                y=1;
            }
            break;
        case 15: //down
            rlutil::locate(28,10+y);
            cout<< " "<<endl;
            y++;
            if(y>6){
                y=6;
            }
            break;
        case 1: //enter
            switch(y){
        case 1:
            menuPacientes();
            break;
        case 2:
            menuProfesionales();
            break;
        case 3:
            MenuTurnos();
            break;
        case 4:
            MenuAgenda();
            break;
        case 5:
            Reportes();
            break;
        case 6:
            return 0;
            break;
        default:
            break;
            }
        }



/*
        cin>>opcion;
        switch(opcion)
        {
        case 1:
            menuPacientes();
            break;
        case 2:
            menuProfesionales();
            break;
        case 3:
            MenuTurnos();
            break;
        case 4:
            MenuAgenda();
            break;
        case 5:
            //f.fechaActual();
            break;
        case 0:
            cout<< "Confirma salir? s/n"<<endl;
            cin>> confirmarCerrar;
            if (tolower(confirmarCerrar)=='s')
            {
                return 0;
            }
            break;
        }
        system("pause");
*/
    }
    cout<<endl;
    system("pause");
    return 0;
}
