#include "common.h"
#include <vector>
#include "questionsPrep.h"
#include "display.h"
#include "testWrite.h"
using namespace std;



bool studentReg( vector <STDT> & students );

bool studentAttended(unsigned short int stdtId, vector <STDT>& students);

bool studentExist(unsigned short int stdtId, vector <STDT>& students);

bool validateAndCallQuizStart(vector <STDT>& students, QUIZ& qz);

bool validateAndCallStdtPrintScore(vector <STDT>& students , int totalCount);

bool validateAndCallQuizStart(vector <STDT>& students, QUIZ& qz);

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


	char opt = '\0' ;
	unsigned short int stdtId = 0; 
	do
	{
		displayMainMenu();
		
		cin >> opt; 

		switch (opt)
		{
		default :
			cout << "Invalid option-----------------X\\n";
			break; 
		case '1' :
			 studentReg( students );
			break;
		case '2' :
			validateAndCallQuizStart( students, quiz1  );
			break;
		case '3' :
			validateAndCallStdtPrintScore(students , quiz1.quizQuestionCount ) ;
			break;
		case '4' :
			if (students.size() == 0)
				cout << "No student attended to test-----------------X\\n";
			else
			for (int i = 0; i < students.size(); i++)
			{
				printStdtScore(students[i ], quiz1.quizQuestionCount );
				cout << "--------------\n";
			}
		case '5' :
			break; 
				
		}

		
	} while (opt != '5' );

	cout << "Program closed\n";

}


bool validateAndCallStdtPrintScore(vector <STDT>& students , int totalCount )
{
	int stdtId = 0;
	cout << "Enter student Id : ";
	cin >> stdtId;
	if (studentExist(stdtId, students) == true)
	{
		if (studentAttended(stdtId, students) == true )
		{
			printStdtScore(students[stdtId - 1] , totalCount );
			return true;
		}
		else
			cout << "Student already attend exam-----------------X\n";
	}
	else
		cout << "Student not existed-----------------X\n";

	return false;
}

bool validateAndCallQuizStart( vector <STDT> & students , QUIZ & qz )
{
	int stdtId = 0; 
	cout << "Enter student Id : ";
	cin >> stdtId ;
	if (studentExist(stdtId, students) == true)
	{
		if (studentAttended(stdtId, students) == false)
		{
			qiuzStart(students[stdtId - 1], qz );
			return true; 
		}
		else
			cout << "Student already attend exam-----------------X\n";
	}
	else
		cout << "Student not existed-----------------X\n";

	return false;
}




bool studentReg( vector <STDT> & students )
{
	STDT student = { 0 , };

	student.stdtId = students.size()  + 1;
	cout << "Enter name : ";
	cin >> student.stdtName ; 
	cout<<"your roll no is : "<< students.size() + 1 <<endl;
	student.stdtMarks = -1 ; 
	student.stdtCorrectAns = -1 ;
	students.push_back(student);
	return true;
}

bool studentExist(unsigned short int stdtId, vector <STDT>& students)
{

	cout << "Existed students cout : " << students.size() << endl;
	if (students.size() == 0 )
		return false;

	if (students.size() >= stdtId)
		return true;

	return false;
}


bool studentAttended( unsigned short int stdtId , vector <STDT> & students )
{
	if ( students[stdtId-1].stdtCorrectAns != -1  )
		return true;

	return false;
}



