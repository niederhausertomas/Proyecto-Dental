#ifndef PACIENTE_CPP_INCLUDED
#define PACIENTE_CPP_INCLUDED
#include<iostream>
using namespace std;
#include "Paciente.h"
#include <string>
#include "Validar.h"


void Paciente::setLegajo(int legajo)
{
    _legajo=legajo;
}
void Paciente::setInasistencias(int inasistencias)
{
    _inasistencias=inasistencias;
}
void Paciente::setNroObraSocial(int nroObraSocial)
{
    _nroObraSocial=nroObraSocial;
}
void Paciente::setEstadoPaciente(bool estadoPaciente)
{
    _estadoPaciente=estadoPaciente;
}
int Paciente::getLegajo()
{
    return _legajo;
}
int Paciente::getInasistencias()
{
    return _inasistencias;
}
int Paciente::getNroObraSocial()
{
    return _nroObraSocial;
}
bool Paciente::getEstadoPaciente()
{
    return _estadoPaciente;
}

int LegajoDePacienteNuevo(){
    int leg=1;
    Paciente aux;
    int i;
    int cantPacientes=cantidadRegistrosPacientes();
    for(i=0; i<cantPacientes; i++)
    {
        aux.leerDeDisco(i);
        if(leg<=aux.getLegajo())
        {
            leg=aux.getLegajo()+1;
        }
    }
    return leg;
}

void Paciente::Cargar()
{
    int DNI, legajo, inasistencias=0, nroObraSocial, dia, mes, anio;
    Fecha fechaNac;
    string Nombre, Apellido, Email, Domicilio, Telefono;
    bool estadoPaciente;
    cout<< "Legajo del Paciente: ";
    setLegajo( LegajoDePacienteNuevo());
    cout<<getLegajo() <<endl;
    DNI=ValidarDni(DNI);
    setDni(DNI);
    cout<< "Ingrese nomre: "<<endl;
    cin.clear();
    cin.ignore(1000,'\n');
    getline(cin,Nombre);
    setNombre(Nombre);
    cout<< "Ingrese apellido: "<<endl;
    getline(cin,Apellido);
    setApellido(Apellido);
    cout<< "Fecha de Nacimiento: "<<endl;
    setFechaNacimiento(ValidarFecha(fechaNac));
    cout<< "Ingrese email: "<<endl;
    cin.ignore();
    getline(cin,Email);
    setEmail(Email);
    cout<< "Ingrese el domicilio: "<<endl;
    getline(cin,Domicilio);
    setDomicilio(Domicilio);
    cout<< "Ingrese el telefono: "<<endl;
    getline(cin,Telefono);
    setTelefono(Telefono);
    setInasistencias(0);
    cout<< "Ingrese numero de obra social: "<<endl;
    cin>> nroObraSocial;
    setNroObraSocial(nroObraSocial);
    setEstadoPaciente(true);
}


void Paciente::Mostrar()
{
    cout<<endl;
    cout<< "Legajo: " <<getLegajo()<<endl;
    cout<< "DNI: " <<getDni()<<endl;
    cout<< "Nombre: "<<getNombre()<<endl;
    cout<< "Apellido: " <<getApellido()<<endl;
    cout<<"Email: "<<getEmail()<<endl;
    cout<<"Domicilio: "<<getDomicilio()<<endl;
    cout<<"Telefono: "<<getTelefono()<<endl;
    cout<<"Inasistencias: "<<getInasistencias()<<endl;
    cout<<"Numero de obra social: "<<getNroObraSocial()<<endl;
    cout<<"Fecha de nacimiento: "<<getFechaNacimiento().getDia()<<"/"<<getFechaNacimiento().getMes()<<"/"<<getFechaNacimiento().getAnio()<<endl;
    cout<< "Estado de Paciente: ";
    ValidarEstado(getEstadoPaciente());
    cout<<endl;
}

bool Paciente::leerDeDisco(int nroRegistro)
{
    FILE *p = fopen("Paciente.dat", "rb");
    if (p==NULL)
    {
        return false;
    }
    fseek(p,nroRegistro*sizeof(Paciente),SEEK_SET);
    bool ok=fread(this, sizeof(Paciente),1,p);
    fclose(p);
    return ok;
}

bool Paciente::guardarEnDisco()
{
    FILE *p = fopen("paciente.dat", "ab");
    if (p==NULL)
    {
        return false;
    }
    bool guardo = fwrite (this, sizeof(Paciente), 1,p);
    fclose(p);
    return guardo;
}

