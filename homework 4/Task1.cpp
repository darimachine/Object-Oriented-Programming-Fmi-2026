#include "Task1.hpp"


std::vector<std::shared_ptr<Discipline>> DisciplineCollection::disciplines;
std::vector<std::unique_ptr<Student>>    StudentSystem::students;
double Student::grade = 0;

const char* MyExceptions::what() const noexcept
{
    switch (error) {
        case FnDublicates:                  return "Faculty number already exists";
        case StudentNotFoundInAddOrRemove:  return "Cannot add/remove this student";
        case NotValidConfiguration:         return "Problem with construction";
        case StudentNotFoundForChecking:    return "The student isn't found for admission checking";
        default:                            return "Unknown error";
    }
}


Discipline::Discipline(std::string name, int credits, Category cat, Options op)
    : name(std::move(name)), credits(credits), cat(cat), op(op)
{
    for (const auto& d : DisciplineCollection::getAll()) {
        if (this->name == d->getName()) {
            throw MyExceptions(FnDublicates);
        }
    }
}


const std::vector<std::shared_ptr<Discipline>>& DisciplineCollection::getAll()
{
    return disciplines;
}

void DisciplineCollection::add(std::shared_ptr<Discipline> d)
{
    disciplines.push_back(std::move(d));
}


void DisciplineFactory::createDiscipline(const std::string& name, int credits,
                                          Category cat, Options op)
{
    auto d = std::make_shared<Discipline>(name, credits, cat, op);
    DisciplineCollection::add(d);
}


void Student::updateGrade(double _grade)
{
    grade += _grade;

}

void Student::add(std::shared_ptr<Discipline> d)
{
    credits += d->getCredits();
    courses.push_back(std::move(d));
    std::cout << "Input grade: ";
    double grade;
    std::cin >> grade;
    updateGrade(grade);
}


void PassCredits::checkValidity(Student* s)
{
    if (!s) throw MyExceptions(StudentNotFoundForChecking);
}

bool PassCredits::PassThisCriteria(Student* s, int minCredit)
{
    checkValidity(s);
    return s->getCredits() >= minCredit;
}

std::unique_ptr<IAdmission<int>> PassCredits::clone() const
{
    return std::make_unique<PassCredits>(*this);
}


void PassMinGrade::checkValidity(Student* s)
{
    if (!s) throw MyExceptions(StudentNotFoundForChecking);
}

bool PassMinGrade::PassThisCriteria(Student* s, double minGrade)
{
    checkValidity(s);
    if (s->getGrade()/s->getCourses().size() < minGrade) {
        throw std::runtime_error("You didn't pass the minimum grade");
    }
    return true;
}

std::unique_ptr<IAdmission<double>> PassMinGrade::clone() const
{
    return std::make_unique<PassMinGrade>(*this);
}


void PassCategory::checkValidity(Student* s)
{
    if (!s) throw MyExceptions(StudentNotFoundForChecking);
}

bool PassCategory::PassThisCriteria(Student* s, Category cat)
{
    checkValidity(s);

    int    count    = 0;
    double countAll = 0;

    for (const auto& i : s->getCourses()) {
        if (i->getCat() == cat) ++count;
    }
    for (const auto& i : DisciplineCollection::getAll()) {
        if (i->getCat() == cat) ++countAll;
    }

    if (countAll > 0 && (count / countAll) > 0.5) {
        return true;
    }
    throw std::runtime_error("You didn't pass the category requirement");
}

std::unique_ptr<IAdmission<Category>> PassCategory::clone() const
{
    return std::make_unique<PassCategory>(*this);
}


void PassClasses::checkValidity(Student* s)
{
    if (!s) throw MyExceptions(StudentNotFoundForChecking);
}

bool PassClasses::PassThisCriteria(Student* s, std::vector<std::string> required)
{
    checkValidity(s);
    int count = 0;
    for (const auto& course : s->getCourses()) {
        if (std::find(required.begin(), required.end(), course->getName()) != required.end()) {
            ++count;
        }
    }
    if (count == static_cast<int>(required.size())) return true;
    throw std::runtime_error("You didn't pass all required classes");
}

std::unique_ptr<IAdmission<std::vector<std::string>>> PassClasses::clone() const
{
    return std::make_unique<PassClasses>(*this);
}


void AllMandatoryClasses::checkValidity(Student* s)
{
    if (!s) throw MyExceptions(StudentNotFoundForChecking);
}

bool AllMandatoryClasses::PassThisCriteria(Student* s, std::vector<std::string> required)
{
    checkValidity(s);
    int count = 0;
    for (const auto& course : s->getCourses()) {
        if (std::find(required.begin(), required.end(), course->getName()) != required.end()) {
            ++count;
        }
    }
    if (count == static_cast<int>(required.size())) return true;
    throw std::runtime_error("You didn't pass all mandatory classes");
}

std::unique_ptr<IAdmission<std::vector<std::string>>> AllMandatoryClasses::clone() const
{
    return std::make_unique<AllMandatoryClasses>(*this);
}

