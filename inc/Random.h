#ifndef RANDOM_H
#define RANDOM_H
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

static int64_t constantMultiplier = 2;

//random yapısı
struct Random
{   
    
    int64_t currentTimems;
    int64_t nanoTime;
    int64_t randomValue;
    //random fonk. göstericileri
    void (*createRandom)(struct Random*);
    int (*randomInt)(struct Random*);
    int (*randomInt2)(struct Random*, int);
    int64_t (*randomLong)(struct Random*);
    int64_t (*randomLong1)(struct Random*,int64_t);
    int64_t (*randomLong2)(struct Random*, int64_t, int64_t);
};
typedef struct Random* Rastgele;

//random fonk. prototipleri
void createRandom(const Rastgele);

int randomInt(const Rastgele,int);

int randomInt2(const Rastgele);

int randomInt3(const Rastgele,  int,  int);

int64_t randomLong(const Rastgele);

int64_t randomLong1(const Rastgele,int64_t);

int64_t randomLong2(const Rastgele, int64_t, int64_t);

int64_t modAl(int64_t, int64_t);

int* toArray(int);

int charToint(char);

char* convertNumberIntoArray(int32_t);


#endif // !RANDOM_H