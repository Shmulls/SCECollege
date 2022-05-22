#include "College.h"

College::~College()
{
	for (int i = 0; i < size_std; i++)
	{
		delete[]array_std;
	}
	delete[]array_std;
}

College::College(Student** array_student, int size)
{
	size_std = size;
	array_std = new Student * [size];
	if (array_std == NULL)
	{
		return;
	}

	for (int i = 0; i < size; i++)
	{
		array_std[i] = array_student[i];
	}
} 
bool College::add_student()
{
	long id;
	cout << "Please enter id: ";
	cin >> id;

	for (int i = 0; i < size_std; i++)
	{
		if (array_std[i]->getID() == id)
		{
			cout << "This student already exsit in the data base!" << endl;
			return false;
		}
	}

	char name[20];
	int choose = 0;
	cout << "Please enter the name of the new student: ";
	cin >> name;

	do
	{
		cout << "Please enter the type of student: " << endl << "[1] Preparatory" << endl << "[2] B.A." << endl << "[3] M.A." << endl;
		cin >> choose;
	} while (choose != 1 && choose != 2 && choose != 3);

	switch (choose)
	{
	case 1:
	{
		bool length;
		int number = 0;

		do
		{
			cout << "Please choose the length of the preparatory:" << endl << "[1] Short" << endl << "[2] Long" << endl;
			cin >> number;
		} while (number != 1 && number != 2);

		if (number == 1)
		{
			length = true;
		}
		else
		{
			length = false;
		}

		
		int new_size = size_std + 1;
		Student** temp = new Student * [new_size];
		if (temp == NULL)
		{
			cout << "temp is NULL!" << endl;
			return false;
		}

		for (int i = 0; i < size_std; i++) // Store in temp array the old array + empty spot.
		{
			temp[i] = array_std[i];
		}

		temp[new_size - 1] = new Student0(name, id, length); // Now i'm adding the new student to the temp array.

		delete[]array_std;

		array_std = new Student * [new_size];
		if (array_std == NULL)
		{
			cout << "Array_std is NULL!" << endl;
			return false;
		}

		array_std = temp; // Because it's an address I will do shallow copy.
		size_std++;
		break;
	}

	case 2:
	{
		Course* crse = NULL;
		int year, size = 0;

		cout << "Please enter what year the student of B.A. : ";
		cin >> year;

		int new_size = size_std + 1;
		Student** temp = new Student * [new_size];

		if (temp == NULL)
		{
			cout << "temp is NULL!" << endl;
			return false;
		}

		for (int i = 0; i < size_std; i++) // store in temp array the old array + empty spot.
		{
			temp[i] = array_std[i];
		}

		temp[new_size - 1] = new Student1(name, id, crse, year, size); // Now i'm adding the new student to the temp array.

		delete[]array_std;

		array_std = new Student * [new_size];
		if (array_std == NULL)
		{
			cout << "Array_std is NULL!" << endl;
			return false;
		}

		array_std = temp; // Because it's an array of pointers to addresses I make a shallow copy.
		size_std++;
		break;
	}

	case 3:
	{
		char thsis[20], supervisor[20];

		cout << "Please enter thsis subject: ";
		cin >> thsis;

		cout << "Please enter supervisor name: ";
		cin >> supervisor;

		int new_size = size_std + 1;
		Student** temp = new Student * [new_size];

		if (temp == NULL)
		{
			cout << "temp is NULL!" << endl;
			return false;
		}

		for (int i = 0; i < size_std; i++) // store in temp array the old array + empty spot.
		{
			temp[i] = array_std[i];
		}

		temp[new_size - 1] = new Student2(name, id, thsis, supervisor); // Now i'm adding the new student to the temp array.

		delete[]array_std;

		array_std = new Student * [new_size];
		if (array_std == NULL)
		{
			cout << "Array_std is NULL!" << endl;
			return false;
		}

		array_std = temp; // Because it's an array of pointers to addresses I make a shallow copy.
		size_std++;
		break;
	}
	}

	return true;
}

