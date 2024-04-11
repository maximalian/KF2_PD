#pragma once
// Struktūra, kas apraksta elementa izmēru (platums un augstums).
struct elementSize {
    int W; // Platums.
    int H; // Augstums.
};

// Struktūra, kas satur šūnu ID, ko kontrolē pogas.
struct controlledCellsID {
    int ID1; // Pirmās šūnas ID.
    int ID2; // Otrās šūnas ID.
};

// Struktūra, kas apraksta elementa atrašanās vietu (X un Y koordinātes).
struct location {
    int X; // X koordināte.
    int Y; // Y koordināte.
};