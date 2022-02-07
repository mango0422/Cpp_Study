#include <iostream>
#include <cstring>
using namespace std;

class Person{
    public:
        void Sleep(){
            cout<<"Sleep"<<endl;
        }
};

class Student : public Person {
    public:
        void Study(){
            cout<<"Study"<<endl;
        }
};

class PartTimeStudent : public Student{
    public:
        void Work(){
            cout<<"Work"<<endl;
        }
};

int main(void){
    Person * ptr1 = new Student();
    Person * ptr2 = new PartTimeStudent();
    Student * ptr3 = new PartTimeStudent();
    ptr1->Sleep();
    ptr2->Sleep();
    ptr3->Study();
    delete ptr1; delete ptr2; delete ptr3;
    return (0);
}

/*
 * IS-A 관계의 성립 생각해보자.
 * 학생(Student)은 사람(Person)이다.
 * 근로학생(PartTimeStudent)은 학생(Student)이다.
 * 근로학생(PartTimeStudent)은 사람(Person)이다.
*/