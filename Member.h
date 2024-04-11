#pragma once
#include "Structures.h"
using namespace System::Drawing;

class Member
{
protected:
    float size; // Elementa izmērs.
    location loc; // Elementa atrašanās vieta.
    int colorArgb; // Krāsa ARGB formātā.
public:
    Member(); // Noklusētais konstruktors.
    location getLocation(); // Atgriež elementa atrašanās vietu.
    void setLocation(int X, int Y); // Iestata elementa atrašanās vietu.
    void setSize(float newSize); // Iestata elementa izmēru.
    float getSize(); // Atgriež elementa izmēru.
    void setColor(int Argb); // Iestata elementa krāsu.
    int getColor(); // Atgriež elementa krāsu.
};