#include "NoMoreTokenException.h"


string NoMoreTokenException :: getString()
{
	return this -> place;
}

///////////////////////////////////////////////////////////

NoMoreTokenException :: NoMoreTokenException(string pl)
{
	this -> place = "NoMoreTokenException occured in " + pl ;
}
