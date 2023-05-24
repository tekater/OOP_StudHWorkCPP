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

    int day;
    int month;
    int year;

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
    Student(const char* Uname, int* Umarks, int Usize,int d,int m,int y) {

        keyName(Uname);

        keyMarks(Umarks, Usize);

        day = d;
        month = m;
        year = y;

    }
    /*
    Student(const char* Uname) {
        int Usize = 3;

        keyName(Uname);

        keyMarks(new int[3] {1, 1, 1}, 3);
    }
    Student(int* Umarks, int Usize) {

        keyName("Noname");

        keyMarks(new int[3] {1, 1, 1}, 3);

    }
    Student() {

        keyName("Noname");

        keyMarks(new int[3] {1, 1, 1}, 3);

    }*/

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
        cout << "\nДата рождения: " << day << "." << month << "." << year << "\n";
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

    

    Date date(10, 2, 2000);

    Student oleg{ "Олег", marks,size, date.getDay(),date.getMonth(),date.getYear()};
    oleg.print();
}
