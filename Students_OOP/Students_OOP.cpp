#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Student {
private:
    int id;
    char name[30];
    int numGrades;
    float* grades;

public:
    // Default constructor
    Student() {
        id = 0;
        strcpy_s(name, sizeof(name), "");
        numGrades = 0;
        grades = new float[numGrades];
    }

    // Parameterized constructor
    Student(int _id, const char _name[], int _numGrades = 0) {
        id = _id;
        strcpy_s(name, sizeof(name), _name);
        numGrades = _numGrades;
        grades = new float[numGrades]();
    }

    // Copy constructor (deep copy)
    Student(const Student& re) {
        cout << "Copy constructor called\n";
        id = re.id;
        numGrades = re.numGrades;
        strcpy_s(name, sizeof(name), re.name);

        grades = new float[numGrades];
        for (int i = 0; i < numGrades; i++)
            grades[i] = re.grades[i];
    }

    // Assignment operator (deep copy)
    Student& operator=(const Student& re) {
        if (this != &re) {
            id = re.id;
            numGrades = re.numGrades;
            strcpy_s(name, sizeof(name), re.name);

            delete[] grades;
            grades = new float[numGrades];
            for (int i = 0; i < numGrades; i++)
                grades[i] = re.grades[i];
        }
        return *this;
    }

    // Destructor
    ~Student() {
        delete[] grades;
    }

    // Setters
    void setID(int i) { id = i; }
    void setName(const char n[]) { strcpy_s(name, sizeof(name), n); }
    void setGrade(int index, float g) { if (index >= 0 && index < numGrades) grades[index] = g; }
    void setNumGrades(int n) { numGrades = n; }

    void allocateGrades() {
        delete[] grades;
        grades = new float[numGrades]();
    }

    // Getters
    int getID() const { return id; }
    const char* getName() const { return name; }
    float getGrade(int index) const { return (index >= 0 && index < numGrades) ? grades[index] : -1; }
    int getNumGrades() const { return numGrades; }

    float calculateSum() const {
        float s = 0;
        for (int i = 0; i < numGrades; i++)
            s += grades[i];
        return s;
    }
};

// Non-member functions
void fillStudent(Student& s) {
    int id, n;
    string name;

    cout << "Enter ID: ";
    cin >> id;
    s.setID(id);

    cin.ignore();
    cout << "Enter name: ";
    getline(cin, name);
    s.setName(name.c_str());

    cout << "Enter number of grades for this student: ";
    cin >> n;
    s.setNumGrades(n);
    s.allocateGrades();

    cout << "Enter " << s.getNumGrades() << " grades:\n";
    for (int i = 0; i < s.getNumGrades(); i++) {
        float g;
        cout << "Grade " << i + 1 << ": ";
        cin >> g;
        s.setGrade(i, g);
    }
}

void printStudent(const Student& s) {
    cout << "\nStudent Info\n";
    cout << "ID: " << s.getID() << endl;
    cout << "Name: " << s.getName() << endl;
    cout << "Grades: ";
    for (int i = 0; i < s.getNumGrades(); i++)
        cout << s.getGrade(i) << " ";
    cout << "\nTotal Sum = " << s.calculateSum() << endl;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* arr = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << endl;
        fillStudent(arr[i]);
    }

    cout << "\nOriginal Students:\n";
    for (int i = 0; i < n; i++)
        printStudent(arr[i]);

    // Demonstrate deep copy
    cout << "\nCopying students using copy constructor:\n";
    Student* copiedArr = new Student[n];
    for (int i = 0; i < n; i++) {
        copiedArr[i] = arr[i];   
        Student temp = arr[i];    // copy constructor
        printStudent(temp);
    }

    delete[] arr;
    delete[] copiedArr;

    return 0;
}
