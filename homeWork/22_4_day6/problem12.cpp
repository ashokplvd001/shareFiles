/*
Description : Write the logic to print inverted right triangle star pattern.
Input Format  : First line contains N of type integer.
Output Format : Print the inverted right triangle star pattern.

Auther : Ashok Giddaluru ( 293950 )
Date of Creation : 22-4-24
DAte of modification : 22-4-24
Vesrion : 0.1
*/


#include <iostream>

using namespace std;	// using name space to use "cout" and "cin" 

void problem12()
{
	int num;
	cout << "Enter the number : ";
	cin >> num;

	for ( ; num ; num--)
	{
		for (int j = num ; j; j--)
			cout << '*';
		cout << endl;
	}
}

/*
OUTPUT :

Enter the number : 5
*****
****
***
**
*


*/