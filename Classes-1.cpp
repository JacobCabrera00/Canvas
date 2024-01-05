#include "Classes.h"
#include <ostream>
#include <algorithm>

//student.cpp
Student::Student(){
    name = "";
    id = "";
}

Student::Student(const std::string& newname, const std::string& newid, char newclassification){
    name = newname;
    id = newid;
    classification = newclassification;
}
std::string Student::getID()const{
    return id;
}

std::ostream& operator<<(std::ostream& print, const Student& student){
    print << "Student Name(" << student.name << ")  ID(" << student.id << ")  Classification(" << student.classification << ")";
    return print; 
}

//Roster.cpp
Roster::Roster(){
    size = 0;
    capacity = 5;
    contents = new Student[5];
} 

Roster::Roster(const Roster& r){
    size = r.size;
    capacity = r.capacity;
    contents = new Student[capacity];
    for(int i = 0; i < size; i++){
        contents[i] = r.contents[i];
    }
}

Roster& Roster::operator=(const Roster& r){
    size = r.size;
    capacity = r.capacity;
    delete [] contents;
    contents = new Student[capacity];
    for(int i = 0; i < size; i++){
        contents[i] = r.contents[i];
    }

    return *this;
}

Roster::~Roster() {
    delete[] contents;
}

void Roster::addStudent(const Student& student) {
    if (size == capacity) {
        Student* newcontents = new Student[capacity + 5];
        for(int i = 0; i < size; i++){
            newcontents[i] = contents[i];
        }
        delete [] contents;
        contents = newcontents;
        capacity += 5;
    }
    contents[size++] = student;
}

void Roster::dropStudent(const std::string& studentId){
    for (int i = 0; i < size; ++i) {
        if (contents[i].getID() == studentId) {
            for (int j = i; j < size - 1; ++j) {
                contents[j] = contents[j + 1];
            }
            --size;
            return;
        }
    }
}

std::ostream& operator<<(std::ostream& print, const Roster& roster) {
    for (int i = 0; i < roster.size; ++i) {
        print << roster.contents[i] << std::endl;
    }
    return print;
}

//Course.cpp

Course::Course(){
    name = "";
    code = "";
    Roster roster;
}

Course::Course(const std::string& n, const std::string& c) {
    name = n;
    code = c;
}   

std::string Course::getCode() const{
    return code;
}


void Course::addStudent(const Student& studentId){
    roster.addStudent(studentId);
}

void Course::dropStudent(const std::string& studentId){
    roster.dropStudent(studentId);
}

std::ostream& operator<<(std::ostream& print, const Course& course){
    print << "Course Name: " << course.name << "   Coure Code(" << course.code << ")   ";
    print << "Roster: " << course.roster;
    return print;
}





