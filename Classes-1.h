#include <string>


class Student{
    friend std::ostream& operator<<(std::ostream& print, const Student &student);
    private:
    std::string name;
    std::string id;
    char classification;
    public:
    Student();
    Student(const std::string& name, const std::string& id, char classification);
    std::string getID() const;
};


class Roster{
    friend std::ostream& operator<<(std::ostream& print, const Roster &roster);
    private:
    Student* contents;
    int size;
    int capacity;
    public:
    Roster();
    Roster(const Roster& r);
    ~Roster();
    Roster& operator=(const Roster& r);
    void addStudent(const Student& student);
    void dropStudent(const std::string& studentId);
};

class Course{
    friend std::ostream& operator<<(std::ostream& print, const Course& course);
    private:
    std::string name;
    std::string code;
    Roster roster;
    public:
    Course();
    Course(const std::string& n, const std::string& c);
    std::string getCode() const;
    void addStudent(const Student& studentId);
    void dropStudent(const std::string& studentId);
};