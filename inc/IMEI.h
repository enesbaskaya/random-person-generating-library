#ifndef IMEI_H
#define IMEI_H

#include "Random.h"

//IMEI yapısı
struct IMEI
{
    int64_t imei;
    // IMEI'nin fokn göstericileri
    void (*setIMEI)(struct IMEI*, struct Random*);
    int64_t (*getIMEI)(struct IMEI*);
};
typedef struct IMEI* IMEINO;

bool isValidIMEI(char[]);

// IMEI'nin fonk. prototipleri
IMEINO setIMEI(const IMEINO, const Rastgele);

int64_t getIMEI(const IMEINO);

#endif