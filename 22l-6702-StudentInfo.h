#include<fstream>

class StudentInfo
{
private:
	static int totalStudents;     //total no. of students in class
	static int totalQuizes;        // total no. of quiz held in class
	static int totalAssignments;   //total no. of assignments assigned to class
	static int total;
	static int* maxQuiz;          //array to store max marks in each quiz of class
	static int* maxAssignment;    //array to store maximum marks in each assignment of class

	static int* average;        // array to store average of whole class

	int grandTotal;           //stores grand total of students

	int* obtainedQuiz;       //array to store obtained marks in quizzes
	int* obtainedAssignment;    //array to store obtained marks in assignments

	int* totalQuizMarks;          //total marks of a quiz
	int* totalAssignmentMarks;   //total assignment marks
	char rollNo[9];             //roll no. of student
	char* firstName;           //first name of student
	char* lastName;             //last name of student

public:
	StudentInfo();
	~StudentInfo();

	void registerStudents(ifstream& );  //loading students from file into the memory
	void displayClassInfo();  //display each students information
	void calculateAverage();
	void calculateMax();
	bool search (char*);
	void fetchReport(); //this function calculates and displays the average, maximum of each quiz.
};

int StudentInfo::totalStudents = 0;
int StudentInfo::totalQuizes = 0;
int StudentInfo::totalAssignments = 0;
int StudentInfo::*maxQuiz = 0;
int StudentInfo::* maxAssignment = 0;
int StudentInfo::*average = 0;
