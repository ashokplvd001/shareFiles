/*
Description :Write the logic to for incrementing Squared Number-Star Pattern.
		Input Format      : Take N as input of type integer.
		Output Format     : Print incrementing Squared Number-Star Pattern.
Auther : Ashok Giddaluru ( 293950 )
Date of Creation : 22-4-24
DAte of modification : 22-4-24
Vesrion : 0.1
*/


#include <iostream>

using namespace std;	// using name space to use "cout" and "cin" 

void problem8()
{
	int num; 
	cout << "Enter the number : ";
	cin >> num;
	for (int i = 1; i <= num * num ; i++)
	{
		if (i % num)
			cout << i << '*';
		else
			cout << i << endl;
	}
}

/*
OUTPUT :


Enter the number : 5
1*2*3*4*5
6*7*8*9*10
11*12*13*14*15
16*17*18*19*20
21*22*23*24*25
*/