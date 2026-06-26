#include "Team.h"

bool Team::operator()(const Person &manager, const Person &worker) {
    if (manager == worker) {
        return false;
    }

    if (!isInGroup(manager) || !isInGroup(worker)) {
        return false;
    }

    for (auto& r:relations) {
        if (r.workerEGN == worker.getEGN() && r.managerEGN != manager.getEGN()) {
            r.managerEGN = manager.getEGN();
            return true;
        }
    }
    relations.push_back({manager.getEGN(), worker.getEGN()});
    return true;
}

size_t Team::managerCount() const {
    std::vector<std::string> managers;

    for (const auto& r:relations) {
        bool found = false;
        for (const auto& m:managers) {
            if (m == r.managerEGN) {
                found = true;
                break;
            }
        }
        if (!found) {
            managers.push_back(r.managerEGN);
        }
    }
    return managers.size();
}

bool operator==(const Team& lhs, const Team& rhs) {
    return lhs.managerCount() == rhs.managerCount();
}

std::strong_ordering operator<=>(const Team& lhs, const Team& rhs) {
    return lhs.managerCount() <=> rhs.managerCount();
}
