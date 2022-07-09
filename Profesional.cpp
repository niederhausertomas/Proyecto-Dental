#ifndef PROFESIONAL_CPP_INCLUDED
#define PROFESIONAL_CPP_INCLUDED
#include<iostream>
using namespace std;
#include "Profesional.h"
#include "Jornada.h"
#include "Validar.h"


void Profesional::setLegajo(int legajo)
{
    _legajo=legajo;
}
void Profesional::setMatricula(int matricula)
{
    _matricula=matricula;
}
void Profesional::setEstadoProfesional(bool estadoProfesional)
{
    _estadoProfesional=estadoProfesional;
}
int Profesional::getLegajo()
{
    return _legajo;
}
int Profesional::getMatricula()
{
    return _matricula;
}
bool Profesional::getEstadoProfesional()
{
    return _estadoProfesional;
}

void Profesional::cargarProfesional()
{
    int Dni, Legajo, Matricula, Dia, Mes, Anio,x;
    string Nombre;
    string Apellido;
    string Email;
    string Domicilio;
    string Telefono;
    bool EstadoProfesional;
    Fecha fechaNac;
    int Leg=1;
    Profesional aux;
    int i;
    int cantProfesionales=cantidadRegistrosProfesionales();
    for(i=0; i<cantProfesionales; i++)
    {
        aux.leerDeDisco(i);
        if(Leg<=aux.getLegajo())
        {
            Leg=aux.getLegajo()+1;
        }
    }
    cout<< "Legajo del Profesional: ";
    cout<< Leg<<endl;
    setLegajo(Leg);
    Dni=ValidarDni(Dni);
    setDni(Dni);
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
    cout<< "Ingrese matricula del profesional: "<<endl;
    cin>> Matricula;
    setMatricula(Matricula);
    setEstadoProfesional(true);
}

void Profesional::mostrarProfesional()
{
    cout<< "Legajo del profesional: "<<getLegajo()<<endl;
    cout<< "DNI: "<<getDni()<<endl;
    cout<< "Nomre: "<<getNombre()<<endl;
    cout<< "Apellido: "<<getApellido()<<endl;
    cout<< "Email: "<<getEmail()<<endl;
    cout<< "domicilio: "<<getDomicilio()<<endl;
    cout<< "Telefono: "<<getTelefono()<<endl;
    cout<< "Matricula: "<<getMatricula() <<endl;
    cout<< "Fecha de nacimiento: "<< getFechaNacimiento().getDia() << "/"<< getFechaNacimiento().getMes()<< "/"<< getFechaNacimiento().getAnio()<<endl;
    cout<< "Estado del Profesional: ";
    ValidarEstado(getEstadoProfesional());
    cout<<endl;
}

bool Profesional::leerDeDisco(int nroRegistro)
{
    FILE *p = fopen("Profesional.dat", "rb");
    if (p==NULL)
    {
        return false;
    }
    fseek(p,nroRegistro*sizeof(Profesional),SEEK_SET);
    bool ok=fread(this, sizeof(Profesional),1,p);
    fclose(p);
    return ok;
}

bool Profesional::guardarEnDisco()
{
    FILE *p = fopen("profesional.dat", "ab");
    if (p==NULL)
    {
        return false;
    }
    bool guardo = fwrite (this, sizeof(Profesional), 1,p);
    fclose(p);
    return guardo;
}

bool Profesional::guardarEnDisco(int nroRegistro)
{
    FILE *p = fopen("profesional.dat", "rb+");
    if (p==NULL)
    {
        return false;
    }
    fseek(p,nroRegistro*sizeof(Profesional),SEEK_SET);
    bool guardo = fwrite (this, sizeof(Profesional), 1,p);
    fclose(p);
    return guardo;
}

//---------------------------------------------------------------------------

int BuscarProfesionalPorLegajo()
{
    int leg;
    cout<<"Ingrese legajo del profesional: ";
    cin>> leg;
    Profesional aux;
    int i;
    int cantProfesionales=cantidadRegistrosProfesionales();
    for(i=0; i<cantProfesionales; i++)
    {
        aux.leerDeDisco(i);
        if(aux.getLegajo()==leg)
        {
            aux.mostrarProfesional();
            return leg;
        }
    }
    cout<<"No existe el profesional."<<endl;
}

