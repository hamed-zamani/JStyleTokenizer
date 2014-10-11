#include <iostream>
#include "StringTokenizer.h"

using namespace std;

int main(){
	string name;
	getline(cin, name);
	StringTokenizer a (name, " ");
	while (a.hasNext()){
		cout << a.getNext() << endl;
	}
	return 0;
}
