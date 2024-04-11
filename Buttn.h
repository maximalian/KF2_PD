#pragma once
#include "Member.h"

class Buttn : public Member
{
private:
    int ID; // Pogas identifikators.
    controlledCellsID cellsID; // Kontrolēto šūnu identifikatori.
    int pointsForCellsMerge; // Punkti, kas piešķirti šūnu saplūšanai.
public:
    Buttn(); // Konstruktors.
    void setCellsID(controlledCellsID newIDs); // Funkcija, kas iestata kontroles šūnu ID.
    controlledCellsID getCellsID(); // Funkcija, kas atgriež kontroles šūnu ID.
    void setPointsForCellsMerge(int points); // Funkcija, kas iestata punktus šūnu saplūšanai.
    int getPointsForCellsMerge(); // Funkcija, kas atgriež punktus šūnu saplūšanai.
    void setID(int ID); // Funkcija, kas iestata pogas ID.
    int getID(); // Funkcija, kas atgriež pogas ID.
};