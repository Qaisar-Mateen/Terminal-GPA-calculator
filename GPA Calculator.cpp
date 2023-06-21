#include<iostream>
#include<windows.h>

using namespace std;

void greet();
void exit_msg();
float Get_Grade_Point();

int main()
{
	char op = '\0';

	greet();

	while (op != 'e')
	{
		cout << "\n\n\t\t\t   ---====================<(Menue)>====================---";
		cout << "\n\t\t\t  ||                                                     ||";
		cout << "\n\t\t\t  ||              Press A: To Calculate SGPA.            ||";
		cout << "\n\t\t\t  ||              Press B: To Calculate CGPA.            ||";
		cout << "\n\t\t\t  ||              Press E: To Exit                       ||";
		cout << "\n\t\t\t  ||                                                     ||";
		cout << "\n\t\t\t   ---=================================================--- \n\n";
		cout << " Command\\: ";
		cin >> op;

		if (op == 'a' || op == 'A')
		{
			system("cls");

			cout << "\n\t\t\t    +-----------<(Grade to Point Table)>-----------+";
			cout << "\n\t\t\t    |  A+ (4.00)  A  (4.00)  A- (3.67)  B+ (3.33)  |";
			cout << "\n\t\t\t    |  B  (3.00)  B- (2.67)  C+ (2.33)  C (2.00)   |";
			cout << "\n\t\t\t    |      C- (1.67)    D+ (1.33)    D (1.00)      |";
			cout << "\n\t\t\t    +----------------------------------------------+\n";

			int sub_no = 0;
			cout << " Enter the no of Courses: ";
			cin >> sub_no;

			while (sub_no <= 1)
			{
				cout << "\n x---INVALID---x \n input again: ";
				cin >> sub_no;
			}

			int* crd_hr = new int[sub_no];
			float* points = new float[sub_no];
			string* sub_name = new string[sub_no];

			for (int i = 0; i < sub_no; i++)
			{
				cout << "\n         +---- For Course " << i + 1 << " ----+ \n";
				cout << " Enter Name : ";
				cin >> sub_name[i];

				cout << " Enter credit hour : ";
				cin >> crd_hr[i];

				while (crd_hr[i] > 3 || crd_hr[i] <= 0)
				{
					cout << "\n x--- INVALID ---x \n Enter again: ";
					cin >> crd_hr[i];
				}

				points[i] = Get_Grade_Point();
			}

			float numerator = 0.0, denominator = 0.0;

			for (int i = 0; i < sub_no; i++)
			{
				numerator += crd_hr[i] * points[i];
				denominator += crd_hr[i];
			}

			float gpa = numerator / denominator;

			cout.precision(3);
			cout << "\t\t\t\t\t\t    --------------\n";
			cout << "\t\t\t\t\t\t   / SGPA is: " << gpa << " / \n";
			cout << "\t\t\t\t\t\t   --------------\n";

			delete[] points;
			delete[] crd_hr;
			delete[] sub_name;
		}

		else if (op == 'b' || op == 'B')
		{
			system("cls");
			int semester = 0;
			cout << " For how many semesters you want to calculate CGPA: ";
			cin >> semester;

			float* gpa = new float[semester];

			for (int i = 0; i < semester; i++)
			{
				cout << "Enter GPA for " << i + 1 << " Semester: ";
				cin >> gpa[i];

				while (gpa[i] > 4 || gpa[i] < 0)
				{
					cout << "\n x---INVALID---x \n input again: ";
					cin >> gpa[i];

				}
			}

			float cgpa = 0.0;

			for (int i = 0; i < semester; i++)
			{
				cgpa += gpa[i];
			}

			cgpa = cgpa / semester;

			cout.precision(3);
			cout << "\t\t\t\t\t\t     ---------------\n";
			cout << "\t\t\t\t\t\t   / CGPA is: " << cgpa << " / \n";
			cout << "\t\t\t\t\t\t   ---------------\n";

			delete[] gpa;

		}

		else if (op == 'e')
		{
			exit_msg();
		}

		else
		{
			cout << "\n    X---- INVALID INPUT ----X \n";
		}
	}

	return 0;
}

float Get_Grade_Point()
{
	string grade;
	float pts = 0.0;

	cout << " Enter Grade: ";
	cin >> grade;


	do {

		if (!grade.compare("A+") || !grade.compare("A") || !grade.compare("a") || !grade.compare("a+"))
		{
			pts = 4.00;
			break;
		}

		else if (!grade.compare("A-") || !grade.compare("a-"))
		{
			pts = 3.67;
			break;
		}

		else if (!grade.compare("B+") || !grade.compare("b+"))
		{
			pts = 3.33;
			break;
		}

		else if (!grade.compare("B") || !grade.compare("b"))
		{
			pts = 3.00;
			break;
		}

		else if (!grade.compare("B-") || !grade.compare("b-"))
		{
			pts = 2.67;
			break;
		}

		else if (!grade.compare("c+") || !grade.compare("C+"))
		{
			pts = 2.33;
			break;
		}

		else if (!grade.compare("C") || !grade.compare("c"))
		{
			pts = 2.00;
			break;
		}

		else if (!grade.compare("C-") || !grade.compare("c-"))
		{
			pts = 1.67;
			break;
		}

		else if (!grade.compare("D+") || !grade.compare("d+"))
		{
			pts = 1.33;
			break;
		}

		else if (!grade.compare("d") || !grade.compare("D"))
		{
			pts = 1.00;
			break;
		}

		else if (!grade.compare("F") || !grade.compare("f"))
		{
			pts = 0.00;
			break;
		}

		else 
		{
			cout << "\n x--- INVALID ---x \n Enter again: ";
			cin >> grade;
		}

	} while (true);
	
	return pts;
}