void PassMinCreditsOptional::checkValidity(Student* s)
{
    if (!s) throw MyExceptions(StudentNotFoundForChecking);
}

bool PassMinCreditsOptional::PassThisCriteria(Student* s, int minCreditOptional)
{
    checkValidity(s);
    int count = 0;
    for (const auto& course : s->getCourses()) {
        if (course->getOp() == Options::Optional) {
            count += course->getCredits();
        }
    }
    if (count < minCreditOptional) {
        throw std::runtime_error("You didn't reach the minimum credits for optional courses");
    }
    return true;
}

std::unique_ptr<IAdmission<int>> PassMinCreditsOptional::clone() const
{
    return std::make_unique<PassMinCreditsOptional>(*this);
}


void PassMaxOptionals::checkValidity(Student* s)
{
    if (!s) throw MyExceptions(StudentNotFoundForChecking);
}

bool PassMaxOptionals::PassThisCriteria(Student* s, int maxOptionals)
{
    checkValidity(s);
    int count = 0;
    for (const auto& course : s->getCourses()) {
        if (course->getOp() == Options::Optional) {
            ++count;
        }
    }
    if (count > maxOptionals) {
        throw std::runtime_error("You exceeded the maximum number of optional courses");
    }
    return true;
}

std::unique_ptr<IAdmission<int>> PassMaxOptionals::clone() const
{
    return std::make_unique<PassMaxOptionals>(*this);
}


std::unique_ptr<PassCredits> RequirementFactory::createMinimumCredits(int credits)
{
    if (credits <= 0) throw MyExceptions(NotValidConfiguration);
    return std::make_unique<PassCredits>(credits);
}

std::unique_ptr<PassMinGrade> RequirementFactory::createMinimumAverageGrade(double grade)
{
    return std::make_unique<PassMinGrade>(grade);
}

std::unique_ptr<PassCategory> RequirementFactory::createMinimumCoursesFromCategory(
    Category category, int count)
{
    return std::make_unique<PassCategory>(category, count);
}

std::unique_ptr<PassClasses> RequirementFactory::createNoFailedMandatoryCourses(
    std::vector<std::string> mandatory)
{
    return std::make_unique<PassClasses>();
}

std::unique_ptr<PassMaxOptionals> RequirementFactory::createMaximumRemainingElectives(int maxCount)
{
    return std::make_unique<PassMaxOptionals>(maxCount);
}


void StudentSystem::add(std::unique_ptr<Student> s)
{
    for (const auto& existing : students) {
        if (existing->getFN() == s->getFN()) {
            throw MyExceptions(StudentNotFoundInAddOrRemove);
        }
    }
    students.push_back(std::move(s));
}

void StudentSystem::remove(const std::string& fn)
{
    auto before = students.size();
    std::erase_if(students, [&fn](const std::unique_ptr<Student>& st) {
        return st->getFN() == fn;
    });
    if (students.size() == before) {
        throw MyExceptions(StudentNotFoundInAddOrRemove);
    }
}

std::unique_ptr<Student>& StudentSystem::operator[](const std::string& fn)
{
    for (auto& s : students) {
        if (s->getFN() == fn) return s;
    }
    throw MyExceptions(StudentNotFoundForChecking);
}

const std::vector<std::unique_ptr<Student>>& StudentSystem::getAll()
{
    return students;
}

bool StudentSystem::finalExam(const RequirementFactory& f)
{
    auto creditCheck = RequirementFactory::createMinimumCredits(180);
    auto gradeCheck  = RequirementFactory::createMinimumAverageGrade(4.00);

    std::vector<std::string> mandatoryList = { "UP", "OOP" };
    auto classCheck = RequirementFactory::createNoFailedMandatoryCourses(mandatoryList);

    bool overallSuccess = true;

    for (const auto& studentPtr : students) {
        std::vector<std::string> studentErrors;
        Student* s = studentPtr.get();

        try {
            if (!creditCheck->PassThisCriteria(s, 180))
                studentErrors.emplace_back("Недостатъчен брой кредити.");
        }
        catch (const std::runtime_error& e) { studentErrors.emplace_back(e.what()); }

        try {
            if (!gradeCheck->PassThisCriteria(s, 4.00))
                studentErrors.emplace_back("Нисък среден успех.");
        }
        catch (const std::runtime_error& e) { studentErrors.emplace_back(e.what()); }

        try {
            if (!classCheck->PassThisCriteria(s, mandatoryList))
                studentErrors.emplace_back("Липсват задължителни предмети.");
        }
        catch (const std::runtime_error& e) { studentErrors.emplace_back(e.what()); }

        if (!studentErrors.empty()) {
            overallSuccess = false;
            std::cout << "Студент с ФН: " << s->getFN()
                      << " НЕ Е допуснат поради следните причини:\n";
            for (const auto& err : studentErrors)
                std::cout << "  - " << err << "\n";
        }
        else {
            std::cout << "Студент с ФН: " << s->getFN() << " е ДОПУСНАТ до изпит.\n";
        }
    }

    return overallSuccess;
}
