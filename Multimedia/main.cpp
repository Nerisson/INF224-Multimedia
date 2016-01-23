
#include<memory>


#include "multimedia.h"
#include "video.h"
#include "photo.h"
#include "film.h"
#include "groupe.h"
#include "mapmultimedia.h"

typedef std::shared_ptr<Multimedia> sp_Multimedia;

int main(int argc, char *argv[]){

    cout << endl;

    Video* v = new Video("Joe", "./VIDE0011.webm", 87);
    v->affiche(cout);

    cout << endl;

    Photo* p = new Photo("Bill", "./IMGP5539.JPG", 48.85, 2.34);
    p->affiche(cout);

    //v->executer();

    cout << endl;



    Film* f = new Film("Joe", "./VIDE0011.webm", 87);
    f->affiche(cout);
    cout << endl;
    unsigned int* d = new unsigned int[4]{1, 2, 3, 4};

    f->setChapters(d, 4);
    f->affiche(cout);

    cout << endl;

//    Multimedia* fm = f;
//    Multimedia* pm = p;

    sp_Multimedia fm(f);
    sp_Multimedia pm(p);

    Groupe* g = new Groupe("Hey!");
    g->push_back(fm);
    g->push_back(pm);
    g->affiche(cout);
    Groupe* g2 = new Groupe("Ho!");
    g2->push_back(fm);
    g2->affiche(cout);


    delete v;
//    delete p;
//    delete f;
    delete[] d;
    delete g2;
    delete g;



    
    MapMultimedia* m = new MapMultimedia();

    sp_Multimedia p2 = m->createPhoto("Photo1", "PathPhoto1", 20, 20);
    m->createVideo("Video1", "PathVideo1", 800);
    m->createVideo("Film1", "PathFilm1", 1800);
    
    sp_Groupe g21 = m->createGroupe("Group1");
    sp_Groupe g22 = m->createGroupe("Group2");
    sp_Groupe g23 = m->createGroupe("Group3");
    
    g21->push_back(p2);
    g22->push_back(p2);
    g23->push_back(p2);
    
    
    auto toto = m->findMultimedia("Film1");
    if(toto != NULL){
        cout << "################" << endl;
        toto->affiche(cout);
        cout << "################" << endl;
    } else {
        cout << "################" << endl;
        cout << "not found" << endl;
        cout << "################" << endl;
    }
    g21->affiche(cout);
    g22->affiche(cout);
    g23->affiche(cout);
    m->deleteMultimedia("Film1");
    g21->affiche(cout);
    g22->affiche(cout);
    g23->affiche(cout);
    auto toto2 = m->findMultimedia("Film1");
    if(toto2 != NULL){
        cout << "################" << endl;
        toto->affiche(cout);
        cout << "################" << endl;
    } else {
        cout << "################" << endl;
        cout << "not found" << endl;
        cout << "################" << endl;
    }
    
    delete m;
    
    return 0;
}

