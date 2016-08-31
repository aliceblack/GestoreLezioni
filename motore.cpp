#include "motore.h"


Motore::Motore(int id, QString st, QString vel, bool ist, int m, bool pag,bool acro, int tra): Lezione(id, st, vel, ist, m, pag,acro,tra) {}

Motore::~Motore(){}

const double Motore::stimaConsumo = 0.37;
