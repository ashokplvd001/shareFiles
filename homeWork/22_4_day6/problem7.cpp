/*
Description : Print series 0,3,8,15,24,35,48,63,80,99
Auther : Ashok Giddaluru ( 293950 )
Date of Creation : 22-4-24
DAte of modification : 22-4-24
Vesrion : 0.1
*/


#include <iostream>

using namespace std;	// using name space to use "cout" and "cin" 

void problem7()
{
	int number ; 
	cout << "Enter the number : ";
	cin >> number;
	int i ; 
	for ( i = 1; i < number ; i++)
		cout << i * i - 1 << ',';
	cout << i * i - 1 << endl;
}