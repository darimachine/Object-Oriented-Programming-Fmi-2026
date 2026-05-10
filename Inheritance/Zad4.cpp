#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>

class Animal {
    std::string name;
    std::string species;
    int age;

public:
    Animal(const std::string& name, const std::string& species, int age) : name(name), species(species), age(age) {
        if (age < 0) {
            throw std::invalid_argument("Animal age cannot be negative.");
        }
    }

    const std::string& getName() const {
        return name;
    }
    const std::string& getSpecies() const {
        return species;
    }
    int getAge() const {
        return age;
    }

    void print() const {
        std::cout << "Animal: " << name << "\nSpecies: " << species << "\nAge: " << age << "\n";
    }
};

class Exhibit {
    std::string location;
    std::string species;
    int capacity{};
    std::vector<Animal> animals; // Композиция защото съдържа животни

public:
    Exhibit(const std::string& location, const std::string& species, int capacity) : location(location), species(species), capacity(capacity) {
        if (capacity <= 0) {
            throw std::invalid_argument("Exhibit capacity must be positive.");
        }
    }

    bool isFull() const {
        return animals.size() >= capacity;
    }

    void addAnimal(Animal a) {
        if (isFull()) {
            throw std::runtime_error("Exhibit is full.");
        }
        if (a.getSpecies() != species) {
            throw std::invalid_argument("Species of animal doesn't match the exhibit");
        }
        animals.push_back(std::move(a));
    }

    const Animal* findByName(const std::string& name) const {
        for (const auto& a : animals) {
            if (a.getName() == name) {
                return &a;
            }
        }
        return nullptr;
    }

    void print() const {
        std::cout << "Exhibit: " << location << " - " << species << " - " << animals.size() << "/" << capacity << "\n";
        for (const auto& a : animals) {
            a.print();
        }
    }

};

class ZooKeeper {
    std::string name;
    unsigned employeeID{};
    int experience{};

public:
    ZooKeeper(const std::string& name, unsigned employeeID, int experience) : name(name), employeeID(employeeID), experience(experience) {
        if (experience < 0) {
            throw std::invalid_argument("Years of experience must be positive.");
        }
    }

    const std::string& getName() const {
        return name;
    }

    unsigned getID() const {
        return employeeID;
    }

    int getExperience() const {
        return experience;
    }

};

class Section {
protected:
    std::string name;
    int minExperience{};
    std::vector<Exhibit> exhibits;
    std::weak_ptr<ZooKeeper> guard; // Не притежава пазача

public:
    Section(const std::string& name, int minExperience) : name(name), minExperience(minExperience) {
    }

    const std::string& getName() const {
        return name;
    }

    int getMinExperience() const {
        return minExperience;
    }

    void addExhibit(Exhibit ex) {
        exhibits.push_back(std::move(ex));
    }

    void assignGuard(std::shared_ptr<ZooKeeper> keeper) {
        if (!keeper) {
            throw std::invalid_argument("Keeper can't be null");
        }
        if (keeper->getExperience() < minExperience) {
            throw std::runtime_error("Keeper doesn't have enough experience.");
        }
        guard = keeper;
    }

    bool hasActiveGuard() const {
        return !guard.expired();
    }

    void clearGuard() {
        guard.reset();
    }

    const Animal* searchAnimal(const std::string& name) const {
        for (const auto& ex : exhibits) {
            if (auto* a = ex.findByName(name)) {
                return a;
            }
        }
        return nullptr;
    }

    const std::vector<Exhibit>& getExhibits() const { return exhibits; }

    void print() const {
        std::cout << "Section: " << name << "\nMinimum Experience: " << minExperience;
        if (hasActiveGuard()) {
            std::cout << "\nGuard: " << guard.lock()->getName();
        }
        else {
            std::cout << "\nGuard: None\n";
        }
        for (const auto& ex : exhibits) {
            ex.print();
        }
    }

};

// Наследяване защото са различни видове секции

class BirdSection : public Section {
public:
    explicit BirdSection(const std::string& name) : Section(name, 0) {
    }
};

