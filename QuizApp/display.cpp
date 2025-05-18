#include "common.h"
#include "display.h"

void displayAllquestionsContent(QUIZ& qz)
{
	for (int i = 0; i < qz.quizQuestionCount; i++)
	{
		cout << 'Q' << i + 1 << ") " << qz.quizQuestions[i].quesQuestion << endl;
		for (int j = 0; j < NO_OF_CHOICE; j++)
			cout << char('A' + j) << ")  " << qz.quizQuestions[i].quesOpt[j] << endl;

		cout << "Right answer is : "
			<< qz.quizQuestions[i].quesOpt[qz.quizQuestions[i].quesRightOpt - 'A'] << endl;
		cout << "Option - " << qz.quizQuestions[i].quesRightOpt << endl << endl;

	}
}

void questionDisplay (  QUES & qs , int number )
{

	cout << 'Q' << number << ") " << qs.quesQuestion << endl;
	for (int j = 0; j < NO_OF_CHOICE; j++)
		cout << char('A' + j) << ")  " << qs.quesOpt[j] << endl;

}

void disclimerDisplay( )
{
	cout << "**************Welcome*****************\n";
	//cout << "\t\tYour test contains " << questionsCount << endl;
	cout << "\t\tClick 'P' to go to previous question\n";
	cout << "\t\tClick 'P' to go to previous question\n";
	cout << "\t\tClick 'N' to go to next question\n";
	cout << "\t\tIf u click 'Q' it will close\n";
	cout << "\t\tIf u click anything other then 'A' , 'B' , 'C' , 'D' it is not valid input , it will ignore that key\n";
	cout << "\t\tYou can start now\n";
	cout << "**************************************\n";
}