/*
Description : Write a c++ program to print alphabet triangle.
Input: 5
Output:

     A
    ABA
   ABCBA
  ABCDCBA
 ABCDEDCBA

Auther : Ashok Giddaluru ( 293950 )
Date of Creation : 22-4-24
DAte of modification : 22-4-24
Vesrion : 0.1
*/


#include <iostream>

using namespace std;	// using name space to use "cout" and "cin" 

void problem9()
{
    
    int num,temp;
    char ch; 
    cout << "Enter the number : ";
    cin >> num; 

    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num - i; j++)
            cout << ' ';

         ch = 'A' - 1 ;
        temp = i * 2 ;

        for (int k = 1 ; k < temp  ; k++)
        {
            if (k <= temp / 2)
                cout << (++ch);
            else
                cout << (--ch);
        }
        cout << endl;

    }
}

/*
OUTPUT :

Enter the number : 5
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
*/

