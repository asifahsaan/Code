#include<iostream>
#include"22l-6702-StudentInfo.h"
#include<fstream>
#include<string>

using namespace std;
int main()
{
	ifstream fileName;
	fileName.open("gradesheet.txt");
	{
		int totalStudents;
		fileName >> totalStudents;
		fileName.clear();
		fileName.seekg(0, ios::beg);
		StudentInfo* allStudents = new StudentInfo[totalStudents];
		for (int i = 0; i < totalStudents; i++)
		{
			allStudents[i].registerStudents(fileName);
		}
		cout << "\t \t Student List \t \t\n";
		cout << "Roll No.\tName\t \t  Q1  Q2  Q3  Q4  A1  A2  A3  A4  Total \n";
		for (int i = 0; i < totalStudents; i++)
		{
			allStudents[i].displayClassInfo();
		}
		allStudents->calculateMax();
		allStudents->calculateAverage();
		bool flag = false;
		int index = 0;
		char* roll{ new char [9] {} };
		while (flag == false)
		{
			cout << "Enter the Roll no. to show student report:";

			while (!(cin >> *roll))
			{
				cout << "Enter the roll-no:";
				cin.clear();
				cin.ignore();
				cin >> roll;
			}
			for (int i = 0; i < totalStudents; i++)
			{
				flag = allStudents[i].search(roll);
				if (flag == true)
				{
					index = i;
					break;
				}
			}
			if (flag == false)
				cout << "Roll no. not found!";
		}
		allStudents[index].fetchReport();

		delete[] roll;
		roll = nullptr;
		delete[] allStudents;
		allStudents = nullptr;
	}
	
	return 0;
	system("pause");
}