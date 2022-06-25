#include <iostream>
#include <cstring>
# include<cstdlib>
using namespace std;
#include "Persona.h"
#include "Paciente.h"
#include "Profesional.h"
#include "Fecha.h"
#include "Hora.h"
#include "Turno.h"
#include "Agenda.h"

// Ver tema de la libreria rlutil para mejorar la estetica https://youtu.be/z2cfUpUqdTs a partir del minuto 55
int main()
{
    int opcion;
    char confirmarCerrar;
    while(true)
    {
        Hora V[24];
        Horarios(V);
        system("cls");
        cout<< "..............Menu................"<<endl;
        cout<< "1. Pacientes: "<<endl;
        cout<< "2. Profesionales: "<<endl;
        cout<< "3. Turnos: "<<endl;
        cout<< "4. Agenda: "<<endl;
        cout<< "0. Cerrar sistema: "<<endl;
        cout<< "Ingrese opcion: "<<endl;
        cout<< ".................................."<<endl<<endl;
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

    }

    cout<<endl;
    system("pause");
    return 0;
}