void greet()
{
	int s = 2000;

	cout << "\n\n";
	cout << "\t\t     ____    __    ____  _______  __        ______   ______   .___  ___.  _______ \n";
	cout << "\t\t     \\   \\  /  \\  /   / |   ____||  |      /      | /  __  \\  |   \\/   | |   ____|\n";
	cout << "\t\t      \\   \\/    \\/   /  |  |__   |  |     |  ,----'|  |  |  | |  \\  /  | |  |__   \n";
	cout << "\t\t       \\            /   |   __|  |  |     |  |     |  |  |  | |  |\\/|  | |   __|  \n";
	cout << "\t\t        \\    /\\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____ \n";
	cout << "\t\t         \\__/  \\__/     |_______||_______| \\______| \\______/  |__|  |__| |_______|\n";
	cout << "\n";

	Sleep(s);
	system("cls");

	cout << "\n\n";
	cout << "\n\t\t\t\t\t    .___________.   ______   ";
	cout << "\n\t\t\t\t\t    |           |  /  __  \\  ";
	cout << "\n\t\t\t\t\t    `---|  |----` |  |  |  | ";
	cout << "\n\t\t\t\t	   	|  |      |  |  |  | ";
	cout << "\n\t\t\t\t		|  |      |  `--'  | ";
	cout << "\n\t\t\t\t\t        |__|	   \\______/  ";

	Sleep(s);
	system("cls");

	cout << "\n\n";
	cout << "\n\t\t\t\t\t  _______ .______      ___      ";
	cout << "\n\t\t\t\t\t /  _____||   _  \\    /   \\     ";
	cout << "\n\t\t\t\t\t|  |  __  |  |_)  |  /  ^  \\    ";
	cout << "\n\t\t\t\t\t|  | |_ | |   ___/  /  /_\\  \\   ";
	cout << "\n\t\t\t\t\t|  |__| | |  |     /  _____  \\  ";
	cout << "\n\t\t\t\t\t \\______| | _|    /__/     \\__\\ ";

	Sleep(s);
	system("cls");

	cout << "\n\n";
	cout << "\n     ______     ___       __        ______  __    __   __          ___   .___________.  ______   .______      ";
	cout << "\n    /      |   /   \\     |  |      /      ||  |  |  | |  |        /   \\  |           | /  __  \\  |   _  \\     ";
	cout << "\n   |  ,----'  /  ^  \\    |  |     |  ,----'|  |  |  | |  |       /  ^  \\ `---|  |----`|  |  |  | |  |_)  |    ";
	cout << "\n   |  |      /  /_\\  \\   |  |     |  |     |  |  |  | |  |      /  /_\\  \\    |  |     |  |  |  | |      /     ";
	cout << "\n   |  `----./  _____  \\  |  `----.|  `----.|  `--'  | |  `----./  _____  \\   |  |     |  `--'  | |  |\\  \\----.";
	cout << "\n    \\______/__/     \\__\\ |_______| \\______| \\______/  |_______/__/     \\__\\  |__|      \\______/  | _| `._____|";

	Sleep(s);
	system("cls");
}

void exit_msg()
{
	int s = 2000;

	system("cls");

	cout << "\n\n";
	cout << "\t\t\t    __________   ___  __  .___________. __  .__   __.   _______ \n";
	cout << "\t\t\t   |   ____\\  \\ /  / |  | |           ||  | |  \\ |  |  /  _____|\n";
	cout << "\t\t\t   |  |__   \\  V  /  |  | `---|  |----`|  | |   \\|  | |  |  __  \n";
	cout << "\t\t\t   |   __|   >   <   |  |     |  |     |  | |  . `  | |  | |_ | \n";
	cout << "\t\t\t   |  |____ /  .  \\  |  |     |  |     |  | |  |\\   | |  |__| | \n";
	cout << "\t\t\t   |_______/__/ \\__\\ |__|     |__|     |__| |__| \\__|  \\______| \n";

	Sleep(s);
	system("cls");

	cout << "\n\n";
	cout << "\n\t\t\t\t\t  _______ .______      ___      ";
	cout << "\n\t\t\t\t\t /  _____||   _  \\    /   \\     ";
	cout << "\n\t\t\t\t\t|  |  __  |  |_)  |  /  ^  \\    ";
	cout << "\n\t\t\t\t\t|  | |_ | |   ___/  /  /_\\  \\   ";
	cout << "\n\t\t\t\t\t|  |__| | |  |     /  _____  \\  ";
	cout << "\n\t\t\t\t\t \\______| | _|    /__/     \\__\\ ";

	Sleep(s);
	system("cls");

	cout << "\n\n";
	cout << "\n     ______     ___       __        ______  __    __   __          ___   .___________.  ______   .______      ";
	cout << "\n    /      |   /   \\     |  |      /      ||  |  |  | |  |        /   \\  |           | /  __  \\  |   _  \\     ";
	cout << "\n   |  ,----'  /  ^  \\    |  |     |  ,----'|  |  |  | |  |       /  ^  \\ `---|  |----`|  |  |  | |  |_)  |    ";
	cout << "\n   |  |      /  /_\\  \\   |  |     |  |     |  |  |  | |  |      /  /_\\  \\    |  |     |  |  |  | |      /     ";
	cout << "\n   |  `----./  _____  \\  |  `----.|  `----.|  `--'  | |  `----./  _____  \\   |  |     |  `--'  | |  |\\  \\----.";
	cout << "\n    \\______/__/     \\__\\ |_______| \\______| \\______/  |_______/__/     \\__\\  |__|      \\______/  | _| `._____|";

	Sleep(s);
	system("cls");
}