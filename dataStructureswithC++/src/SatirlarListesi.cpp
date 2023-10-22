/** 
* @file Dugum.cpp
* @description   Satırlar Listesi oluşturuldu(ekle fonk. ,çıkar fonk, rand sil fonk, ortalama hesapla fonk, yazdır fonk,)
* @course 1.Öğretim C grubu
* @assignment 1.Ödev
* @date 23.11.2022
* @author Ahmet Şamil Aydın - ahmet.aydin21@ogr.sakarya.edu.tr
*/

#include "SatirlarListesi.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

SatirlarListesi::SatirlarListesi()
{
    this->ilk=0;
    this->sayac=0;
    this->ortalama=0;
    this->oncekiListe=0;
    this->sonrakiListe=0;
}

void SatirlarListesi::ekle(Dugum *eklenecekDugum)
{
    if(ilk==0)
    {
        ilk = eklenecekDugum;
        sayac++;
    }
    else
    {
        Dugum* gec = ilk;

        while(gec->sonraki!=0)
        {
            gec=gec->sonraki;
        }

        gec->sonraki = eklenecekDugum;
        eklenecekDugum->onceki = gec;
        sayac++;
    }
}


void SatirlarListesi::sil()
{
    if(ilk==0)
        return;
    int randomDugum=rand()%sayac;
    Dugum *gec=ilk;

    for(int i=0;i<randomDugum;i++)
    {
        gec=gec->sonraki;
    }

    if(gec==ilk)
    {
        if(ilk->sonraki!=0)
        {
            gec->sonraki->onceki=0;
            ilk=gec->sonraki;
            delete gec;
            sayac--;
        }
        else
        {
            delete gec;
            sayac--;
        } 
    }

    else if(gec->sonraki==0)
    {
        gec->onceki->sonraki=0;
        delete gec;
        sayac--;
    }

    else 
    {
        gec->onceki->sonraki=gec->sonraki;
        gec->sonraki->onceki=gec->onceki;
        delete gec;
        sayac--;
    }
}

void SatirlarListesi::ortalamaHesapla()
{
    Dugum *gec=ilk;
    float toplam=0;
    for(int i=0;i<sayac;i++)
    {
        toplam+=gec->veri;
        gec=gec->sonraki;
    }
    this->ortalama=toplam/sayac;
}

void SatirlarListesi::yazdir(int sira,int a1, int a2 ,int aralik)
{
    Dugum *gec=ilk;
    int sayacSD=0;
    cout<<setw(sira*10)<<""<<"^^^^^^^^"<<endl;
     while(gec!=0)
    {   
      if(aralik>=a1&&aralik<=a2)
        {
            
            cout<<setw(sira*10)<<""<<gec<<endl;
            cout<<setw(sira*10)<<""<<"--------"<<endl;
            cout<<setw(sira*10)<<""<<gec->veri<<endl;
            cout<<setw(sira*10)<<""<<"--------"<<endl;
            cout<<setw(sira*10)<<""<<gec->sonraki<<endl;  
            cout<<setw(sira*10)<<""<<"--------"<<endl;         
        }
        cout<<endl; 
       
        gec=gec->sonraki;
        
    }
   
}

SatirlarListesi::~SatirlarListesi()
{
    Dugum* gec =ilk;
    while(gec!=0)
    {
        Dugum* silinecek = gec;
        gec=gec->sonraki;
        delete silinecek;
    }
}