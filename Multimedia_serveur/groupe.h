#ifndef GROUPE_H
#define GROUPE_H

#include <list>
#include <string>
#include <memory>
#include <algorithm>

#include "multimedia.h"

using namespace std;

typedef std::shared_ptr<Multimedia> sp_Multimedia;

class Groupe:public list<sp_Multimedia> {

    private:
        string name;

    public:
        Groupe(){}
        Groupe(string nom) : name(nom){}
        virtual string getNom() const;
        virtual void affiche(ostream& ostream) const;
        virtual ~Groupe(){}
        
        void removeMultimedia(string _nom);
        void executerGroupe() const;
};

#endif // GROUPE_H
