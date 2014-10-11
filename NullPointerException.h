#ifndef NULL_POINTER_EXCEPTION
#define NULL_POINTER_EXCEPTION

#include <string>

using namespace std;

class NullPointerException : public exception
{
public:
	NullPointerException(string);
	string getString();

private :
	string place;
};

#endif
