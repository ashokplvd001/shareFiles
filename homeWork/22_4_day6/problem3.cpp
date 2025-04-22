/*
Description : Write a program to calculate area of circle taking input the radius of the circle
Auther : Ashok Giddaluru ( 293950 )
Date of Creation : 22-4-24
DAte of modification : 22-4-24
Vesrion : 0.1
*/


#include <iostream>

using namespace std;	// using name space to use "cout" and "cin" 

void problem3()
{
	int radius;

	cout << "Enter the radius of the circlr in cm : ";
	cin >> radius;

	cout << "Area of the circle : " << radius * radius * 3.14 << "cm sq\n" ;

}

/*
OUTPUT:

Enter the radius of the circlr : 3
Area of the circle : 28.26
*/