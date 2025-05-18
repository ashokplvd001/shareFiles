#pragma once
#include "common.h"


bool qiuzStart(STDT & st, QUIZ & qz);

bool createRand(vector <short int>& randomList);

bool resultCalulation(STDT& student, vector <char>& rightWrong);

bool createRandList(vector <int>& list);

bool inputValidation( char & input , int & index  , int questionsCount , char  & rightFlag  , char rightOpt );