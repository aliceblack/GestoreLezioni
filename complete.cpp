#include "complete.h"

Complete::Complete(){}

void Complete::add(Lezione* x){
    lezioniComp.push_back(x);
}

Complete::iterator::iterator(){}

Complete::iterator::iterator(Lezione ** x) : punt(x) {}

Complete::iterator::iterator(const iterator& cit) : punt(cit.punt) {}

Lezione* Complete::iterator::operator*(){
    return *punt;
}

Complete::iterator& Complete::iterator::operator++(){//prefisso
     ++punt;
    return *this;
}

Complete::iterator Complete::iterator::operator++(int){
    iterator aux(*this); operator++(); return aux;
}

bool Complete::iterator::operator==(const iterator cit) {return punt==cit.punt;}

bool Complete::iterator::operator!=(const iterator cit) {return punt!=cit.punt;}

Lezione* Complete::operator[](Complete::iterator it){
    return *it;
}

Lezione* Complete::operator[](vector<Lezione*>::iterator it){
    return *it;
}

Lezione* Complete::operator[](int i){
    return lezioniComp[i];
}

Complete::iterator Complete::begin(){
    iterator aux;
    aux.punt=&(*lezioniComp.begin());
    return aux;
}

Complete::iterator Complete::end(){
    iterator aux;
    aux.punt=&(*lezioniComp.end());
    return aux;
}

int Complete::oreSoloPPL(){
    int oreTot=0;
    for(Complete::iterator it=begin(); it!=end(); ++it)
    {

        PPL* p=dynamic_cast<PPL*>(*it);
        if(p && !p->getIstruttore() && !p->getAcrobatico())
            {oreTot=oreTot+p->getMinuti();}
    }
    return oreTot/60;//da minuti ad ore
}

int Complete::oreMasterPPL(){
    int oreTot=0;
    for(Complete::iterator it=begin(); it!=end(); ++it)
    {
        PPL* p=dynamic_cast<PPL*>(*it);
        if(p && p->getIstruttore() && !p->getAcrobatico())
           {oreTot=oreTot+p->getMinuti();}
    }
    return oreTot/60;
}

int Complete::oreAcrobaticoPPL(){
    int oreTot=0;
    for(Complete::iterator it=begin(); it!=end(); ++it)
    {
        PPL* p=dynamic_cast<PPL*>(*it);
        if(p && p->getAcrobatico())
           {oreTot=oreTot+p->getMinuti();}
    }
    return oreTot/60;
}

int Complete::oreSoloGPL(){
    int oreTot=0;
    for(Complete::iterator it=begin(); it!=end(); ++it)
    {

        GPL* g=dynamic_cast<GPL*>(*it);
        if(g && !g->getIstruttore())
            {oreTot=oreTot+g->getMinuti();}
    }
    return oreTot/60;
}

int Complete::oreMasterGPL(){
    int oreTot=0;
    for(Complete::iterator it=begin(); it!=end(); ++it)
    {

        GPL* g=dynamic_cast<GPL*>(*it);
        if(g && g->getIstruttore())
            {oreTot=oreTot+g->getMinuti();}
    }
    return oreTot/60;
}

int Complete::oreSoloVDS(){
    int oreTot=0;
    for(Complete::iterator it=begin(); it!=end(); ++it)
    {

        VDS* v=dynamic_cast<VDS*>(*it);
        if(v && !v->getIstruttore())
            {oreTot=oreTot+v->getMinuti();}
    }
    return oreTot/60;
}

int Complete::oreMasterVDS(){
    int oreTot=0;
    for(Complete::iterator it=begin(); it!=end(); ++it)
    {

        VDS* v=dynamic_cast<VDS*>(*it);
        if(v && v->getIstruttore())
            {oreTot=oreTot+v->getMinuti();}
    }
    return oreTot/60;
}

bool Complete::orePPL(){
    return oreMasterPPL() && oreSoloPPL();
}

bool Complete::oreGPL(){
    return oreMasterGPL() && oreSoloGPL();
}

bool Complete::oreVDS(){
    return oreMasterVDS() && oreSoloVDS();
}

bool Complete::minAcrobPPL(){
    return oreAcrobaticoPPL()>=10;
}

void Complete::remove(int idLez){
    for(vector<Lezione*>::iterator it=lezioniComp.begin(); it!=lezioniComp.end(); ++it)
    {
        if( (*it)->getId()==idLez )
        {
            lezioniComp.erase(it);
        }
    }
}

void Complete::paga(int idLez){
    for(Complete::iterator it=begin(); it!=end(); ++it)
    {
        if( (*it)->getId()==idLez )
        {
            (*it)->setPagata();
        }
    }

}
