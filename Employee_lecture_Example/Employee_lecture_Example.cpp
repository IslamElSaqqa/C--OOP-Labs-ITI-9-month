#include <iostream>
#include <cstring>


using namespace std;

class Employee 
{
	int id;
	float salary;
	char* name; // Dynamic allocation

	// Constructors
	public:

		// Default constructor
		Employee() 
		{
			cout << "Default Construcor called " << endl;
			id = 1;
			salary = 1000.0f;
			name = new char[8];
			strcpy_s(name, 8, "unknown");	// strlen = 8, including \0 for null terminator
		}

		// parametrized Constructor
		Employee(int id, float salary, char n[])
		{
			cout << "Parametrized Construcor called " << endl;
			this->id = id;
			this->salary = salary;
			name = new char[strlen(n) + 1];	// allocate the char array in the heap
			strcpy_s(name, strlen(n) + 1, n);
		}

		// copy constructor to avoid bitwise (memberwise copy) to achieve deep copy
		Employee(const Employee& re)
		{
			cout << "Copy Construcor called " << endl;
			this->id = re.id;
			this->salary = re.salary;
			this->name = new char[strlen(re.name) + 1];
			strcpy_s(name,strlen(re.name) + 1, re.name);
		}


		// Assignment Overloading to apply deep copy
		Employee& operator= (const Employee& re)
		{
			if (this != &re) {
				id = re.id;
				salary = re.salary;
				delete[] name;
				name = new char[strlen(re.name) + 1];
				strcpy_s(name, strlen(re.name) + 1, re.name);
			}
			
			return *this;
		
		}

		// setters
		void setId(int id){this->id = id;}
		void setSalary(float salary){this->salary = salary;}
		void setName(char name [])
		{
			// delete the old name from the heap when setting new name.
			delete [] this->name;
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}

		// getters
		int getId(){return id;}
		float getSalary() { return salary; }
		char* getName() { return name; }

		// destructor
		~Employee() { delete [] name; }
};

Employee fillEmp();
void printE(Employee emp);	// calls copy constructor for deep copy
void printE(); // calls default constructor only using shallow copy


int main()
{
	Employee emp , e;

	// Memory Leak if there is no assignment overloading operator
	emp = fillEmp();	// Bitwise copy (we avoided it using copy constructor) 
	printE(); // calls default constructor
	cout << "----------" << endl;
	cout << endl;
	e = fillEmp();
	printE(e); // calls copy constructor
	
}

Employee fillEmp()  // by value
{
	Employee e;		// local
	int i; float s; char n[20];

	cout << "Enter id: ";
	cin >> i;

	cout << "\nEnter salary: ";
	cin >> s;

	cout << "\nEnter Name: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer

	cin.getline(n, 20);  // read name correctly

	e.setName(n);
	e.setSalary(s);
	e.setId(i);

	return e;
}

// uses copy constructor to solve bitwise copy
void printE(Employee emp)
{
	cout << "Id: " << emp.getId() << endl;
	cout << "Employee Name: " << emp.getName() << endl;
	cout << "Salary: " << emp.getSalary() << endl;
}

// bitwise copy
void printE() 
{
	Employee emp;
	cout << "Id: " << emp.getId() << endl;
	cout << "Employee Name: " << emp.getName() << endl;
	cout << "Salary: " << emp.getSalary() << endl;

}
