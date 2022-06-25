#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED

class Hora
{
private:
    int _horas, _minutos;
public:
    void setHoras(int horas);
    void setMinutos(int minutos);
    int getHoras();
    int getMinutos();
};

void Horarios(Hora V[24]);


#endif // HORA_H_INCLUDED
