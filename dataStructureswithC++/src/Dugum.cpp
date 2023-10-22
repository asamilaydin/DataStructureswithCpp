/** 
* @file Dugum.cpp
* @description   Dugum verileri tanımlandı(veri,önceki,sonraki).
* @course 1.Öğretim C grubu
* @assignment 1.Ödev
* @date 23.11.2022
* @author Ahmet Şamil Aydın - ahmet.aydin21@ogr.sakarya.edu.tr
*/

#include "Dugum.hpp"
#include <iostream>

Dugum::Dugum(int veri)
{
    this->veri=veri;
    onceki=sonraki=0;
}
