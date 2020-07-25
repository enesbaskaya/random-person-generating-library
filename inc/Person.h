#ifndef PERSON_H
#define PERSON_H

#include "TC.h"
#include "Telephone.h"


//kişi yapısı
struct Person{

    //kişinin bilgileri
    TurkishRebuplic tcObject;
    Telefon telObject;
    int old;
    char* name;
    char* surName;
    //kişinin fonk. göstericisi
    void (*ekranaBilgiYaz)(struct Person*);

};
typedef struct Person* Kisi;

//kişinin fonk. prototipi
void ekranaBilgiYaz(const Kisi);
Kisi PersonMake();

#endif // !PERSON_H