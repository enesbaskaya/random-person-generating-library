#include "Random.h"

//matematiksel işlemler ve time kütüphanesi ile random değerlerimi ürettiğimiz fonk.
void createRandom(const Rastgele r)
{

    r->currentTimems = time(0) * sin((constantMultiplier % 45) + 1);
    r->randomValue = (r->currentTimems * r->currentTimems) - (sin((constantMultiplier) + 1) * r->currentTimems) + (cos((constantMultiplier) + 9) * r->currentTimems);
    r->randomValue = r->randomValue < 0 ? -r->randomValue : r->randomValue;

    constantMultiplier++;
}

//int ve long random döndüren fonk.

int randomInt(const Rastgele r, int a)
{
    createRandom(r);
    int abs = r->randomValue % a < 0 ? -(r->randomValue % a) : r->randomValue % a;
    return (int)abs;
}

int randomInt2(const Rastgele r)
{
    createRandom(r);
    int abs = (r->randomValue % 2147483647 > 0 ? r->randomValue % 2147483647 : -(r->randomValue % 2147483647));
    return (int)abs;
}

int randomInt3(const Rastgele r, int a, int b)
{
    createRandom(r);
    int abs = a - b > 0 ? a - b : -(a - b);
    return (a + (modAl(r->randomValue, abs)));
}

int64_t randomLong(const Rastgele r)
{
    createRandom(r);
    return r->randomValue;
}

int64_t randomLong1(const Rastgele r, int64_t a)
{
    createRandom(r);
    return r->randomValue % a;
}

int64_t randomLong2(const Rastgele r, int64_t a, int64_t b)
{
    createRandom(r);
    int64_t abs = a - b > 0 ? a - b : -(a - b);
    return (a + (modAl(r->randomValue, abs)));
}

int64_t modAl(int64_t bolunen, int64_t bolen)
{
    double carpan = (double)bolunen / (double)bolen;
    double oran = carpan - ((int)(carpan));
    return oran * bolen;
}

int *toArray(int number)
{
    int n = log10(number) + 1;
    int i;
    int *numberArray = calloc(n, sizeof(int));
    for (i = 0; i < n; ++i, number /= 10)
    {
        numberArray[i] = number % 10;
    }
    return numberArray;
}

int charToint(char a)
{
    char *p = &a;
    int k = atoi(p);
    return k;
}

char *convertNumberIntoArray(int32_t number)
{
    unsigned int length = (int)(log10((float)number)) + 1;
    char *arr = (char *)malloc(length * sizeof(char)), *curr = arr;
    do
    {
        *curr++ = number % 10;
        number /= 10;
    } while (number != 0);
    return arr;
}
