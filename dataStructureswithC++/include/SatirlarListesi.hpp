#ifndef SATIRLARLISESI_hpp
#define SATIRLARLISESI_hpp
#include "Dugum.hpp"

class SatirlarListesi
{
    private:
    Dugum* ilk;
    public:
    SatirlarListesi *oncekiListe;
    SatirlarListesi *sonrakiListe;
    int sayac;
    float ortalama;
    SatirlarListesi();
    ~SatirlarListesi();
    void ortalamaHesapla();
    void ekle(Dugum*);
    void sil();
    void yazdir(int,int,int,int);

};
#endif