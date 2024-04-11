#include "Member.h"

Member::Member()
{
}

location Member::getLocation()
{
	return loc;
}


void Member::setLocation(int X, int Y)
{
	loc.X = X;
	loc.Y = Y;
}

void Member::setSize(float newSize)
{
	size = newSize;
}

float Member::getSize()
{
	return size;
}

void Member::setColor(int Argb)
{
	colorArgb = Argb;
}

int Member::getColor()
{
	return colorArgb;
}
