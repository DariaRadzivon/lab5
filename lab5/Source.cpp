#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> 

using namespace std;

// base class Persona
class Persona {
protected:
    string name;
    int age;

public:
    Persona(const string& name, int age) : name(name), age(age) {}

    // A virtual function for changing the age of a person
    virtual void update() {
        cout << name << " (Особа): Змінюється вік на 1 рік." << endl;
        age++;
    }

    virtual void display() const {
        cout << "Ім'я: " << name << ", Вік: " << age << endl;
    }
};

// A virtual function for changing the age of a person
class Student : public Persona {
private:
    int course;

public:
    Student(const string& name, int age, int course) : Persona(name, age), course(course) {}

    // Redefined function to move to the next course
    void update() override {
        cout << name << " (Студент): Перехід на наступний курс." << endl;
        course++;
    }

    void display() const override {
        cout << "Ім'я: " << name << ", Вік: " << age << ", Курс: " << course << endl;
    }
};

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // Creating objects of classes Person and Student
    Persona* person1 = new Persona("Олександр", 30);
    Persona* student1 = new Student("Анна-Марія", 20, 1);

    // Call the update function for each object
    person1->display();
    person1->update();
    person1->display();

    student1->display();
    student1->update();
    student1->display();

    // Freeing memory
    delete person1;
    delete student1;

    return 0;
}