bool Paciente::guardarEnDisco(int nroRegistro)
{
    FILE *p = fopen("paciente.dat", "rb+");
    if (p==NULL)
    {
        return false;
    }
    fseek(p,nroRegistro*sizeof(Paciente),SEEK_SET);
    bool guardo = fwrite (this, sizeof(Paciente), 1,p);
    fclose(p);
    return guardo;
}

//-------------------------------------------------------------------------------------------------------------------
void menuPacientes()
{
    int opcion;
    Paciente reg;
    int i=0;
    while(i==0)
    {
        system("cls");
        cout<< "......... Menu Pacientes .........."<<endl;
        cout<< "1. Cargar nuevo paciente: "<<endl;
        cout<< "2. Listado de pacientes Activos: "<<endl;
        cout<< "3. Listado de pacientes inactivos: "<<endl;
        cout<< "4. Listar Todos los pacientes: "<<endl;
        cout<< "5. Buscar paciente por legajo: "<<endl;
        cout<< "6. Editar Paciente: "<<endl;
        cout<< "0. Volver a menu principal: "<<endl;
        cout<< ".................................."<<endl<<endl;
        cout<< "Ingrese opcion: ";
        cin>>opcion;
        switch(opcion)
        {
        case 1:
            system("cls");
            cout<< "1. Cargar nuevo paciente: "<<endl;
            cout<< ".................................."<<endl<<endl;
            reg.Cargar();
            if (reg.guardarEnDisco()==true)
            {
                cout<< "Paciente guardado correctamente. "<<endl;
            }
            else
            {
                cout<< "No se pudo guardar."<<endl;
            };
            system("pause");
            break;
        case 2:
            system("cls");
            cout<< "2. Listado de pacientes activos: "<<endl;
            cout<< ".................................."<<endl<<endl;
            listarPacientesActivos();
            system("pause");
            break;
        case 3:
            system("cls");
            cout<< "3. Listado de pacientes inactivos: "<<endl;
            cout<< ".................................."<<endl<<endl;
            listarPacientesInactivos();
            system("pause");
            break;
        case 4:
            system("cls");
            cout<< "4. Listado del total de pacientes: "<<endl;
            cout<< ".................................."<<endl<<endl;
            listarPacientes();
            system("pause");
            break;
        case 5:
            BuscarPacientePorLegajo();
            system("pause");
            break;
        case 6:
            EditarPaciente();
            system("pause");
            break;
        case 0:
            i=1;
            break;
        }
    }
}


void listarPacientes()
{
    Paciente aux;
    int i;
    int cantPacientes=cantidadRegistrosPacientes();
    for(i=0; i<cantPacientes; i++)
    {
        aux.leerDeDisco(i);
        aux.Mostrar();
        cout<<endl;
    }

cout<< "Cantidad de Pacientes Total: "<< cantPacientes<<endl;
}

void listarPacientesActivos(){
    Paciente aux;
    int i,z=0;
    int cantPacientes=cantidadRegistrosPacientes();
    for(i=0; i<cantPacientes; i++)
    {
        aux.leerDeDisco(i);
        if (aux.getEstadoPaciente()==true){
        aux.Mostrar();
        z++;
        cout<<endl;}
    }
    cout<< "Cantidad de Pacientes Activos: "<< z<<endl;
}

void listarPacientesInactivos(){
    Paciente aux;
    int i,z=0;
    int cantPacientes=cantidadRegistrosPacientes();
    for(i=0; i<cantPacientes; i++)
    {
        aux.leerDeDisco(i);
        if (aux.getEstadoPaciente()==false){
        aux.Mostrar();
        z++;
        cout<<endl;}
    }
    cout<< "Cantidad de Pacientes inactivos: "<< z<<endl;
}

int BuscarPacientePorLegajo()
{
    int leg;
    cout<<"Ingrese legajo del paciente: ";
    cin>> leg;
    Paciente aux;
    int i;
    int cantPacientes=cantidadRegistrosPacientes();
    for(i=0; i<cantPacientes; i++)
    {
        aux.leerDeDisco(i);
        if(aux.getLegajo()==leg)
        {
            aux.Mostrar();
            return leg;
        }
    }
    cout<<"No existe el paciente."<<endl;
}

