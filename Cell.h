#pragma once
#include "Member.h"
using namespace System::Drawing;

class Cell : public Member
{
private:
    int ID; // Šūnas identifikators.
    int controlButtonID; // Kontroļpogas identifikators, kam pieder šī šūna.
    int value; // Šūnas vērtība.
public:
    Cell(); // Konstruktors.
    void setControlButtonID(int btnID); // Funkcija, kas iestata kontroļpogas ID.
    int getControlButtonID(); // Funkcija, kas atgriež kontroļpogas ID.
    void setValue(int newValue); // Funkcija, kas iestata šūnas vērtību.
    int getValue(); // Funkcija, kas atgriež šūnas vērtību.
    void setID(int ID); // Funkcija, kas iestata šūnas ID.
    int getID(); // Funkcija, kas atgriež šūnas ID.
};