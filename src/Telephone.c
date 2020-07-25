#include "Telephone.h"

char* dizileri_birlestir(char dizi_1[], int boyut_1, 
			 char dizi_2[], int boyut_2, 
			 char sonuc[]){
	int i, k;
	
	for( i = 0; i < boyut_1; i++ ) 
		sonuc[i] = dizi_1[i];

	for( k = 0; k < boyut_2; i++, k++ ) {
		sonuc[i] = dizi_2[k];
	}
	return sonuc;
}

//telefon numarasının üretildiği fonk.
Telefon setTelephone(const Telefon tel, const Rastgele r)
{
    //alan doklarının seçildiği kısım
    char *telNo;
    char *telNoFirst[3];
    char *telNoLast[7];
    char *s[10];
    int index = array[abs(randomInt(r, 31))];
    int64_t index_2 = randomLong2(r, 1000000, 9999999);
    sprintf(telNoFirst, "%d", index);
    sprintf(telNoLast, "%lld", index_2);

    telNo = dizileri_birlestir(telNoFirst,3, telNoLast,7,s);
    
    char *eptr;

    tel->telNo = strtoll(telNo, &eptr, 10);
    return tel;
}

//üretilen telefon numarası değerini döndürür
int64_t getTelephone(const Telefon tel)
{
    return tel->telNo;
}