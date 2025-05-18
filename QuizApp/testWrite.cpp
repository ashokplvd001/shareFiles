#include <conio.h>
#include "testWrite.h"
#include "display.h"


bool qiuzStart(STDT& st, QUIZ& q )
{

	int qIndex = 0 ; 
	char input = 'N';

	st.stdtMarks = 0;
	st.stdtMarks = 0 ;
	
	disclimerDisplay( q.quizQuestionCount );

	for (int i = 0; i <  q.quizQuestionCount ; i++)
		q.quizRighWrong[i] = 0; 

	/// create Random list *****
	//createRand( q.quizRandQuestionsList );
	
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
	

		// input validation function 
		inputValidation(input, qIndex, q.quizQuestionCount , q.quizRighWrong[qIndex] , q.quizQuestions[qIndex].quesRightOpt);
	


	} while (input != 'Q' );

	cout << "Test closed\n";

	// reult calculation 
	resultCalulation(st,  q.quizRighWrong );

	// result show function     
	printStdtScore(st, q.quizQuestionCount);

	return true;

}

bool createRand ( vector <short int> & randomList )
{
	for (int i = 0; i < randomList.size(); i++)
		randomList[i] = 0; 

	int value = 0; 
	for (int i = 0 , j = 0 ; i < randomList.size(); i++)
	{
		value = rand() % randomList.size() ; 

		for ( j = 0; j < i; j++)
		{
			if (randomList[j] == value )
				break;
		}

		if (i == j)
		{
			randomList[i] = value;
			i++; 
		}
	}
	return true;
}

bool resultCalulation( STDT & student , vector <char> & rightWrong )
{
	int sum = 0; 

	for (int i = 0; i < rightWrong.size(); i++)
	{
		if (rightWrong[i] == 1)
			sum++ ;
	}
	student.stdtCorrectAns = sum ;
	student.stdtMarks = sum * 5;
	student.stdPercentage = student.stdtMarks * 100 / (rightWrong.size() * 5) ;

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
			cout << "\rThis is first question in list no prev question stop pressing 'P' , press 'N' and go furthur";
			fflush(stdout);
			printFlag = false;
		}
	
	}
	else if ( input  == 'N')
	{
		if (index < questionsCount - 1)
			index++;
		else {
			input = '\0';
			cout << "\rThis is last question in list no next question stop pressing 'N' , press 'P' and go back";
			fflush( stdout) ;
			
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