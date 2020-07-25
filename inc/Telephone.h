#ifndef TELEPHONE_H
#define TELEPHONE_H 
#include "IMEI.h"

//alan kodları
static int array[]= {501,505,506,507,551,552,553,554,555,559,530,531,532,533,534,535,536,537,538,539,561,540,541,543,544,545,546,547,548,549,542};

struct Telephone
{
    IMEINO imeiObject;
    int64_t telNo;
    //telefon fonk. göstericileri
    void (*setTelephone)(struct Telephone*, struct Random*);
    int64_t (*getTelephone)(struct Telephone*);
};
typedef struct Telephone* Telefon;

//telefon fonk. prototipleri
Telefon setTelephone(const Telefon, const Rastgele);
int64_t getTelephone(const Telefon);

#endif // !TELEPHONE_H