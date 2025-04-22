/*
Description :The basic salary is entered.House rent allowance is 40 % of basic salary & dearness
		allowance is 20 % of basic salary.write a program to calculate the gross salary.
Auther : Ashok Giddaluru ( 293950 )
Date of Creation : 22-4-24
DAte of modification : 22-4-24
Vesrion : 0.1
*/


#include <iostream>

using namespace std;	// using name space to use "cout" and "cin"  

void problem1()
{
	/*
	The basic salary is entered.House rent allowance is 40 % of basic salary & dearness
		allowance is 20 % of basic salary.write a program to calculate the gross salary.
		*/

	int basicSalary; 
	cout << "Enter basic salary : ";
	cin >> basicSalary;

	float houseAllowance = ((float)basicSalary * 40.0) / 100.0 ;
	float dearnessAllowance = ((float)basicSalary * 20.0) / 100.0 ;

	float grossSalary = houseAllowance + dearnessAllowance + basicSalary;

	cout << "grossSalary is : " << grossSalary << endl;
}


/*
OUTPUT :

Enter basic salary : 150
grossSalary is : 240

*/