bool College::add_grade(long id, char* course_name, char* lecturer, int grade)
{
	for (int i = 0; i < size_std; i++)
	{
		if (array_std[i]->getID() == id)
		{
			Student1* temp = dynamic_cast<Student1*>(array_std[i]);
			if (temp)
			{
				for (int j = 0; j < temp->getSize(); j++)
				{
					if (strcmp(temp->getCourse()[j].getCourseName(), course_name) == 0)
					{
						temp->getCourse()[j].set_course(lecturer, grade);
						return true;
					}
				}

				Course* new_arr;
				new_arr = new Course[sizeof(temp->getCourse()) + 1];
				if (new_arr == NULL)
				{
					cout << "new_arr NULL" << endl;
					return false;
				}
				
				for (int i = 0; i < temp->getSize(); i++)
				{
					new_arr[i] = temp->getCourse()[i];
				}
				new_arr[temp->getSize()] = Course(course_name, lecturer, grade);

				temp->set_Size(temp->getSize() + 1);
				delete[]temp->getCourse();
				temp->set_Course(new_arr);

				return true;
			}
		}
		
	}
	
	return false;
}

void College::print_all() const
{
	for (int i = 0; i < size_std; i++)
	{
		array_std[i]->print();
	}
}

void College::print_excellent() const
{
	for (int i = 0; i < size_std; i++)
	{
		if (array_std[i]->if_Outstanding() == true)
		{
			array_std[i]->Student::print();
		}
	}
}

void College::find_types(Student** array_student, int size, int &z, int &f, int &s)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(array_student[i]->get_type(), "Student0") == 0)
			z++;
		else if (strcmp(array_student[i]->get_type(), "Student1") == 0)
			f++;
		else
			s++;
	}
}

int College::supervisor(char* name_super) 
{
	int counter = 0;
	for (size_t i = 0; i < size_std; i++)
	{
		Student2* temp = dynamic_cast<Student2*>(array_std[i]);
		if (temp)
		{
			if (strcmp(temp->getSuper(), name_super) == 0)
			{
				array_std[i]->print_name();
				counter++;
			}
		}

	}
	return counter;
}

void College::menu()
{
	int choose = 0;
	
	while(choose != 7)
	{
		cout << "[1] Add Student" << endl;
		cout << "[2] Add grade" << endl;
		cout << "[3] Print all" << endl;
		cout << "[4] Print excellent" << endl;
		cout << "[5] Types of student" << endl;
		cout << "[6] Supervisor" << endl;
		cout << "[7] Quit" << endl;

		cin >> choose;


		switch (choose)
		{
		case 1:
		{
			if (add_student() == true)
				cout << "Student added!" << endl;
			else
				cout << "Student add failed" << endl;
			break;
		}
		case 2:
		{
			char course_name[20], lecturer[20];
			long id;
			int grade;

			cout << "Please enter id: ";
			cin >> id;
			cout << endl;

			cout << "Please course name: ";
			cin >> course_name;
			cout << endl;

			cout << "Please lecturer name: ";
			cin >> lecturer;
			cout << endl;

			cout << "Please grade: ";
			cin >> grade;
			cout << endl;

			if (add_grade(id, course_name, lecturer, grade) == true)
				cout << "Grade added!" << endl;
			else
				cout << "Grade add failed" << endl;
			break;
		}
		case 3:
		{
			print_all();
			break;
		}
		case 4:
		{
			print_excellent();
			break;
		}
		case 5:
		{
			int z = 0, f = 0, s = 0;
			find_types(array_std, size_std, z, f, s);

			cout << "Student prepares amount: " << z << endl;
			cout << "BA student amount: " << f << endl;
			cout << "MA student amount: " << s << endl;
			break;
		}
		case 6:
		{
			char name_super[20];
			int rtrn;
			cout << "Please enter name of supervisor: ";
			cin >> name_super;
			cout << endl;

			rtrn = supervisor(name_super);

			cout << "The number of students that " << name_super << " is their lecturer is: [" << rtrn << "]" << endl;
			break;
		}
		case 7:
		{
			cout << "Thank you!" << endl;
			break;
		}
		}

	}
}