void EditarPaciente()
{
    int leg;
    cout<<"Ingrese legajo del paciente: ";
    cin>> leg;
    Paciente aux;
    int i;
    int cantPacientes=cantidadRegistrosPacientes();
    for(i=0; i<cantPacientes; i++)
    {
        aux.leerDeDisco(i);
        if(aux.getLegajo()==leg)
        {
            aux.Mostrar();
            cout<<endl;
            int opcion;
            int dni, legajo, inasistencias, nroObraSocial, dia, mes, anio;
            string Nombre;
            string Apellido;
            string Email;
            string Domicilio;
            string Telefono;
            bool estadoPaciente;
            cout<< "Ingrese la opcion que desea modificar: "<<endl;
            cout<< "1. Legajo: "<<endl;
            cout<< "2. DNI: "<<endl;
            cout<< "3. Nombre: "<<endl;
            cout<< "4. Apellido: "<<endl;
            cout<<"5. Email: "<<endl;
            cout<<"6. Domicilio: "<<endl;
            cout<<"7. Telefono: "<<endl;
            cout<<"8. Inasistencias: "<<endl;
            cout<<"9. Numero de obra social: "<<endl;
            cout<<"10. Fecha de nacimiento: "<<endl;
            cout<< "11. Estado del paciente: "<<endl;
            cout<< "0. Salir de modificacion: "<<endl;
            cin>>opcion;
            switch(opcion)
            {
            case 1:
                cout<< "Ingrese legajo del paciente: "<<endl;
                cin>> legajo;
                aux.setLegajo(legajo);
                aux.guardarEnDisco(i);
                break;
            case 2:
                cout<< "Ingrese dni: "<<endl;
                cin>>dni;
                aux.setDni(dni);
                aux.guardarEnDisco(i);
                break;
            case 3:
                cout<< "Ingrese nomre: "<<endl;
                cin.ignore();
                getline(cin,Nombre);
                aux.setNombre(Nombre);
                aux.guardarEnDisco(i);
                break;
            case 4:
                cout<< "Ingrese apellido: "<<endl;
                cin.ignore();
                getline(cin,Apellido);
                aux.setApellido(Apellido);
                aux.guardarEnDisco(i);
                break;
            case 5:
                cout<< "Ingrese email: "<<endl;
                cin.ignore();
                getline(cin,Email);
                aux.setEmail(Email);
                aux.guardarEnDisco(i);
                break;
            case 6:
                cout<< "Ingrese el domicilio: "<<endl;
                cin.ignore();
                getline(cin,Domicilio);
                aux.setDomicilio(Domicilio);
                aux.guardarEnDisco(i);
                break;
            case 7:
                cout<< "Ingrese el telefono: "<<endl;
                cin.ignore();
                getline(cin,Telefono);
                aux.setTelefono(Telefono);
                aux.guardarEnDisco(i);
                break;
            case 8:
                cout<< "Ingrese inasistencias: "<<endl;
                cin>>inasistencias;
                aux.setInasistencias(inasistencias);
                aux.guardarEnDisco(i);
                break;
            case 9:
                cout<< "Ingrese numero de obra social: "<<endl;
                cin>> nroObraSocial;
                aux.setNroObraSocial(nroObraSocial);
                aux.guardarEnDisco(i);
                break;
            case 10:
                {cout<< "Dia de nacimiento: "<<endl;
                cin>>dia;
                cout<< "Mes de nacimiento: "<<endl;
                cin>>mes;
                cout<< "Anio de nacimiento: "<<endl;
                cin>>anio;
                Fecha fechaNac(dia, mes, anio);
                aux.setFechaNacimiento(fechaNac);
                aux.guardarEnDisco(i);}
                break;
            case 11:
                int n;
                do{
                cout<< "Ingrese 1. para paciente como activo, 2. Para paciente inactivo: "<<endl;
                cin>> n;
                } while(n<1||n>2);
                if (n==1){
                aux.setEstadoPaciente(true);
                }
                if (n==2){
                aux.setEstadoPaciente(false);
                }
                aux.guardarEnDisco(i);
                break;
            }
            aux.Mostrar();
            return;
        }
    }
    cout<<"No existe el paciente."<<endl;
    return;
}

int cantidadRegistrosPacientes()
{
    FILE *p= fopen("paciente.dat","rb");
    if(p==NULL)
    {
        return 0;
    }
    long bytes;
    int cantReg;
    fseek(p,0,SEEK_END);
    bytes=ftell(p);
    cantReg=bytes/sizeof(Paciente);
    return cantReg;
}

#endif // PACIENTE_CPP_INCLUDED