class MammalSection : public Section {
public:
    explicit MammalSection(const std::string& name) : Section(name, 3) {
    }
};

class ReptileSection : public Section {
public:
    explicit ReptileSection(const std::string& name) : Section(name, 5) {
    }
};

class Zoo {
private:
    std::vector<BirdSection> birds;
    std::vector<MammalSection> mammals;
    std::vector<ReptileSection> reptiles;
    std::vector<std::shared_ptr<ZooKeeper>> keepers;
    // Притежава всичките затова композиция

public:
    void addBirdSection(BirdSection bs) {
        birds.push_back(std::move(bs));
    }

    void addMammalSection(MammalSection ms) {
        mammals.push_back(std::move(ms));
    }

    void addReptileSection(ReptileSection rs) {
        reptiles.push_back(std::move(rs));
    }

    std::vector<BirdSection>& getBirdSections() {
        return birds;
    }

    std::vector<MammalSection>& getMammalSections() {
        return mammals;
    }

    std::vector<ReptileSection>& getReptileSections() {
        return reptiles;
    }

    std::shared_ptr<ZooKeeper> addKeeper(const std::string& name, int id, int experience) {
        auto kp = std::make_shared<ZooKeeper>(name, id, experience);
        keepers.push_back(kp);
        return kp;
    }

    void removeKeeper(int employeeID) {
        auto it = std::find_if(keepers.begin(), keepers.end(),
            [employeeID](const std::shared_ptr<ZooKeeper>& k) {
                return k->getID() == employeeID;
            });
        if (it == keepers.end()) {
            throw std::runtime_error("No keeper found.");
        }
        keepers.erase(it);
    }

    void printAll() const {
        for (const auto& b : birds) {
            b.print();
        }
        for (const auto& m : mammals) {
            m.print();
        }
        for (const auto& r : reptiles) {
            r.print();
        }
    }

    const Animal* search(const std::string& name) const {
        for (const auto& b : birds)
            if (auto* a = b.searchAnimal(name)) {
                return a;
            }
        for (const auto& m : mammals)
            if (auto* a = m.searchAnimal(name)) {
                return a;
            }
        for (const auto& r : reptiles)
            if (auto* a = r.searchAnimal(name)) {
                return a;
            }
        return nullptr;
    }

};

int main() {
    Zoo zoo;

    zoo.addBirdSection(BirdSection("Aviary"));
    zoo.addMammalSection(MammalSection("Savannah"));
    zoo.addReptileSection(ReptileSection("Reptile House"));

    Exhibit eagles("East Wing", "Eagle", 3);
    eagles.addAnimal(Animal("Eddie", "Eagle", 4));
    zoo.getBirdSections()[0].addExhibit(std::move(eagles));

    Exhibit lions("North Plain", "Lion", 2);
    lions.addAnimal(Animal("Leo", "Lion", 7));
    zoo.getMammalSections()[0].addExhibit(std::move(lions));

    Exhibit snakes("West Cave", "Python", 4);
    snakes.addAnimal(Animal("Sss", "Python", 3));
    zoo.getReptileSections()[0].addExhibit(std::move(snakes));

    auto rookie = zoo.addKeeper( "Ivan", 1, 2);
    auto senior = zoo.addKeeper("Maria", 2, 6);

    try {
        zoo.getReptileSections()[0].assignGuard(rookie);
    } catch (const std::runtime_error& e) {
        std::cout << "Rejected: " << e.what() << "\n";
    }

    zoo.getReptileSections()[0].assignGuard(senior);
    std::cout << "Active guard: " << std::boolalpha
              << zoo.getReptileSections()[0].hasActiveGuard() << "\n";

    zoo.removeKeeper(2);
    senior.reset();
    std::cout << "Active guard after removeKeeper: "
              << zoo.getReptileSections()[0].hasActiveGuard() << "\n";

    zoo.printAll();

    if (const Animal* a = zoo.search("Leo")) {
        std::cout << "Found: "; a->print();
    }
    if (!zoo.search("Ghost")) {
        std::cout << "\nGhost not found.\n";
    }

    return 0;
}