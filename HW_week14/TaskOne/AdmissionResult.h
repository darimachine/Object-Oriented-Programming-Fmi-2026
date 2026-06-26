#pragma once
#include <vector>
#include <string>

class AdmissionResult
{
private:
    bool admitted;
    std::vector<std::string> reasons;
public:
    explicit AdmissionResult(bool admitted);
    void addReason(const std::string& reason);
    bool isAdmitted() const;
    const std::vector<std::string>& getReasons() const;
    void print() const;
};

