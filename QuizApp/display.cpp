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
		cout << "^^^^^^^^^^^^^^^^^^^^^^^\n";
	}
	cout << "#########################\n";
}

void questionDisplay(QUES& qs, int number)
{

	cout << 'Q' << number << ") " << qs.quesQuestion << endl;
	for (int j = 0; j < NO_OF_CHOICE; j++)
		cout << char('A' + j) << ")  " << qs.quesOpt[j] << endl;
	cout << "--------\n";

}

void disclimerDisplay(int questionsCount)
{
	cout << "**************Welcome*****************\n";
	cout << "\t\tYour test contains " << questionsCount << " Questions" << endl;
	cout << "\t\tTotal marks : " << questionsCount * 5 << endl;
	cout << "\t\tPass percentage is 70%\n" ;
	cout << "\t\tClick 'P' to go to previous question\n";
	cout << "\t\tClick 'P' to go to previous question\n";
	cout << "\t\tClick 'N' to go to next question\n";
	cout << "\t\tIf u click 'Q' it will close\n";
	cout << "\t\tIf u click anything other then 'A' , 'B' , 'C' , 'D' it is not valid input , it will ignore that key\n";
	cout << "\t\tYou can start now\n";
	cout << "**************************************\n";
}



void printStdtScore(STDT& student , int totalCount )
{
	cout << "\n********score*******\n";
	cout << "Student Id\t: " << student.stdtId << endl;
	cout << "Student Name\t: " << student.stdtName << endl;
	cout << "Total questions count\t: " << totalCount << endl;
	cout << "Total marks : " << totalCount * 5 << endl;
	cout << "Correct Answers\t: " << student.stdtCorrectAns << endl;
	cout << "Wrong Answers\t: " << totalCount -  student.stdtCorrectAns << endl;
	cout << "Student total Marks\t: " << student.stdtMarks << endl;
	cout << "Student Percentage\t: " << student.stdPercentage << endl;

	if (student.stdPercentage >= 70) cout << "Quiz Passed\n";
	else cout << "Quiz Failed\n";

	cout << "\n********   ***   *******\n";
}

void displayMainMenu()
{
	cout << "Enter the option\n1. Student register\n2. Start Exam\n3. Want to see my score\n4. Print all students list\n5. Exit from app\n";
}