#include <iostream>
#include <iostream>
#include <cstring>
using namespace std;

class Person {
protected:
    char name[50];
    int id;
public:
    Person() : id(0) {
        strcpy(name, "Default Name");
    }
    Person(int Id, const char* newName) : id(Id) {
        strncpy(name, newName, 49);
        name[49] = '\0'; 
    }
    void setName(const char* newName) {
        strncpy(name, newName, 49);
        name[49] = '\0'; 
    }
    void setId(int newId) {
        id = newId;
    }
    char *getName() {
        return name;
    }
    int getId() const {
        return id;
    }
    void Print() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }

}; 
class employee : public Person {
private:
    float salary;
public:
    employee() : Person(), salary(0.0f) {}
    employee(int Id, const char* newName, float sal) : Person(Id, newName) {
        salary = sal;
    }
    void setSalary(float sal) {
        salary = sal;
    }
    float getSalary() const {
        return salary;
    }
    void Print() const {
        Person::Print();
        cout << "Salary: " << salary << endl;
    }
};

// Product Purchased for each customer
class customer : public Person {
private:
    int ProductPurchase;
public:
    customer() : Person(), ProductPurchase(0) {}
    customer(int Id, const char* newName, int pCount) : Person(Id, newName) {
        ProductPurchase = pCount;
    }
    void setProductPurchase(int pCount) {
        ProductPurchase = pCount;
    }
    int getProductPurchase() const {
        return ProductPurchase;
    }
    void Print() const {
        Person::Print();
        cout << "Product Purchase Count: " << ProductPurchase << endl;
    }
}; 


int main()
{
    customer c1(1, "Islam", 5);
    employee e1(2, "Shawky", 50000.0f);
    cout << "Customer Details:" << endl;
    c1.Print();
    cout << "\nEmployee Details:" << endl;
    e1.Print();


    return 0;
}