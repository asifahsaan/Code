#include<iostream>
#include"22l-6702-StudentInfo.h"
#include<fstream>
#include<string>

using namespace std;

StudentInfo::StudentInfo()
{
	
}

StudentInfo::~StudentInfo()
{
	delete[] maxQuiz; 
	maxQuiz = nullptr;
	delete [] maxAssignment;   
	maxAssignment = nullptr;
	delete[] average; 
	average = nullptr;
	delete[] obtainedQuiz; 
	obtainedQuiz = nullptr;
	delete [] obtainedAssignment;
	obtainedAssignment = nullptr;
	delete[] totalQuizMarks; 
	totalQuizMarks= nullptr;
	delete[] totalAssignmentMarks; 
	totalAssignmentMarks = nullptr;
	delete[] firstName; 
	firstName = nullptr;
	delete[] lastName;
	lastName = nullptr;
}

int StudentInfo::total = 0;
void StudentInfo::registerStudents(ifstream& filename)
{
	filename >> totalStudents;
	filename >> totalQuizes;
	filename >> totalAssignments;

	for (int i = 0; i < 4; i++)
	{
		filename >> *totalQuizMarks;
		total += *totalQuizMarks;
		totalQuizMarks+1;
	}
	for (int i = 0; i < 4; i++)
	{
		filename >> totalAssignmentMarks[i];
		total += *totalAssignmentMarks;
		totalAssignmentMarks + 1;
	}
	
	obtainedQuiz = new int[4];
	obtainedAssignment = new int[4];

	filename >> rollNo;
	rollNo[9] = '\0';
	filename >> firstName;
	filename >> lastName;
	for (int i = 0; i < 4; i++)
	{
		filename >> obtainedQuiz[i];
	}
	for (int i = 0; i < 4; i++)
	{
		filename >> obtainedAssignment[i];
	}

}
void StudentInfo::displayClassInfo() //display's first name, last name, roll no.,quiz marks, assignment marks, obtained, total
{
	grandTotal = 0;
	cout << rollNo << "\t" << firstName << " " << lastName << " ";
	for (int i = 0; i < 4; i++)
	{
		obtainedQuiz[i];
		cout<< " ";
		grandTotal += obtainedQuiz[i];
	}
	for (int i = 0; i < 4; i++)
	{
		obtainedAssignment[i];
		cout << " ";
		grandTotal += obtainedAssignment[i];
	}
	cout << grandTotal;

}
void StudentInfo::calculateMax()
{

	cout << "Maximum marks of quiz 1 : " << *maxQuiz << "\n";
	cout << "Maximum marks of quiz 2 : " << *(maxQuiz+1) << "\n";
	cout << "Maximum marks of quiz 3 : " << *(maxQuiz+2) << "\n";
	cout << "Maximum marks of quiz 4 : " << *(maxQuiz+3) << "\n";
	cout << "Maximum marks of Assignment 1 : " << *maxAssignment << "\n";
	cout << "Maximum marks of Assignment 2 : " << *(maxAssignment + 1) << "\n";
	cout << "Maximum marks of Assignment 3 : " << *(maxAssignment + 2) << "\n";
	cout << "Maximum marks of Assignment 4 : " << *(maxAssignment + 3) << "\n";

}
void StudentInfo::fetchReport() //calculates average, maximum of each quiz
{
	cout << "\t \tStudent Report\n";
	cout << "Roll No.:  " << rollNo << "\n";
	cout << "Name :   " << firstName << " " << lastName << "\n";
	cout << "Quiz 1 : " << obtainedQuiz[0] << "\n";
	cout << "Quiz 2 : " << obtainedQuiz[1] << "\n";
	cout << "Quiz 3 : " << obtainedQuiz[2] << "\n";
	cout << "Quiz 4 : " << obtainedQuiz[3] << "\n";
	cout << "Assignment 1 : " << obtainedAssignment[0] << "\n";
	cout << "Assignment 2 : " << obtainedAssignment[1] << "\n";
	cout << "Assignment 3 : " << obtainedAssignment[2] << "\n";
	cout << "Assignment 4 : " << obtainedAssignment[3] << "\n";
	cout << "Total:  " << grandTotal << "/" << "total";
}
bool StudentInfo::search (char* roll)
{
	bool flag = false;
	int count = 0;
	for (int i = 0; i < 9; i++)
	{
		if (roll[i] == rollNo[i])
			count++;
	}
	if (count == 9)
		flag = true;
	return flag;
}
void StudentInfo::calculateAverage()
{
	*average = 0;
	cout << "Quiz 1 average : ";
}
