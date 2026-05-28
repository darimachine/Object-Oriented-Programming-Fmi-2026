#pragma once
#include <vector>
#include <string>
#include <iostream>

class RequirementCheckResult {
private:
    bool admitted;
    std::vector<std::string> reasons;

    public:
        RequirementCheckResult(bool success = true);

        void addReason(const std::string& reason);
        void merge(const RequirementCheckResult& other);

        bool isAdmitted() const;
        const std::vector<std::string>& getReasons() const;
        void printReport() const;
};
