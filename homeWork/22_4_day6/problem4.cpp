/*
Description :  Write a program to swap two numbers without using third variable and without using functions or pointers.
Auther : Ashok Giddaluru ( 293950 )
Date of Creation : 22-4-24
DAte of modification : 22-4-24
Vesrion : 0.1
*/


#include <iostream>

using namespace std;	// using name space to use "cout" and "cin" 

void problem4()
{

	int num1, num2;

	cout << "Enter number1 : ";
	cin >> num1;
	cout << "Enter number2 : ";
	cin >> num2;

	num1 = num1 + num2;
	num2 = num1 - num2;
	num1 = num1 - num2;

	cout << "number1 : " << num1<<endl;
	cout << "number2 : " << num2<<endl;

	num1 = num1 ^ num2;
	num2 = num1 ^ num2;
	num1 = num1 ^ num2;

	cout << "number1 : " << num1<<endl;
	cout << "number2 : " << num2<<endl;

}

/*
OUTPUT :

Enter number1 : 21
Enter number2 : 56
number1 : 56
number2 : 21
number1 : 21
number2 : 56
*/