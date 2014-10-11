#include "NullPointerException.h"


string NullPointerException :: getString()
{
	return this -> place;
}

///////////////////////////////////////////////////////////

NullPointerException :: NullPointerException(string pl)
{
	this -> place = "NullPointerException occured in " + pl ;
}
