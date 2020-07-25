#ifndef TC_H
#define TC_H 
#include "Random.h"

//TC yapısı

struct TC
{
    int64_t tc;
    //tc fonk. göstercileri
    void (*setTC)(struct TC*, struct Random*);
    int64_t (*getTC)(struct TC*);
};
typedef struct TC* TurkishRebuplic;


bool isValidTC(char[]);
//TC fonk. prototipleri
TurkishRebuplic setTC(const TurkishRebuplic, const Rastgele);

int64_t getTC(const TurkishRebuplic);

#endif