/*
Description : Write the logic to print right triangle star pattern.
Input Format  : First line contains N of type integer.
Output Format : Print the right triangle star pattern.

Auther : Ashok Giddaluru ( 293950 )
Date of Creation : 22-4-24
DAte of modification : 22-4-24
Vesrion : 0.1
*/


#include <iostream>

using namespace std;	// using name space to use "cout" and "cin" 

void problem11()	
{
	int num;
	cout << "Enter the number : ";
	cin >> num;
	for (int i = num * 2; i > 1; i--)
	{
		if (i > num )
		{
			for (int j = num * 2; j >= i; j--)
				cout << '*';
		}
		else
		{
			for (int j = i ; j > 1 ; j--)
				cout << '*';
		}
		cout << endl;
	}
}

/*
OUTPUT :

Enter the number : 5
*
**
***
****
*****
****
***
**
*


*/