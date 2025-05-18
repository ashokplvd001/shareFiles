#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std ; 

#define NO_OF_CHOICE 4

#define DEBUG 


typedef struct _student
{
	int stdtId ; 
	string stdtName ;
	int stdtCorrectAns;
	int stdtMarks; 
	float stdPercentage;
}STDT;


typedef struct _question
{
	string quesQuestion;
	string quesOpt[ NO_OF_CHOICE ] ;
	char quesRightOpt ;
}QUES;


typedef struct _quiz
{
	vector < QUES > quizQuestions; 
	short int quizQuestionCount;
	vector < short int > quizRandQuestionsList;
	//vector <bool> quizRighWrong; // bool vector behavior is different
	vector <char> quizRighWrong;
}QUIZ;



////////////


//////////