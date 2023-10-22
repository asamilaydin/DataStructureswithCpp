#ifndef YONETICILISTESI_hpp
#define YONETICILISTESI_hpp
#include "SatirlarListesi.hpp"

class YoneticiListesi
{
    public:
    int yonsay;
    SatirlarListesi *ilkListe;
    YoneticiListesi();
    ~YoneticiListesi();
    void listeEkle(SatirlarListesi*);
    void listeCikar(SatirlarListesi*);
    void yazdir();
    void yazdirsatir();
};


#endif