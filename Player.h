#pragma once
class Player
{
private:
    int score = 0; // Spēlētāja rezultāts.
    bool makingMove = false; // Būleanais mainīgais, kas norāda, vai spēlētājs veic gājienu.
public:
    Player(); // Noklusētais konstruktors.
    void setScore(int score); // Iestata spēlētāja rezultātu.
    int getScore(); // Atgriež spēlētāja rezultātu.
    void setStatus(bool makingMove); // Iestata spēlētāja gājiena statusu.
    bool getStatus(); // Atgriež spēlētāja gājiena statusu.
};