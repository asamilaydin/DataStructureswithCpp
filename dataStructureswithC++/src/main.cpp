/** 
* @file main.cpp
* @description   Klasör içindeki satırları okuyup satirlar listesine ekler gerekli fonksiyonlar çağrılır, yazdir fonksiyonuyla ekrana getirilir ve sonra alınan alan bırakılır.
* @course 1.Öğretim C grubu
* @assignment 1.Ödev
* @date 23.11.2022
* @author Ahmet Şamil Aydın - ahmet.aydin21@ogr.sakarya.edu.tr
*/




#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "YoneticiListesi.hpp"

using namespace std;

int main()
{
    YoneticiListesi *yoneticiListe=new YoneticiListesi();
    ifstream file("veriler.txt");
    
    if (file.good())
    {
        string str;
        while(getline(file, str)) 
        {
            SatirlarListesi *satirlarListesi=new SatirlarListesi();
            istringstream ss(str);
            int num;
            while(ss >> num)
            {
                satirlarListesi->ekle(new Dugum(num));
            }
            satirlarListesi->ortalamaHesapla();
            yoneticiListe->listeEkle(satirlarListesi);
           
        }    
    }
   yoneticiListe->yazdir();
   delete yoneticiListe;

}