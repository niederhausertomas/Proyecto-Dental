#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha
{
private:
    int _dia, _mes, _anio;
public:
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    int getDia();
    int getMes();
    int getAnio();
    void cargrarFehca();
    Fecha(int dia, int mes, int anio);
    Fecha();
    void FechaActual();
};
//----------------------------------------------------
string DiaDeLaSemana(Fecha f);
bool FinDeSemana(Fecha f);
#endif // FECHA_H_INCLUDED
