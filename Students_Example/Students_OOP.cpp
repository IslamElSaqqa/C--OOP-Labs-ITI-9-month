#include <iostream>
#include <cstring>
#include <string>
using namespace std;


// members schoolname but all students should beling to the same schoolname, 
// but if the student changed his school name, the schoolname should be also changed
class Student {
private:
    int id;
    char* name;
    float grades[3];
    static int count;
    static char schoolName[];

public:
    // Default constructor
    Student() {
        id = 0;
        name = new char[8];
        strcpy(name, "unknown");
        strcpy(schoolName, "unknown");
        grades[0] = grades[1] = grades[2] = 0.0f;
        count++;
    }

    // Parameterized constructor
    Student(int _id, const char _name[], float g[], const char _schoolName []) {
        id = _id;
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
        strcpy(schoolName, _schoolName);
        for (int i = 0; i < 3; i++)
            grades[i] = g[i];
        count++;
    }

    // Copy constructor
    Student(const Student& re) {
        cout << "Copy constructor called\n";
        id = re.id;
        name = new char[strlen(re.name) + 1];
        strcpy(name, re.name);
        strcpy(schoolName, re.schoolName);

        for (int i = 0; i < 3; i++)
            grades[i] = re.grades[i];
        count++;
    }

    // Assignment operator
    Student& operator=(const Student& re) {
        if (this != &re) {
            id = re.id;
            delete[] name;
            name = new char[strlen(re.name) + 1];
            strcpy(name, re.name);
            for (int i = 0; i < 3; i++)
                grades[i] = re.grades[i];
        }
        return *this;
    }

    // Destructor
    ~Student() {
        delete[] name;
        count--;
    }

    // Setters
    void setID(int i) { id = i; }
    void setName(const char n[]) {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    void setSchoolName (const char n[])
    {
        strcpy(schoolName, n);
    }
    void setGrade(int index, float g) {
        if (index >= 0 && index < 3)
            grades[index] = g;
    }

    // Getters
    int getID() const { return id; }
    const char* getName() const { return name; }
    float getGrade(int index) const { return (index >= 0 && index < 3) ? grades[index] : -1; }

    float calculateSum() const {
        return grades[0] + grades[1] + grades[2];
    }

    // Get count
    static int getCount ()
    {
        return count;
    }
    static char *getSchoolName ()
    {
        return schoolName;
    }



    // Operator overloads
    Student operator+(int m) {
        Student temp = *this;
        temp.id += m;
        return temp;
    }

    Student operator+(const char* c) {
        Student temp = *this;
        int len1 = strlen(name);
        int len2 = strlen(c);
        delete[] temp.name;
        temp.name = new char[len1 + len2 + 1];
        strcpy(temp.name, name);
        strcat(temp.name, c);
        return temp;
    }

    Student operator+(const Student& s) {
        Student temp;
        temp.id = id + s.id;
        for (int i = 0; i < 3; i++)
            temp.grades[i] = grades[i] + s.grades[i];
        int len1 = strlen(name);
        int len2 = strlen(s.name);
        delete[] temp.name;
        temp.name = new char[len1 + len2 + 2];
        strcpy(temp.name, name);
        strcat(temp.name, " ");
        strcat(temp.name, s.name);
        return temp;
    }

    Student operator++() {  // prefix
        ++id;
        return *this;
    }
    Student operator++(int) {  // postfix
        Student temp = *this;
        ++id;
        return temp;
    }

    operator int() { return id; }
    operator char* () { return name; }

    bool operator==(const Student& s) const {
        if (id != s.id) return false;
        if (strcmp(name, s.name) != 0) return false;
        for (int i = 0; i < 3; i++)
            if (grades[i] != s.grades[i])
                return false;
        return true;
    }

    friend Student operator+(int m, Student s) { return s + m; }
    friend Student operator+(const char* c, Student s) { return s + c; }
};

int Student:: count = 0;
char Student ::schoolName[] = "ITI";

// Fill function
Student fillStudent() {
    Student s;
    int id;
    char n[50];
    char schoolName[5];
    cout << "Enter ID: ";
    cin >> id;
    s.setID(id);

    cin.ignore();
    cout << "Enter name: ";
    cin.getline(n, 50);
    s.setName(n);

    cout << "Enter schoolName: ";
    cin.getline(schoolName, 5);
    s.setSchoolName(schoolName);

    cout << "Enter 3 grades:\n";
    for (int i = 0; i < 3; i++) {
        float g;
        cout << "Grade " << i + 1 << ": ";
        cin >> g;
        s.setGrade(i, g);
    }

    return s;
}


// to use copy constructor
void PrintStudent(Student s) {
    cout << "ID: " << s.getID() << endl;
    cout << "Name: " << s.getName() << endl;
    cout << "School Name: " << s.getSchoolName() << endl;
    cout << "No of Students:  " << s.getCount() << endl;
    cout << "Grades: ";
    for (int i = 0; i < 3; i++)
        cout << s.getGrade(i) << " ";
    cout << "\nTotal Sum = " << s.calculateSum() << endl;
}

int main() {
    cout << "=== [s0] Create using param constructor ===\n";
    float g[3] = { 11.6f, 20.12f, 35.5f };
    Student s0(20, "Islam", g, "ABC School");

    PrintStudent(s0);

    cout << "\nFInal student count: " << Student::getCount() << endl;
    cout << "\n=== [s1] Create using default constructor + fill ===\n";
    Student s1 = fillStudent();
    PrintStudent(s1);

    cout << "\n=== [s2] = s0 + 5 (adds to id) ===\n";
    Student s2 = s0 + 5;
    PrintStudent(s2);

    cout << "\n=== [s3] = 7 + s0 (friend) ===\n";
    Student s3 = 7 + s0;
    PrintStudent(s3);

    cout << "\n=== [s4] = s0 + \"Mahmoud\" (append name) ===\n";
    Student s4 = s0 + "Mahmoud";
    PrintStudent(s4);

    cout << "\n=== [s5] = \"Eng.\" + s0 (prefix name) ===\n";
    Student s5 = "Eng." + s0;
    PrintStudent(s5);

    cout << "\n=== [s6] = s0 + s2 (combine ids, names, grades) ===\n";
    Student s6 = s0 + s2;
    PrintStudent(s6);

    cout << "\n=== Post-increment s0++ ===\n";
    Student s7 = s0++;
    cout << "[s7] Returned OLD s0:\n";
    PrintStudent(s7);

    cout << "[s0] AFTER post-increment:\n";
    PrintStudent(s0);

    cout << "\n=== Pre-increment ++s0 ===\n";
    ++s0;
    PrintStudent(s0);

    cout << "\n=== Cast s0 to int ===\n";
    int idValue = (int)s0;
    cout << "ID = " << idValue << "\n";

    cout << "\n=== Cast s0 to const char* ===\n";
    const char* nameValue = (const char*)s0;
    cout << "Name = " << nameValue << "\n";

    cout << "\n=== [s8] = s2 (assignment operator) ===\n";
    Student s8;
    s8 = s2;
    PrintStudent(s8);

    cout << "\n=== Compare s0 and s2 (operator==) ===\n";
    if (s0 == s2)
        cout << "s0 and s2 are SAME\n";
    else
        cout << "s0 and s2 are NOT same\n";
    return 0;
}
