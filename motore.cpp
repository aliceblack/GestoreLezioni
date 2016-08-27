#include "motore.h"


Motore::Motore(int id, QString st, QString vel, bool ist, int m, bool pag): Lezione(id, st, vel, ist, m, pag) {}

Motore::~Motore(){}

const double Motore::stimaConsumo = 0.37;
