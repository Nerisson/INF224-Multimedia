
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

    m->createPhoto("Photo1", "PathPhoto1", 20, 20);
    m->createVideo("Video1", "PathVideo1", 800);
    
    
    delete m;
    
    return 0;
}