void EditarProfesional()
{
    int leg;
    cout<<"Ingrese legajo del profesional: ";
    cin>> leg;
    Profesional aux;
    int i;
    int cantProfesionales=cantidadRegistrosProfesionales();
    for(i=0; i<cantProfesionales; i++)
    {
        aux.leerDeDisco(i);
        if(aux.getLegajo()==leg)
        {
            int opcion;
            int Dni, Legajo, Matricula, Dia, Mes, Anio;
            string Nombre;
            string Apellido;
            string Email;
            string Domicilio;
            string Telefono;
            bool EstadoProfesional;
            aux.mostrarProfesional();
            cout<< endl;
            cout<< "Ingrese la opcion que desea modificar: "<<endl;
            cout<< "1. Legajo: "<<endl;
            cout<< "2. DNI: "<<endl;
            cout<< "3. Nombre: "<<endl;
            cout<< "4. Apellido: "<<endl;
            cout<< "5. Email: "<<endl;
            cout<< "6. Domicilio: "<<endl;
            cout<< "7. Telefono: "<<endl;
            cout<< "8. Legajo del profesional: "<<endl;
            cout<< "9. Matricula del profesional: "<<endl;
            cout<<"10. Fecha de nacimiento: "<<endl;
            cout<< "11. Estado del profesional: "<<endl;
            cout<< "0. Salir de modificacion: "<<endl;
            cin>>opcion;
            switch(opcion)
            {
            case 1:
                cout<< "Ingrese legajo del paciente: "<<endl;
                cin>> Legajo;
                aux.setLegajo(Legajo);
                aux.guardarEnDisco(i);
                break;
            case 2:
                cout<< "Ingrese dni: "<<endl;
                cin>>Dni;
                aux.setDni(Dni);
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
                cout<< "Ingrese el legajo del profesional: "<<endl;
                cin>> Legajo;
                aux.setLegajo(Legajo);
                aux.guardarEnDisco(i);
                break;
            case 9:
                cout<< "Ingrese numero de matricula del profesional: "<<endl;
                cin>> Matricula;
                aux.setMatricula(Matricula);
                aux.guardarEnDisco(i);
                break;
            case 10:
                {cout<< "Dia de nacimiento: "<<endl;
                cin>>Dia;
                cout<< "Mes de nacimiento: "<<endl;
                cin>>Mes;
                cout<< "Anio de nacimiento: "<<endl;
                cin>>Anio;
                Fecha fechaNac(Dia, Mes, Anio);
                aux.setFechaNacimiento(fechaNac);
                aux.guardarEnDisco(i);}
                break;
            case 11:
                int n;
                do{
                cout<< "Ingrese 1. para profesional activo, 2. Para profesional inactivo: "<<endl;
                cin>> n;
                } while(n<1||n>2);
                if (n==1){
                aux.setEstadoProfesional(true);
                }
                if (n==2){
                aux.setEstadoProfesional(false);
                }
                aux.guardarEnDisco(i);
                break;
            case 0:
                    return;
                break;
            }
            cout<<endl;
            aux.mostrarProfesional();
            system("pause");
            return;
        }
    }
    cout<<"No existe el profesional."<<endl;
    return;
}

