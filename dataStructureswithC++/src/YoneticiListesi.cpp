/** 
* @file Dugum.cpp
* @description   yonteici listesi olusturuldu(liste ekle fonk, liste cikar fonk, yazdır fonk).
* @course 1.Öğretim C grubu
* @assignment 1.Ödev
* @date 23.11.2022
* @author Ahmet Şamil Aydın - ahmet.aydin21@ogr.sakarya.edu.tr
*/



#include "YoneticiListesi.hpp"
#include "SatirlarListesi.hpp"
#include <iostream>
#include <iomanip>
using namespace std;


YoneticiListesi::YoneticiListesi()
{
    this->ilkListe=0;
    this->yonsay=0;
    
}

void YoneticiListesi::listeEkle(SatirlarListesi *eklenecekListe)
{
    if(this->ilkListe==0)
    {
        this->ilkListe=eklenecekListe;
        yonsay++;
    }
    else if(this->ilkListe->sonrakiListe==0)
    {
        if(eklenecekListe->ortalama<ilkListe->ortalama)
        {
            eklenecekListe->sonrakiListe=ilkListe;
            ilkListe->oncekiListe=eklenecekListe;
            ilkListe=eklenecekListe;
            yonsay++;
        }
        else 
        {
            ilkListe->sonrakiListe=eklenecekListe;
            eklenecekListe->oncekiListe=ilkListe;
            yonsay++;
        }
    }
    else 
    {
        SatirlarListesi *gec=ilkListe;
        while (gec->sonrakiListe!=0)
        {
            if(eklenecekListe->ortalama<gec->ortalama)
            {
                if(gec==ilkListe)
                {
                    eklenecekListe->sonrakiListe=ilkListe;
                    ilkListe->oncekiListe=eklenecekListe;
                    ilkListe=eklenecekListe;
                    yonsay++;
                    return;
                }
                else
                {
                    eklenecekListe->sonrakiListe=gec;
                    eklenecekListe->oncekiListe=gec->oncekiListe;
                    gec->oncekiListe->sonrakiListe=eklenecekListe;
                    gec->oncekiListe=eklenecekListe;
                    yonsay++;
                    return;
                }
            }
            gec=gec->sonrakiListe;
        }

        if(gec->ortalama>eklenecekListe->ortalama)
        {
            eklenecekListe->sonrakiListe=gec;
            eklenecekListe->oncekiListe=gec->oncekiListe;
            gec->oncekiListe->sonrakiListe=eklenecekListe;
            gec->oncekiListe=eklenecekListe;
            yonsay++;
        }
        else
        {
            gec->sonrakiListe=eklenecekListe;
            eklenecekListe->oncekiListe=gec;
            yonsay++;
        }
    }
}

void YoneticiListesi::listeCikar(SatirlarListesi *silinecekListe)
{
    if(silinecekListe->sonrakiListe==0)
    {
        if(silinecekListe==ilkListe)
            delete silinecekListe;
        else
        {
            silinecekListe->oncekiListe->sonrakiListe=0;
            delete silinecekListe;
        }
    }
    else if(silinecekListe==ilkListe)
    {
        ilkListe->sonrakiListe->oncekiListe=0;
        ilkListe=ilkListe->sonrakiListe;
        delete silinecekListe;
    }
    else
    {
        silinecekListe->oncekiListe->sonrakiListe=silinecekListe->sonrakiListe;
        silinecekListe->sonrakiListe->oncekiListe=silinecekListe->oncekiListe;
        delete silinecekListe;
    }
    
}

