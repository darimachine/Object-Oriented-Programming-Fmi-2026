
#include <iostream>
#include "Hospital.h"

Hospital& Hospital::getInstance()
{
    static Hospital instance;
    return instance;
}
void Hospital::addWard(const string& name)
{
    wards.emplace_back(name);
}
void Hospital::removeWard(const string& name)
{
    erase_if(wards, [&name](const Ward& w) {return w.getName() == name; });
}
Ward& Hospital::operator[](const string& name)
{
    for (auto& el : wards) {
        if (el.getName() == name) {
            return el;
        }
    }
}
vector<Ward> Hospital::findPatientInWards(const string& egn) const
{
    vector<Ward> result;
    for (const auto& w : wards) {
        Patient * p = w.findPatient(egn);
        if (p != nullptr) {
            result.push_back(w);
        }
    }
    return result;
}
size_t Hospital::countPatientWards(const string& egn) const {
    size_t count = 0;
    for (const auto& ward : wards) {
        if (ward.findPatient(egn) != nullptr) {
            count++;
        }
    }
    return count;
}
Hospital::operator bool() const {
    if (wards.empty()) return false;
    size_t total = 0;
    for (const auto& ward : wards) {
        total += ward.patientCount();
    }
    return (total / wards.size()) > 20;
}

ostream& operator<<(ostream& os, const Hospital& h)
{
    os << h.name;
    for (const auto& el : h.wards) {
        os << el;
    }
    return os;
    // TODO: insert return statement here
}
