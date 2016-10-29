#include <iostream>
#include "io.h"
 
int main()
{
	using namespace std;

    int x = readNumber();
    int y = readNumber();
    writeAnswer(x+y);

    if( __cplusplus == 201103L ) cout << "C++11\n" ;
	else if( __cplusplus == 19971L ) cout << "C++98\n" ;
	else cout << "pre-standard C++\n" ;

    cin >> x;
    return 0;
}
