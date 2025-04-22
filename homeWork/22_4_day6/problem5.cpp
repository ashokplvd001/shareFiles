/*
Description : If the marks obtained by a student in five different subjects are input through the keyboard, find
out the aggregate marks and percentage marks obtained by the student. Assume that the maximum
marks that can be obtained by a student in each subject are 100
Auther : Ashok Giddaluru ( 293950 )
Date of Creation : 22-4-24
DAte of modification : 22-4-24
Vesrion : 0.1
*/


#include <iostream>

using namespace std;	// using name space to use "cout" and "cin" 

void problem5()
{
	int subjects = 5; 
	int marks[5];
	int total = 0; 
	for (int i = 0 ; i < subjects; i++)
	{
		cout << "Enter the mark of subject" << i << " : " ;
		cin >> marks[i];
		total = total + marks[i]; 
	}
	
	cout << "total marks of all subects : " << total<<endl; 
	cout << "average of marks : " << (float)total / subjects;
}