#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>

using namespace std;

class Department
{
private:
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & id;
        ar & name;
    }

public:
    int id;
    string name;

    Department() {}
    Department(int i, const string &n) : id(i), name(n) {}
};

class Student
{
private:
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & id;
        ar & name;
        ar & gpa;
        ar & department;
    }

public:
    int id;
    string name;
    double gpa;
    Department *department;

    Student() {}
    Student(int i, const string &n, double g, Department *d)
        : id(i), name(n), gpa(g), department(d) {}
};

int main()
{
    Department *cs = new Department(1, "Computer Science");
    Department *se = new Department(2, "Software Engineering");

    vector<Student> students =
        {
            {1001, "Alice", 3.92, cs},
            {1002, "Bob", 3.75, cs},
            {1003, "Cindy", 3.88, cs},
            {1004, "David", 3.67, cs},
            {2001, "Emma", 3.95, se},
            {2002, "Frank", 3.73, se},
            {2003, "Grace", 3.84, se},
            {2004, "Henry", 3.58, se}};

    cout << "===== Original Data =====" << endl;
    for (const auto &s : students)
    {
        cout
            << s.id << "\t"
            << s.name << "\t"
            << s.department->name << "\t"
            << s.department
            << endl;
    }

    // Serialize
    ofstream ofs("students.dat", ios::binary);
    boost::archive::binary_oarchive oa(ofs);
    oa << cs << se << students;
    ofs.close();

    // Deserialize
    vector<Student> restored;
    ifstream ifs("students.dat");
    boost::archive::binary_iarchive ia(ifs);
    Department *cs2 = nullptr;
    Department *se2 = nullptr;
    ia >> cs2 >> se2 >> restored;

    cout << "===== Desrialized Data =====" << endl;
    for (const auto &s : restored)
    {
        cout
            << s.id << "\t"
            << s.name << "\t"
            << s.department->name << "\t"
            << s.department
            << endl;
    }
}
