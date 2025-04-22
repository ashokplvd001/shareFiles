/*
Description : If a Five digit number is input through the keyboard, write a program to calculate the sum of
its digits.
Auther : Ashok Giddaluru ( 293950 )
Date of Creation : 22-4-24
DAte of modification : 22-4-24
Vesrion : 0.1
*/


#include <iostream>

using namespace std;	// using name space to use "cout" and "cin" 

void problem6()
{
	int num , res = 0 ; 
	cout << "Enter the number : ";
	cin >> num;

	while (num)
	{
		res = res + num % 10; 
		num /= 10; 
	}
	cout << "the sum of the numbers of given digits is : " << res; 
	return;
}

/*
OUTPUT :

Enter the number : 23734
the sum of the numbers of given digits is : 19
*/