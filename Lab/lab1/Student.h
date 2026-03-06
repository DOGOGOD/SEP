#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <vector>

class Class;

enum Degree {
    undergraduate,
    graduate
};

class Student {
    // TODO: implement class Student.
private:
    const std::string name;
    const std::string year;
    Degree degree;
protected:
    std::vector<Class *> classes;
public:
    const std::string id;
    std::string toString() const;
    virtual double getGpa() const = 0;
    double getAvgScore() const;
    Student(const std::string &id, const std::string &name, const std::string &year, Degree degree)
        : name(name), year(year), degree(degree), id(id)
    {};
    void addClass(Class *cl);
    virtual ~Student(){};
};

// TODO: implement class Graduate.
class Graduate : public Student {
public:
    Graduate(const std::string &id, const std::string &name, const std::string &year)
        : Student(id, name, year, Degree::graduate)
    {};
    ~Graduate() override {};
    double getGpa() const override;
};

// TODO: implement class Undergraduate.
class Undergraduate : public Student {
public:
    Undergraduate(const std::string &id, const std::string &name, const std::string &year)
        : Student(id, name, year, Degree::undergraduate)
    {};
    ~Undergraduate() override {};
    double getGpa() const override;
};

class StudentWrapper {
private:
    const Student &student;
    double score = -1.0; // Invalid Score
public:
    const std::string id;
    // TODO: fix error
    StudentWrapper(const std::string &id, const Student &student)
        : student(student), id(id)
    {}

    void setScore(double score)
    {
        if (score < 0 || score > 100)
            throw "Wrong Score!";
        this->score = score;
    }

    double getScore() const
    {
        return this->score;
    }

    std::string toString() const
    {
        return student.toString();
    }
};

#endif // STUDENT_H_
