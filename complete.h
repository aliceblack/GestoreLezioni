#ifndef COMPLETE_H
#define COMPLETE_H
#include <vector>
#include "ppl.h"
#include "gpl.h"
#include "vds.h"
#include "lezione.h"

class Complete{
friend class iterator;
private:
    vector<Lezione*> lezioniComp;
public:
    class iterator{
        friend class Complete;
    private:
        Lezione** punt;
    public:
        iterator();
        iterator(Lezione**);
        iterator(const iterator&);
        Lezione* operator*();
        iterator& operator++();
        iterator operator++(int);
        bool operator==(const iterator);
        bool operator!=(const iterator);
    };

    Complete();
    void add(Lezione*);
    void remove(int);
    void paga(int);
    iterator begin();
    iterator end();
    Lezione* operator[](iterator);
    Lezione* operator[](vector<Lezione*>::iterator);
    Lezione* operator[](int);
    int oreSoloPPL();
    int oreMasterPPL();
    int oreAcrobaticoPPL();
    int oreSoloGPL();
    int oreMasterGPL();
    int oreSoloVDS();
    int oreMasterVDS();
    bool orePPL();
    bool oreGPL();
    bool oreVDS();
    bool minAcrobPPL();
};

#endif // COMPLETE_H
