#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include "Person.h"

int main()
{
    system("color a");
    system("cls");
    setlocale(LC_ALL, "Turkish");
    printf("Lütfen bir seçenek giriniz...\n");
    printf("1(a)- Rastgele kişi üret.\n");
    printf("2(b)- Üretilenleri kontrol et.\n");
    printf("3(c)- Çıkış yap.\n");

    char get = getch();
    if (get == 'a' || 1 == charToint(get))
    {
        system("cls");
        printf("Lutfen kac kisi uretilmesi gerektigini giriniz: ");
        char string[256];
        scanf("%s", string);
        int count = atoi(string);
        FILE *file = fopen("kisiler.txt", "w");
        FILE *readFile = fopen("randomisimler.txt", "r");
        for (int i = 0; i < count; i++)
        {
            char str[1000];
            if (fgets(str, 1000, readFile) != NULL)
            {
                char *token = strtok(str, " ");
                char name[100];
                char surName[100];
                int j = 0;
                while (token != NULL && j < 2)
                {
                    if (j == 0)
                        strcpy(name, token);
                    else
                        strcpy(surName, token);
                    j++;
                    token = strtok(NULL, " ");
                }

                if (name != NULL && surName != NULL)
                {
                    Kisi kisi = PersonMake();
                    kisi->name = name;
                    kisi->surName = strtok(surName, "\n");
                    char tc[256];
                    char tel[256];
                    char imei[256];
                    sprintf(tc, "%lld", kisi->tcObject->tc);
                    sprintf(tel, "%lld", kisi->telObject->telNo);
                    sprintf(imei, "%lld", kisi->telObject->imeiObject->imei);
                    char *x = malloc(200 * sizeof(char));
                    sprintf(x, "%s %s %s %d %s %s%s%s%s", tc, name, surName, kisi->old, tel, "(", imei, ")", "\n");
                    fputs(x, file);
                    free(kisi->tcObject);
                    free(kisi->telObject);
                    free(kisi->telObject->imeiObject);
                    free(kisi);
                    free(x);
                }
            }
            float percentage = (i / (float)count) * 100;
            system("cls");
            system("color b");
            printf("Kisiler olusturuluyor... %% %f \n", percentage);
        }
        fclose(file);
        system("cls");
        system("color 7");
        printf("Kisiler yazdirildi!");
    }
    else if (get == 'b' || 2 == charToint(get))
    {
        int correctTC = 0;
        int correctIMEI = 0;
        int unCorrectIMEI = 0;
        int unCorrectTC = 0;
        FILE *readFile = fopen("kisiler.txt", "r");
        char str[1000];
        while (fgets(str, 1000, readFile) != NULL)
        {
            char *token = strtok(str, " ");
            char tc[100];
            char imei[100];
            int j = 0;
            while (token != NULL)
            {
                if (j == 0)
                    strcpy(tc, token);
                else if (j == 5)
                    strcpy(imei, token);
                j++;
                token = strtok(NULL, " ");
            }
            if (isValidTC(tc))
                correctTC++;
            else
                unCorrectTC++;

            if (isValidIMEI(strtok(strtok(imei, "("), ")")))
                correctIMEI++;
            else
                unCorrectIMEI++;
        }
        system("cls");
        printf("Gecerli TC Sayisi: %d\n", correctTC);
        printf("Gecerli IMEI Sayisi: %d\n", correctIMEI);

        printf("Gecersiz TC Sayisi: %d\n", unCorrectTC);
        printf("Gecersiz IMEI Sayisi: %d", unCorrectIMEI);
        fclose(readFile);
    }
    else if (get == 'c' || 3 == charToint(get))
    {
        return 0;
    }

    return 0;
}
