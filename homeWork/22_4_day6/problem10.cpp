/*
Description : Write the logic to print star pattern or rectangle star pattern.
		Input Format  : First line contains N of type integer.
		Output Format : Print the rectangle star pattern. or pointers.

Auther : Ashok Giddaluru ( 293950 )
Date of Creation : 22-4-24
DAte of modification : 22-4-24
Vesrion : 0.1
*/


#include <iostream>

using namespace std;	// using name space to use "cout" and "cin" 

void problem10()
{
	int number;
	cout << "Enter the number : ";
	cin >> number;

	for (int i = 1 ; i <= (number * number) ; i++)
	{
		cout << '*';
		if (i % number == 0)
			cout << endl;
	}
}

/*
OUTPUT : 

Enter the number : 5
*****
*****
*****
*****
*****

*/