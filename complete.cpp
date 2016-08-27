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
            if((*it)->getTipo()==1)
            {
                if(!(*it)->getIstruttore() && !(*it)->getAcrobatico())
                    {oreTot=oreTot+(*it)->getMinuti();}
            }

        }
        return oreTot/60;//da minuti ad ore
}

int Complete::oreMasterPPL(){
    int oreTot=0;
    for(Complete::iterator it=begin(); it!=end(); ++it)
    {
        if((*it)->getTipo()==1)
        {
            if((*it)->getIstruttore() && !(*it)->getAcrobatico())
               {oreTot=oreTot+(*it)->getMinuti();}
        }
    }
    return oreTot/60;
}

int Complete::oreAcrobaticoPPL(){
    int oreTot=0;
    for(Complete::iterator it=begin(); it!=end(); ++it)
    {
        if((*it)->getTipo()==1)
        {
            if((*it)->getAcrobatico())
               {oreTot=oreTot+(*it)->getMinuti();}
        }
    }
    return oreTot/60;
}

int Complete::oreSoloGPL(){
    int oreTot=0;
    for(Complete::iterator it=begin(); it!=end(); ++it)
    {
        if((*it)->getTipo()==3)
        {
            if(!(*it)->getIstruttore())
                {oreTot=oreTot+(*it)->getMinuti();}
        }
    }
    return oreTot/60;
}

int Complete::oreMasterGPL(){
    int oreTot=0;
    for(Complete::iterator it=begin(); it!=end(); ++it)
    {
        if((*it)->getTipo()==3)
        {
            if((*it)->getIstruttore())
                {oreTot=oreTot+(*it)->getMinuti();}
        }
    }
    return oreTot/60;
}

int Complete::oreSoloVDS(){
    int oreTot=0;
    for(Complete::iterator it=begin(); it!=end(); ++it)
    {
        if((*it)->getTipo()==2)
        {
            if(!(*it)->getIstruttore())
                {oreTot=oreTot+(*it)->getMinuti();}
        }
    }
    return oreTot/60;
}

int Complete::oreMasterVDS(){
    int oreTot=0;
    for(Complete::iterator it=begin(); it!=end(); ++it)
    {
        if((*it)->getTipo()==2)
        {
            if((*it)->getIstruttore())
                {oreTot=oreTot+(*it)->getMinuti();}
        }
    }
    return oreTot/60;
}

bool Complete::orePPL(){
    return oreMasterPPL()>=12 && oreSoloPPL()+oreMasterPPL()>=45;
}

bool Complete::oreGPL(){
    return oreMasterGPL()>=7 && oreSoloGPL()>=4 && oreSoloGPL()+oreMasterGPL()>=13;
}

bool Complete::oreVDS(){
    return oreMasterVDS()>=16;
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
            break;
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
