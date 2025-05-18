#include <cstdio>
#include <string>
#include "common.h"
#include "questionsPrep.h"



bool qustionsPrep(QUIZ* quiz1, string fileName)
{
	QUES quest = { "" , };
	int quesCount = 0;


#ifdef DEBUG 
	cout << "filename : " << fileName << endl;
#endif

	FILE* fptr = fopen((const char*)fileName.c_str(), "r");



	if (fptr == NULL)
	{
		perror("fopen");
		return false;
	}

	while (prepQuestionAns(fptr, &quest))
	{
		quesCount++;	

		quiz1->quizQuestions.push_back( quest );			
	}

#ifdef DEBUG 
	cout << "quesCount = " << quesCount << endl;
#endif


	fclose(fptr);

	quiz1->quizQuestionCount = quesCount;

	quiz1->quizRandQuestionsList.resize(quesCount, 0);

	quiz1->quizRighWrong.resize(quesCount, 0 );

	if (quesCount < 1)
	{
		cout<<"No questions in quiz source\n" ;
		return false;
	}

	return true;
}





bool prepQuestionAns(FILE* fptr, QUES* quest)
{
	bool flag = false;
	char ch1 = 0, ch2 = 0;

	for (int i = 0; i < NO_OF_CHOICE; i++)
		quest->quesOpt[i] = "";
	quest->quesQuestion = "";
	quest->quesRightOpt = 'A';


	do
	{
		if ('Q' == fgetc(fptr))
		{
			if (')' == fgetc(fptr))
			{
				while ((ch1 = fgetc(fptr)) != '\n' && ch1 != EOF)
				{
					quest->quesQuestion = quest->quesQuestion + ch1;
				}

				if (quest->quesQuestion != "")
					flag = true;
			}
		}

		if (feof(fptr))
			return false;

	} while (flag == false);

	
	do
	{
		ch1 = toupper(fgetc(fptr));
		switch (ch1)
		{
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			{
				if ( fgetc(fptr) == ')')
				{
					while ((ch2 = fgetc(fptr)) != '\n' && ch2 != EOF)
					{
						quest->quesOpt[ch1 - 'A'] = quest->quesOpt[ch1 - 'A'] + ch2;
					}
				}
			}
			break;
			case 'R':
			{
				if ((ch2 = fgetc(fptr)) == ')')
				{
					ch2 = toupper(fgetc(fptr));
					quest->quesRightOpt = ch2;
				}

			}
			break;
		}
		if (feof(fptr))
			return true;

	} while (ch1 != 'Q');

	fseek(fptr, -1, SEEK_CUR);


	return true;


}