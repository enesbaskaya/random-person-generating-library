#include "TC.h"

bool isValidTC(char tc[])
{

    int doubles = 0;
    int single = 0;

    //çift ve tek değerlerin toplandığı bölüm
    for (int i = 0; i < 9; i++)
    {
        int value = charToint(tc[i]);
        if (i % 2 == 0)
        {
            single += value;
        }
        else
        {
            doubles += value;
        }
    }

    int digit9 = ((doubles * 7) - single) % 10;
    int digit10 = (doubles + single + digit9) % 10;
    return (digit9 == charToint(tc[9]) && digit10 == charToint(tc[10]));
}

//random TC üreten fonk.
TurkishRebuplic setTC(const TurkishRebuplic tc, const Rastgele r)
{
    //üretilen random TC
    tc->tc = randomLong2(r, 100000000, 999999999);
    char tcS[11];
    char *eptr;
    sprintf(tcS, "%lld", tc->tc);
    int doubles = 0;
    int single = 0;

    //çift ve tek değerlerin toplandığı bölüm
    for (int i = 0; i < strlen(tcS); i++)
    {
        int value = charToint(tcS[i]);
        if (i % 2 == 0)
        {
            single += value;
        }
        else
        {
            doubles += value;
        }
    }

    //TC algoritmasına göre diğer hanelerin bulunması
    int digit10 = ((doubles * 7) - single) % 10;
    int digit11 = (doubles + single + digit10) % 10;

    char buffer[2];
    char tuffer[2];

    itoa(abs(digit10), buffer, 10);
    tcS[9] = buffer[0];

    itoa(abs(digit11), tuffer, 10);
    tcS[10] = tuffer[0];

    tc->tc = strtoll(tcS, &eptr, 10);
    char tcX[256];
    sprintf(tcX, "%lld", tc->tc);
    if (isValidTC(tcX))
        return tc;
    else
        return setTC(tc, r);
}
//üretilen IMEI döndürür
int64_t getTC(const TurkishRebuplic tc)
{
    return tc->tc;
}