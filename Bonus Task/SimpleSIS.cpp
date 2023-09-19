#include <bits/stdc++.h>

using namespace std;

class Course
{
    string cname;
    string ccode;
    double cgrade;
    int chours;
    bool registered;

public:
    Course() {}
    Course(string code, string name, int hours)
    {
        ccode = code;
        cname = name;
        chours = hours;
        cgrade = 0;
        registered = false;
    }
    bool is_registered()
    {
        return registered;
    }
    bool is_passed()
    {
        if (cgrade > 2)
            return true;
        else
            return false;
    }
    string get_name()
    {
        return cname;
    }
    string get_code()
    {
        return ccode;
    }
    double get_grade()
    {
        return cgrade;
    }
    int get_hours()
    {
        return chours;
    }
    void set_registered(bool reg)
    {
        registered = reg;
    }
    void set_grade(float grade)
    {
        cgrade = grade;
    }
};
class Student
{
    string scode;
    string sname;
    double gpa;
    Course courses[5];

public:
    Student(string code, string name)
    {
        scode = code;
        sname = name;
        gpa = 0;
        Course comp("CS101", "Introduction to Computer Science", 3);
        Course math("MATH201", "Calculus I", 4);
        Course physics("PHYS101", "Introduction to Physics", 4);
        Course chemistry("CHEM101", "Introduction to Chemistry", 3);
        Course english("ENGL101", "English Composition I", 3);
        courses[0] = comp;
        courses[1] = math;
        courses[2] = physics;
        courses[3] = chemistry;
        courses[4] = english;
    };
    void register_course(string ccode, float cgrade)
    {
        for (int i = 0; i < 5; i++)
        {
            if (ccode == courses[i].get_code())
            {
                courses[i].set_grade(cgrade);
            }
        }
    }
    float calc_gpa()
    {
        double numerator = 0;
        double total_hrs = 0;
        for (int i = 0; i < 5; i++)
        {
            total_hrs += courses[i].get_hours();
            numerator += (courses[i].get_grade() * courses[i].get_hours());
        }
        gpa = numerator / total_hrs;
        return gpa;
    }
    string get_name()
    {
        return sname;
    }
};

vector<Student> sort_by_GPA(vector<Student> vect);

int main()
{
    int n;
    vector<Student> studs;

    string code;
    string name;
    double grade;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> code >> name;
        Student s(code, name);
        string code;
        double grade;

        for (int j = 0; j < 5; j++)
        {
            cin >> code >> grade;
            s.register_course(code, grade);
        }
        studs.push_back(s);
    }
    
        studs = sort_by_GPA(studs);
    for (int i = 0; i < n; i++)
    {
        cout << studs[i].get_name() << " " << studs[i].calc_gpa() << endl;
        cout << endl;
    }
}

vector<Student> sort_by_GPA(vector<Student> vect)
{
    bool flag;
    do
    {
        flag = false;
        for (int i = 0; i < vect.size() - 1; i++)
            if (vect[i].calc_gpa() < vect[i + 1].calc_gpa())
            {
                flag = true;
                Student aux = vect[i];
                vect[i] = vect[i + 1];
                vect[i + 1] = aux;
            }
    } while (flag);
    return vect;
}