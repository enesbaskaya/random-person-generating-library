#include "IMEI.h"

bool isValidIMEI(char imei[])
{
    int total = 0;
    for (int i = 0; i < 14; i++)
    {
        int digit = charToint(imei[i]);
        if ((i % 2 == 0))
        {
            total += digit;
        }
        else
        {
            if ((digit * 2) >= 10)
            {
                int first = (digit * 2) % 10;
                int second = (int)((double)digit * 2) / (double)10;
                total += first;
                total += second;
            }
            else
            {
                total += (digit * 2);
            }
        }
    }

    int digit15 = abs(10 - ((total % 10) == 0 ? 10 : (total % 10)));
    return (digit15 == charToint(imei[14]));
}

//random IMEI üreten fonk.
IMEINO setIMEI(const IMEINO imei, const Rastgele r)
{
    //bir kısmı üretilen IMEI
    int64_t semiImei = randomLong2(r, 100000000000000, 999999999999999);
    char *eptr;
    int16_t total = 0;
    //üretilen IMEI dizi ye atılıp rakamsal değerleirin algoritmaya uygun işlemler yapıldığı kısım
    char array[15];
    sprintf(array, "%lld", semiImei);
    int16_t counter = 0;
    for (int i = 0; i < strlen(array); i++)
    {
        int32_t digit = charToint(array[i]);
        //çiftlerin toplandığı kısım
        if ((i % 2 == 0))
        {
            total += digit;
            //teklerin iki katının toplandığı kısım
        }
        else
        {
            //teklerin toplandığı kısım
            if ((digit * 2) >= 10)
            {
                int first = (digit * 2) % 10;
                int second = (int)((double)digit * 2) / (double)10;
                total += first;
                total += second;
            }
            else
            {
                total += (digit * 2);
            }
        }
    }
    //IMEI algoritmasına göre son hanenin bulunması
    int digit15 = abs(10 - ((total % 10) == 0 ? 10 : (total % 10)));
    char buffer[2];
    itoa(digit15, buffer, 10);
    array[14] = buffer[0];
    //IMEI tam hali
    imei->imei = strtoll(array, &eptr, 10);
    char imeiX[256];
    sprintf(imeiX, "%lld", imei->imei);
    if (isValidIMEI(imeiX))
        return imei;
    else
        return setIMEI(imei, r);
}
//üretilen IMEI döndürür
int64_t getIMEI(const IMEINO imei)
{
    return imei->imei;
}
