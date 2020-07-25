#include "Person.h"

void ekranaBilgiYaz(const Kisi per)
{
    int64_t tc = getTC(per->tcObject);
    int64_t tel = getTelephone(per->telObject);
    int64_t imei = getIMEI(per->telObject->imeiObject);
    printf("TC: %llu", tc);
    printf("Tel: %llu", tel);
    printf("IMEI: %llu", imei);
}

Kisi PersonMake()
{

    Kisi person;
    Rastgele r;
    TurkishRebuplic tc;
    Telefon tel;
    IMEINO imei;

    tel = (Telefon)malloc(sizeof(struct Telephone));
    tc = (TurkishRebuplic)malloc(sizeof(struct TC));
    r = (Rastgele)malloc(sizeof(struct Random));
    person = (Kisi)malloc(sizeof(struct Person));
    imei = (IMEINO)malloc(sizeof(struct IMEI));
    person->old = randomInt(r, 100);
    person->tcObject = setTC(tc, r);
    person->telObject = setTelephone(tel, r);
    person->telObject->imeiObject = setIMEI(imei, r);
    free(r);

    return person;
}