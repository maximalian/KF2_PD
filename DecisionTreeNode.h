#pragma once
#include "Structures.h"
#include <vector>
#include <Windows.h>

using namespace std;

class DecisionTreeNode
{
private:
    vector<int> data{}; // Vektors, kas satur informāciju par mezglu.
    int player1Score{}; // Spēlētāja 1 rezultāts šajā mezglā.
    int player2Score{}; // Spēlētāja 2 rezultāts šajā mezglā.
    int chosenButtonID = -1; // Izvēlētās pogas ID.
public:
    vector<DecisionTreeNode*> childs; // Vektors ar šī mezgla pēctečiem.
    //----
    int getPlayer1Score(); // Atgriež spēlētāja 1 rezultātu.
    int getPlayer2Score(); // Atgriež spēlētāja 2 rezultātu.
    vector<int> getData(); // Atgriež mezgla datus.
    int getChildsCount(); // Atgriež pēcteču skaitu.
    int getChosenButtonID(); // Atgriež izvēlētās pogas ID.
    DecisionTreeNode* getChild(int ID); // Atgriež pēcteci pēc norādītā ID.
    //----
    void setPlayer1Score(int score); // Iestata spēlētāja 1 rezultātu.
    void setPlayer2Score(int score); // Iestata spēlētāja 2 rezultātu.
    void setChosenButtonID(int ID); // Iestata izvēlētās pogas ID.
    void setData(vector<int> newData); // Iestata jaunus mezgla datus.
    void addChild(DecisionTreeNode* newChild); // Pievieno jaunu pēcteci.
    void deleteTree(DecisionTreeNode* tree); // Atbrīvo atmiņu, iznīcinot visus koka mezglus.
    //----
    bool hasChilds(); // Pārbauda, vai mezglam ir pēcteči.
    ~DecisionTreeNode(); // Destruktors.
};