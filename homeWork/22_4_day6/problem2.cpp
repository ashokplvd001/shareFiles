/*
Description :The selling price & profit are entered. Write a program to calculate cost price of item.
Auther : Ashok Giddaluru ( 293950 )
Date of Creation : 22-4-24
DAte of modification : 22-4-24
Vesrion : 0.1
*/


#include <iostream>

using namespace std;	// using name space to use "cout" and "cin" 
void problem2()
{
	/*
	The selling price & profit are entered. Write a program to calculate cost price of item.
	*/
	
	int sellPrice, profit;
	cout << "Enter the sell price : ";
	cin >> sellPrice; 
	cout << "Enter the profit : ";
	cin >> profit ; 

	int costPrice = sellPrice - profit; 
	cout << "cost price is : " << sellPrice - profit; 

}

/*
OUTPUT :

Enter the sell price : 100
Enter the profit : 20
cost price is : 80
*/