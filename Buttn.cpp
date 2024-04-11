#include "Buttn.h"

Buttn::Buttn()
{
}

void Buttn::setCellsID(controlledCellsID newIDs)
{
	cellsID.ID1 = newIDs.ID1;
	cellsID.ID2 = newIDs.ID2;
}

controlledCellsID Buttn::getCellsID()
{
	return cellsID;
}

void Buttn::setPointsForCellsMerge(int points)
{
	this->pointsForCellsMerge = points;
}

int Buttn::getPointsForCellsMerge()
{
	return this->pointsForCellsMerge;
}

void Buttn::setID(int ID)
{
	this->ID = ID;
}

int Buttn::getID()
{
	return this->ID;
}
