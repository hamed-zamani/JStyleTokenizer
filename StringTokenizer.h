#ifndef STRING_TOKENIZER_H
#define STRING_TOKENIZER_H

#include <string>
#include <iostream>

using namespace std;

class StringTokenizer 
{

private:	
	
	char* tokenizingString;
	string* delimiters;
	int cursor;
	int stringLen;
	int delimiterLen;


public:
	
	StringTokenizer(char*, char*);
	StringTokenizer(string, string);

	~StringTokenizer();
	bool hasNext();
	string getNext();
	string getRemainderNotStartWith(string);
	string getUntil(string);

};

#endif