#ifndef JORNADA_H_INCLUDED
#define JORNADA_H_INCLUDED
#include "Fecha.h"
#include "Hora.h"

class Jornada{
    private:
        int _Id;
        char _Dia[10];
        int _LegajoDelProfesional;
        Hora _Entrada;
        Hora _Salida;
    public:
        void setId(int Id);
        void setDia(string Dia);
        void setLegajoDelProfesional(int LegajoDelProfesional);
        void setEntrada(Hora Entrada);
        void setSalida (Hora Salida);
        int getId();
        string getDia();
        int getLegajoDelProfesional();
        Hora getEntrada();
        Hora getSalida();
        void CargarJornada();
        bool VerificarJornada(Jornada j);
        bool GuardarEnDisco();
        bool GuardarEnDisco(int nroRegistro);
        void MostrarJornada();
        bool LeerDeDisco(int nroRegistro);
};

//-------------------------------------------------------------------------------------------

int CantidadRegistrosJornada();
int BuscarJornadaPorLegajoProfesional();
void EditarJornada();
void MostrarJornadaProf();
void MostrarTodasLasJornadaProf();
bool ProfDisponibleDia(Fecha FechaTurno);
int IdDeJornadaNuevo();
#endif // JORNADA_H_INCLUDED
