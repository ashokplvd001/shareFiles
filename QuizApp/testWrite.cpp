#include <conio.h>
#include "testWrite.h"
#include "display.h"


bool qiuzStart(STDT& st, QUIZ& q )
{

	int qIndex = 0 ; 
	char input = 'N';
	
	void disclimerDisplay(  );

	do
	{
		switch ( input )
		{

			case 'N':
			case 'P':
				questionDisplay( q.quizQuestions[qIndex] ,  qIndex+1);
				break;
			case 'A' :
			case 'B' :
			case 'C' :
			case 'D' :
				cout << "U choosed -> " << q.quizQuestions[qIndex].quesOpt[input - 'A'] << endl;
				break;
		}

		input = _getch();
	

		// option validation function 
		inputValidation(input, qIndex, q.quizQuestionCount, q.quizRighWrong[qIndex] , q.quizQuestions[qIndex].quesRightOpt);
	


	} while (input != 'Q' );

	cout << "Test closed\n";

	// result show function      ***

	return true;

}


bool inputValidation(char& input , int &  index , int questionsCount , char  & rightFlag , char rightOpt )
{
	input = toupper( input );
	bool printFlag = true; 

	if ( input == 'P')
	{
		if (index > 0)
			index--;
		else {
			input = '\0';
			printFlag = false;
		}
	
	}
	else if ( input  == 'N')
	{
		if (index < questionsCount - 1)
			index++;
		else {
			input = '\0';
			printFlag = false;
		}
		
	}
	else
	{
		switch ( input )
		{
		default :
			printFlag = false;
		case 'A' :
		case 'B' :
		case 'C' :
		case 'D' :
			if (input == rightOpt)
				rightFlag = 1 ;
			else rightFlag = 0 ;
			break;
		case 'Q':
			break;

		}


	}

	if (printFlag == true)
		cout << input << endl;

	return true;
}