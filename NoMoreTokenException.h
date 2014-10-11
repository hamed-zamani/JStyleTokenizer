#ifndef NO_MORE_TOKEN_EXCEPTION
#define NO_MORE_TOKEN_EXCEPTION

#include <string>

using namespace std;

class NoMoreTokenException : public exception
{
public:
	NoMoreTokenException(string);
	string getString();

private :
	string place;
};

#endif
