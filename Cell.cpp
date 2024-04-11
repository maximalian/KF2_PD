#include "Cell.h"

void Cell::setControlButtonID(int btnID)
{
	controlButtonID = btnID;
}

int Cell::getControlButtonID()
{
	return controlButtonID;
}

void Cell::setValue(int newValue)
{
	value = newValue;
}

int Cell::getValue()
{
	return value;
}

void Cell::setID(int ID)
{
	this->ID = ID;
}

int Cell::getID()
{
	return this->ID;
}

Cell::Cell()
{
}