void YoneticiListesi::yazdir()
{    
     int index=0;
     int sno=0;
     int sonSayfa=yonsay/8;
     int a1,a2;
     int araliks=0;
     SatirlarListesi* gec =ilkListe;
     SatirlarListesi* yazdirilacak=ilkListe;
   
     
    while (true)
     { 

        a1=sno*8;
        a2=(sno*8)+7;



        system("cls");
        if(sno==0)
         cout<<"ilk"<<setw(75)<<"--->"<<endl;
        else if (sno>0&&sno<sonSayfa)
        {
           cout<<"<---"<<setw(75)<<"--->"<<endl;
        }
        else
        cout<<"<---"<<setw(75)<<"son"<<endl;
        
      
    int sayacYD=0;
    while(gec!=0)
    {   
        if(sayacYD>=a1&&sayacYD<=a2)
        {
            cout<<setw(8)<<gec<<"  ";           
        }
        sayacYD++;
        gec=gec->sonrakiListe;
        
    }
     cout<<endl;
     gec =ilkListe;
      sayacYD=0;
     while(gec!=0)
    {   
        if(sayacYD>=a1&&sayacYD<=a2)
        {
         cout<<"--------  ";
        }
         
        sayacYD++;
        gec=gec->sonrakiListe;
     }   

     cout<<endl;
     gec =ilkListe;
      sayacYD=0;
    while(gec!=0)
    {   
        if(sayacYD>=a1&&sayacYD<=a2)
        {
            cout<<setw(8)<<gec->oncekiListe<<"  ";
        }
        sayacYD++;
            gec=gec->sonrakiListe;
        
    }
      cout<<endl;
     gec =ilkListe;
      sayacYD=0;
     while(gec!=0)
    {   
        if(sayacYD>=a1&&sayacYD<=a2)
        {
         cout<<"--------  ";
        }
         
        sayacYD++;
        gec=gec->sonrakiListe;
     }   

     cout<<endl;
     gec =ilkListe;
      sayacYD=0;
      while(gec!=0)
    {   
        if(sayacYD>=a1&&sayacYD<=a2)
        {
            cout<<setw(8)<<gec->ortalama<<"  ";
        }
        sayacYD++;
            gec=gec->sonrakiListe;
        
    }
      cout<<endl;
     gec =ilkListe;
      sayacYD=0;
     while(gec!=0)
    {   
        if(sayacYD>=a1&&sayacYD<=a2)
        {
         cout<<"--------  ";
        }
         
        sayacYD++;
        gec=gec->sonrakiListe;
     }   

      cout<<endl;
      gec =ilkListe;
       sayacYD=0;
    while(gec!=0)
    {   
        if(sayacYD>=a1&&sayacYD<=a2)
        {
            cout<<setw(8)<<gec->sonrakiListe<<"  ";
        }
        sayacYD++;
            gec=gec->sonrakiListe;
        
    }
      cout<<endl;
      gec =ilkListe;
      sayacYD=0;
     while(gec!=0)
    {   
        if(sayacYD>=a1&&sayacYD<=a2)
        {
         cout<<"--------  ";
        }
         
        sayacYD++;
        gec=gec->sonrakiListe;
        
     }   
      
     cout<<endl<<endl;
      gec =ilkListe;
     
         
    yazdirilacak->yazdir(index,a1,a2, araliks);
    char ch;
    cin>>ch;
    
         if(ch=='c')
            
         {  
            if(sno==sonSayfa)
            {
                index++;
                if(yazdirilacak->sonrakiListe==0){
                yazdirilacak=yazdirilacak->oncekiListe;
                index--;}
                yazdirilacak=yazdirilacak->sonrakiListe;

            }
            else 
           {
            if(index<7) 
             { index++;
           
              yazdirilacak=yazdirilacak->sonrakiListe;
              
             }
             else
             {
               if(sno<sonSayfa)
              {
               
                sno++;
                araliks=sno*8;
                index=0;
                yazdirilacak=ilkListe;
                for(int i=0;i<=a2;i++)
                {
                    yazdirilacak=yazdirilacak->sonrakiListe;
                }
              
              }
             }
           
           }
     
         }
        
         if(ch=='z')
         {
          if (index>0)
              {  index--;
              yazdirilacak=yazdirilacak->oncekiListe;
              }
               
           else
           {
            if(sno>0)
            {   
                sno--;
                araliks=sno*8;
                index=7;
                yazdirilacak=yazdirilacak->oncekiListe;
          
            }
           }    
         }
         if(ch=='a')
         {
            if(sno>0)
            {   
                sno--;
                araliks=sno*8;
                index=0;
                 yazdirilacak=ilkListe;
                for(int i=0;i<araliks;i++)
                {
                   yazdirilacak=yazdirilacak->sonrakiListe;
                }
                
            }
         }

         if(ch=='d')
         {  
            if(sno<sonSayfa)
            {
               
                sno++;
                araliks=sno*8;
                index=0;
                yazdirilacak=ilkListe;
                for(int i=0;i<=a2;i++)
                {
                    yazdirilacak=yazdirilacak->sonrakiListe;
                }
              
            }
        }

    }
    

    
}

YoneticiListesi::~YoneticiListesi()
{
    SatirlarListesi *gec=ilkListe;
    while(gec!=0)
    {
        SatirlarListesi *silinecek = gec;
        gec=gec->sonrakiListe;
        delete silinecek;
    }
}