void menuProfesionales()
{
    int opcion;
    Profesional prof;
    int i=0;
    while(i==0)
    {
        system("cls");
        cout<< "....... Menu profesionales ......."<<endl;
        cout<< "1. Cargar nuevo profesional: "<<endl;
        cout<< "2. Listado de profesionales Activos: "<<endl;
        cout<< "3. Listado de profesionales inactivos: "<<endl;
        cout<< "4. Listado Todos los profesionales: "<<endl;
        cout<< "5. Buscar profesional por legajo: "<<endl;
        cout<< "6. Editar Profesional: "<<endl;
        cout<< "7. Cargar jornada de Profesional: "<<endl;
        cout<< "8. Editar Jornada de profesional: "<<endl;
        cout<< "9. Mostrar jornada de un profesional: "<<endl;
        cout<< "10. Mostrar todas las jornadas: "<<endl;
        cout<< "0. Volver a menu principal: "<<endl;
        cout<< ".................................."<<endl<<endl;
        cout<< "Ingrese opcion: ";
        cin>>opcion;
        switch(opcion)
        {
        case 1:
            system("cls");
            cout<< "1. Cargar nuevo profesional: "<<endl;
            cout<< ".................................."<<endl<<endl;
            prof.cargarProfesional();
            if (prof.guardarEnDisco()==true)
            {
                cout<< "Profesional guardado correctamente. "<<endl;
            }
            else
            {
                cout<< "No se pudo guardar."<<endl;
            };
            cout<< endl;
            prof.mostrarProfesional();
            system("pause");
            break;
        case 2:
            system("cls");
            cout<< "2. Listado de profesionales activos: "<<endl;
            cout<< ".................................."<<endl<<endl;
            listarProfesionalesActivos();
            system("pause");
            break;
        case 3:
            system("cls");
            cout<< "3. Listado de profesionales Inactivos: "<<endl;
            cout<< ".................................."<<endl<<endl;
            listarProfesionalesInactivos();
            system("pause");
            break;
        case 4:
            system("cls");
            cout<< "4. Listado de todos los profesionales: "<<endl;
            cout<< ".................................."<<endl<<endl;
            listarProfesionales();
            system("pause");
            break;
        case 5:
            BuscarProfesionalPorLegajo();
            system("pause");
            break;
        case 6:
            EditarProfesional();
            break;
        case 7:
            Jornada j;
            j.CargarJornada();
            cout<<endl;
            if (j.GuardarEnDisco()==true)
            {
                cout<< "Jornada cargada correctamente. "<<endl;
            }
            else
            {
                cout<< "No se pudo cargar la jornada."<<endl;
            };
            cout<< endl;
            j.MostrarJornada();
            system("pause");
            break;
        case 8:
            EditarJornada();
            break;
        case 9:
            MostrarJornadaProf();
            break;
        case 10:
            cout<<endl;
            cout<< "---- Todas las jornadas: ----"<<endl<<endl;
            MostrarTodasLasJornadaProf();
            break;
        case 0:
            i=1;
            break;
        }
    }
}

void listarProfesionales()
{
    Profesional aux;
    int z=0;
    FILE *p= fopen("profesional.dat","rb");
    if(p==NULL)
    {
        return;
    }
    while(fread(&aux,sizeof(Profesional),1,p)==1)
    {
        aux.mostrarProfesional();
        cout<<endl;
        z++;
    }
    fclose(p);
    cout<< "Hay " << z<< " Profesionales. "<<endl;
}

void listarProfesionalesActivos()
{
    Profesional aux;
    FILE *p= fopen("profesional.dat","rb");
    int z=0;
    if(p==NULL)
    {
        return;
    }
    while(fread(&aux,sizeof(Profesional),1,p)==1)
    {
        if (aux.getEstadoProfesional()==true)
        {
            aux.mostrarProfesional();
            cout<<endl;
            z++;
        }
    }
    cout<< "Hay "<< z<< " profesionales activos."<<endl;
    fclose(p);
}

void listarProfesionalesInactivos()
{
    Profesional aux;
    FILE *p= fopen("profesional.dat","rb");
    int z=0;
    if(p==NULL)
    {
        return;
    }
    while(fread(&aux,sizeof(Profesional),1,p)==1)
    {
        if (aux.getEstadoProfesional()==false)
        {
            aux.mostrarProfesional();
            cout<<endl;
            z++;
        }
    }
    cout<< "Hay "<< z<< " profesionales inactivos."<<endl;
    fclose(p);
}

int cantidadRegistrosProfesionales()
{
    FILE *p= fopen("profesional.dat","rb");
    if(p==NULL)
    {
        return 0;
    }
    long bytes;
    int cantReg;
    fseek(p,0,SEEK_END);
    bytes=ftell(p);
    cantReg=bytes/sizeof(Profesional);
    return cantReg;
}

#endif // PROFESIONAL_CPP_INCLUDED
