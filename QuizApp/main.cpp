#include "common.h"
#include "questionsPrep.h"
#include "display.h"
#include "testWrite.h"
using namespace std;


int main()
{
	
	string fileName = "" ;
	QUIZ quiz1 = { {} , 0 , {} };
	vector <STDT> students ;
	STDT st = { 0 , };

	
	cout << "Enter the quiz name : ";
	cin >> fileName; 
	fileName += ".txt";
	
	if (qustionsPrep(&quiz1, fileName) == false)
	 {
		cout << "Failed to prepare questions ; ";
			return -1;
	 }

#ifdef DEBUG  
	displayAllquestionsContent(quiz1);
#endif


	int opt = 0; 

	//do
	{
		//cout<<"Enter the option 1. Student register\n2.Start Exam\n3.Want to see my score\nExit from app " : 
		//cin>>

		
	}


	//	qiuzStart( st , quiz1 );

}






