#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <stdexcept>
#include <iostream>

enum Category {
    IT,
    Math,
    AppMathematics,
    Other
};

enum Options {
    Mandatory,
    Optional
};

enum errorCodes {
    FnDublicates,
    StudentNotFoundInAddOrRemove,
    StudentNotFoundForChecking,
    NotValidConfiguration
};


class MyExceptions : public std::exception {
    errorCodes error;
public:
    MyExceptions(errorCodes er) : error(er) {}
    const char* what() const noexcept override;
};


class Discipline;
class DisciplineCollection;
class Student;


class Discipline {
    std::string name;
    int credits;
    Category cat;
    Options op;
public:
    Discipline(std::string name, int credits, Category cat, Options op = Mandatory);

    const std::string& getName()    const { return name; }
    Category           getCat()     const { return cat; }
    int                getCredits() const { return credits; }
    Options            getOp()      const { return op; }
};


class DisciplineCollection {
    static std::vector<std::shared_ptr<Discipline>> disciplines;
public:
    static const std::vector<std::shared_ptr<Discipline>>& getAll();
    static void add(std::shared_ptr<Discipline> d);
};


class DisciplineFactory {
public:
    static void createDiscipline(const std::string& name, int credits,
                                 Category cat, Options op = Mandatory);
};

class Student {
    std::string fn;
    std::string name;
    std::vector<std::shared_ptr<Discipline>> courses;
    static double grade;  
    int    credits = 0;

public:
    Student(const std::string& fn, const std::string& name)
        : fn(fn), name(name) {}
    static void updateGrade(double _grade);
    void add(std::shared_ptr<Discipline> d);

    const std::string& getFN()      const { return fn; }
    const std::string& getName()    const { return name; }
    int                getCredits() const { return credits; }
    double             getGrade()   const { return grade; }
    const std::vector<std::shared_ptr<Discipline>>& getCourses() const { return courses; }
};


template <typename T>
class IAdmission {
public:
    IAdmission()          = default;
    virtual ~IAdmission() = default;

    virtual std::unique_ptr<IAdmission<T>> clone()                    const = 0;
    virtual bool PassThisCriteria(Student* s, T criterion)                  = 0;
    virtual void checkValidity(Student* s)                                  = 0;
};


class PassCredits : public IAdmission<int> {
    int minCr;
public:
    explicit PassCredits(int minCr) : minCr(minCr) {}

    bool PassThisCriteria(Student* s, int minCredit) override;
    std::unique_ptr<IAdmission<int>> clone() const override;
    void checkValidity(Student* s) override;
};

class PassMinGrade : public IAdmission<double> {
    double minGr;
public:
    explicit PassMinGrade(double minGr) : minGr(minGr) {}

    bool PassThisCriteria(Student* s, double minGrade) override;
    std::unique_ptr<IAdmission<double>> clone() const override;
    void checkValidity(Student* s) override;
};

class PassCategory : public IAdmission<Category> {
    Category c;
    int      minCount;
public:
    PassCategory(Category c, int minCount = 1) : c(c), minCount(minCount) {}

    bool PassThisCriteria(Student* s, Category cat) override;
    std::unique_ptr<IAdmission<Category>> clone() const override;
    void checkValidity(Student* s) override;
};

class PassClasses : public IAdmission<std::vector<std::string>> {
public:
    bool PassThisCriteria(Student* s, std::vector<std::string> required) override;
    std::unique_ptr<IAdmission<std::vector<std::string>>> clone() const override;
    void checkValidity(Student* s) override;
};

class AllMandatoryClasses : public IAdmission<std::vector<std::string>> {
public:
    bool PassThisCriteria(Student* s, std::vector<std::string> required) override;
    std::unique_ptr<IAdmission<std::vector<std::string>>> clone() const override;
    void checkValidity(Student* s) override;
};

class PassMinCreditsOptional : public IAdmission<int> {
    int minCrOp;
public:
    explicit PassMinCreditsOptional(int min) : minCrOp(min) {}

    bool PassThisCriteria(Student* s, int minCreditOptional) override;
    std::unique_ptr<IAdmission<int>> clone() const override;
    void checkValidity(Student* s) override;
};

class PassMaxOptionals : public IAdmission<int> {
    int maxCount;
public:
    explicit PassMaxOptionals(int maxCount) : maxCount(maxCount) {}

    bool PassThisCriteria(Student* s, int maxOptionals) override;
    std::unique_ptr<IAdmission<int>> clone() const override;
    void checkValidity(Student* s) override;
};


template <typename StudentType>
class AdmissionService {
    std::vector<std::unique_ptr<IAdmission<StudentType>>> requirements;
public:
    void addRequirement(std::unique_ptr<IAdmission<StudentType>> req) {
        requirements.push_back(std::move(req));
    }

    std::vector<std::string> checkAdmission(StudentType* s) const {
        std::vector<std::string> errors;
        for (const auto& req : requirements) {
            try {
                if (!req->PassThisCriteria(s)) {
                    errors.push_back("Requirement not met.");
                }
            }
            catch (const std::runtime_error& e) {
                errors.push_back(e.what());
            }
        }
        return errors;
    }
};


class RequirementFactory {
public:
    static std::unique_ptr<PassCredits>      createMinimumCredits(int credits);
    static std::unique_ptr<PassMinGrade>     createMinimumAverageGrade(double grade);
    static std::unique_ptr<PassCategory>     createMinimumCoursesFromCategory(Category category, int count);
    static std::unique_ptr<PassClasses>      createNoFailedMandatoryCourses(std::vector<std::string> mandatory);
    static std::unique_ptr<PassMaxOptionals> createMaximumRemainingElectives(int maxCount);
};


class StudentSystem {
    static std::vector<std::unique_ptr<Student>> students;
public:
    static void add(std::unique_ptr<Student> s);
    static void remove(const std::string& fn);

    static std::unique_ptr<Student>& operator[](const std::string& fn);
    static const std::vector<std::unique_ptr<Student>>& getAll();
    static bool finalExam(const RequirementFactory& f);
};
