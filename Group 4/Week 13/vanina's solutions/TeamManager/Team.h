#ifndef TEAMMANAGER_TEAM_H
#define TEAMMANAGER_TEAM_H

#include "Group.h"

#include<string>

struct Relation {
    std::string managerEGN;
    std::string workerEGN;
};

class Team : public Group {
    std::vector<Relation> relations;

public:

    bool operator()(const Person& manager, const Person& worker);
    size_t managerCount() const;

};

bool operator==(const Team& lhs, const Team& rhs);
std::strong_ordering operator<=>(const Team& lhs, const Team& rhs);


#endif //TEAMMANAGER_TEAM_H