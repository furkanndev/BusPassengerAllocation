#include <stdio.h>
#include <stdlib.h>


struct Passenger
{
    char ad[50];
    char soyad[50];
    int yolcu_no;
};

struct Otobus
{
    struct Passenger otobus_yolculari[8];
    int yolcu_sayisi;
    struct Otobus *next;
    int otobus_no;  
};

int guncel_yolcu_sayisi = 0;
int guncel_otobus_sayisi = 0;

struct Otobus *ilk_otobus = NULL;
struct Passenger yolcular[64];


void otobus_olustur()
{

    struct Otobus *temp;
    temp = calloc(sizeof(struct  Otobus), 1);
    temp -> yolcu_sayisi = 0;
    temp ->next =NULL;
    temp ->otobus_no = guncel_otobus_sayisi + 1;

    if(guncel_otobus_sayisi == 0)
    {


        ilk_otobus = temp;
    }
    else
    {
        struct Otobus *p;
        p = ilk_otobus;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;

    }
    guncel_otobus_sayisi++;

}




void ekle()
{

    struct Otobus *p;
    p = ilk_otobus;
    printf("Yolcu Adi: ");
    scanf("%s",yolcular[guncel_yolcu_sayisi].ad);
    printf("Yolcu Soyadi: ");
    scanf("%s",yolcular[guncel_yolcu_sayisi].soyad);
    yolcular[guncel_yolcu_sayisi].yolcu_no = guncel_yolcu_sayisi % 8 + 1;
    while (p->next != NULL)
    {
        p = p->next;
    }
    if(p->yolcu_sayisi == 8)
    {
        printf("Yeni otobus olusturuluyor.... Lutfen Bekleyin....\n");
        otobus_olustur();
    }
    while (p->next != NULL)
    {
        p = p->next;
    }
    p-> otobus_yolculari[yolcular[guncel_yolcu_sayisi].yolcu_no-1] = yolcular[guncel_yolcu_sayisi];
    p-> yolcu_sayisi++;
    guncel_yolcu_sayisi ++;

}



void yazdir()
{

    struct Otobus *p;
    p = ilk_otobus;
    while (p)
    {
        printf("\n************** %d.Otobus *************\n", p->otobus_no);

        for(int i = 0 ; i< p->yolcu_sayisi ; i++)
        {

            printf("%d nolu yolcu - Yolcu Adi: %s - Yolcu Soyadi: %s\n",p->otobus_yolculari[i].yolcu_no,p->otobus_yolculari);
        }
        printf("\n");
        p = p -> next;


    }
    printf("\n");
    


}



int main()
{

    int islem;
    int i = 1;
    otobus_olustur();

    while (i)
    {
        printf("(1) Add Passenger\n");
        printf("(2) Print Passenger\n");
        printf("(0) Exit \n");

        scanf("%d", &islem);
        switch (islem)
        {
        case 1:
        ekle();
            break;
        case 2 :
        yazdir();
        break;
        case 0 :
        i = 0;
        break;
        default:
            printf("Wrong Selection!");
            break;
        }



    }
    







}