#include "Classes.h"
#include <iostream>
#include <ostream>


int main(){
    std::string menu;
    std::string courseId;
    std::string removecourseCode;
    std::string removestudentId;
    std::string studentName;
    std::string studentId;
    char studentClassification;
    std::string courseName;
    std::string courseCode;
    int removeCourse;
    const int CourseCart = 5;
    int Coursesize = 0;
    Course* courses = new Course[CourseCart];
    int capacity = 5;
    int rosterSize = 0;
    Roster* roster = new Roster[capacity];



    while(menu != "6"){
        std::cout << "---------------Menu---------------" << std::endl;
        std::cout << "1. Create a course" << std::endl;
        std::cout << "2. Remove a course" << std::endl;
        std::cout << "3. List all courses" << std::endl;
        std::cout << "4. Enroll a student in a course" << std::endl;
        std::cout << "5. Remove a student from a course" << std::endl;
        std::cout << "6. Quit" << std::endl;
        std::cout << "Enter your Choice: ";
        std::cin >> menu;

        if(menu == "1"){
            std:: cout << "\n";
            std::cout << "Enter in the Course Name: ";
            std::cin >> courseName;
            std::cout << "Enter in the Course Code: ";
            std::cin >> courseCode;
            if(Coursesize != 5){
            courses[Coursesize] = Course(courseName, courseCode);
            Coursesize++;
            }
            else{
                std::cout << "The capcity of Courses is reached" << std::endl;
                std::cout << "Remove a course if you wish to add a course" << std::endl;
            }
            courseName = "";
            courseCode = "";  
        }
        if(menu == "2"){
            std::cout << "\n";
            std::cout << "Course List" << std::endl;
            for(int i = 0; i < Coursesize; i++){
                std::cout << i + 1 << ". " << courses[i] << std::endl;
            }

            std::cout << "Enter Course to Remove: ";
            std::cin >> removeCourse;
            
            for(int i = removeCourse - 1; i < Coursesize - 1; i++){
                courses[i] = courses[i + 1];
            }
            Coursesize--;
        }
        if(menu == "3"){
            std::cout << "\n";
            std::cout << "Course List" << std::endl;
            for(int i = 0; i < Coursesize; i++){
                std::cout << i + 1 << ". " << courses[i] << std::endl;
            }
        }
        if(menu == "4"){
            std::cout << "Enter Student Name: ";
            std::cin >>studentName;
            std::cout << "Enter Student Id: ";
            std::cin >> studentId;
            std::cout << "Enter Student Classification: ";
            std::cin >> studentClassification;
            std::cout << "Enter the Course Code you wish to enroll in: ";
            std::cin >> courseId;

            for(int i = 0; i < CourseCart; i++){
                if(courses[i].getCode() == courseId){
                    courses[i].addStudent(Student(studentName, studentId, studentClassification));
                }
            }

        }
        
        if(menu == "5"){
             std::cout << "Enter the Course Code you want to remove a student from: ";
             std::cin >> removecourseCode;
             std::cout << "Enter the Student Id you wish to remove: ";
             std::cin >> removestudentId;

             for(int i = 0; i < CourseCart; i++){
                if(courses[i].getCode() == removecourseCode){
                    courses[i].dropStudent(removestudentId);
             }
        }
        std::cout <<"\n";

    };
    delete []courses;
    }