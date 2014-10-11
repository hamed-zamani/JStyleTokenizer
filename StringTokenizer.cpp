#include "StringTokenizer.h"
//#include "NoMoreTokenException.h"
//#include "NullPointerException.h"
#include <string.h>

StringTokenizer ::StringTokenizer (char* inString, char* delimiters) 
{
	cursor = 0;
	this->tokenizingString = inString;
	this->delimiters = new string (delimiters);
	this->stringLen = strlen (this->tokenizingString);
	this -> delimiterLen = this->delimiters->size();	
}

///////////////////////////////////////////////////////////////////////////

StringTokenizer :: StringTokenizer (string inString, string delimiters) 
{
	cursor = 0;
	this->tokenizingString = new char[inString.size() + 1];
	memcpy((void *)(this->tokenizingString), inString.c_str(), inString.size() + 1);
	this->delimiters = new string(delimiters);
	this->stringLen = strlen (this->tokenizingString);
	this -> delimiterLen = this->delimiters->size();
}

///////////////////////////////////////////////////////////////////////////

bool StringTokenizer :: hasNext()
{

	if(tokenizingString == NULL)
		return false;
	if(strlen(tokenizingString) == 0)
		return false;
	//skip delimiters	
	while(this -> cursor != this -> stringLen && (delimiters -> find_first_of(tokenizingString[this -> cursor]) >= 0 && delimiters -> find_first_of(tokenizingString[this -> cursor]) < this->delimiterLen)) 
	{
		++cursor;	
	}
	
	
	if(this -> cursor == this -> stringLen)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////

string StringTokenizer :: getNext() 
{

	if(tokenizingString == NULL)
		cerr << "StringTokenizer::getNext" << endl;
	
	if (!hasNext())
		cerr << "StringTokenizer::getNext" << endl;

	int tokenLength = 0;
	int tokenFirst = cursor;

	while(cursor != this -> stringLen && delimiters -> find_first_of(tokenizingString[this -> cursor]) >= this->delimiterLen)
	{	
		++cursor;
		++tokenLength;
	}
	
	return string(tokenizingString, tokenFirst, tokenLength);
}

///////////////////////////////////////////////////////////////////////////

string StringTokenizer :: getRemainderNotStartWith(string str) 
{
	int tokenLength = 0;
	int lenOfStr = str.size();
	char*  temp = new char[lenOfStr + 1];
	int counter = 0;
	int i = 0;

	if(tokenizingString == NULL)
		cerr << "StringTokenizer::getRemainderWithOut" << endl;
	if (!hasNext())
		cerr << "StringTokenizer::getRemainderWithOut" << endl;

	while(cursor != this -> stringLen && delimiters -> find_first_of(tokenizingString[this->stringLen - 1]) < this->delimiterLen)
	{					
		this->stringLen--;
	}
	counter = this->cursor;

	for(i = 0; i < lenOfStr; i++)
	{
		temp[i] = tokenizingString[counter++];
	}
	temp[i] = 0;

	if(!strcmp(temp, str.c_str()))
	{
		this->cursor+= lenOfStr;
	}


	tokenLength = this->stringLen - cursor;

	delete[] temp;

	return string(tokenizingString, cursor, tokenLength);
}

///////////////////////////////////////////////////////////////////////////

string StringTokenizer :: getUntil(string endStr)
{
	int tokenLength = 0;
	int tokenFirst = 0;
	int endOfRetStr = 0;

	int strLen = endStr.size();

	if(tokenizingString == NULL)
		cerr << "StringTokenizer::getUntilStr()" << endl;

	if (!hasNext())
		cerr << "StringTokenizer::getUntilStr()" << endl;

	tokenFirst = cursor;	

	while(cursor != this -> stringLen && endStr.find_first_of(tokenizingString[this -> cursor]) >= strLen)
	{
		++cursor;
		++tokenLength;
	}

	endOfRetStr = cursor;

	while(cursor != this -> stringLen && delimiters -> find_first_of(tokenizingString[endOfRetStr]) < this->delimiterLen)		//clear delimiter from last of retStr
	{			
		endOfRetStr--;
		tokenLength--;
	}
	
//	if(this->cursor!= this->stringLen)
//		this->cursor++;
	return string(tokenizingString, tokenFirst, tokenLength);
}

///////////////////////////////////////////////////////////////////////////

StringTokenizer :: ~StringTokenizer ()
{
	delete[] (this->tokenizingString);
	delete this->delimiters;
	//this ->delimiters ->erase();
}