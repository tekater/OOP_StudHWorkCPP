#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;
class Date {
    int day;
    int month;
    int year;
public:
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    Date() : Date(1, 2, 2000) {};

    void setDay(int d) {
        day = d;
    }
    void setMonth(int m) {
        month = m;
    }
    void setYear(int y) {
        year = y;
    }

    int getDay() {
        return day;
    }
    int getMonth() {
        return month;
    }
    int getYear() {
        return year;
    }
};

class Student {
    char* name;
    int* marks;
    int size;

    Date start;

    void keyName(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    void keyMarks(int* Umarks, int Usize) {
        marks = new int[Usize];

        for (int i = 0; i < Usize; i++) {
            marks[i] = Umarks[i];
        }

        size = Usize;
    }

public:
    Student(const char* Uname, int* Umarks, int Usize, Date start) :start{ start } {

        keyName(Uname);

        keyMarks(Umarks, Usize);

    }

    void setName(const char* Uname) {
        delete[] name;

        keyName(Uname);
    }

    void setMarks(int* Umarks, int Usize) {
        delete[] marks;
        keyMarks(Umarks, Usize);
    }

    void print() {
        cout << "Имя: " << name << endl;
        cout << "Оценки: ";
        for (int i = 0; i < size; i++) {
            cout << marks[i] << " ";
        }
        cout << "\nДата рождения: " << start.getDay() << "." << start.getMonth() << "." << start.getYear() << "\n";
    }

    ~Student() {
        cout << name << " умер\n";
        if (name) {
            delete[]name;
        }

        if (marks) {
            delete[] marks;
        }
    }
};

void main() {

    setlocale(0, "");
    srand(time(NULL));
    const int size = 5;
    int marks[size]{ 1,5,3,4,2 };

    Student oleg{ "Олег", marks,size, {10,2,2000} };
    oleg.print();
}
