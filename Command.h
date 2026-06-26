#pragma once
#include <iostream>
#include <memory>
#include "Territory.h"

class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual std::string description() const = 0;
    virtual ~Command() = default;
};

class AddLandmarkCommand : public Command {
    Territory& territory;
    std::unique_ptr<Landmark> landmark;
    std::string landmarkName;

public:
    AddLandmarkCommand(Territory& t, std::unique_ptr<Landmark> l);
    void execute() override;
    void undo() override;
    std::string description() const override;
};

class RemoveLandmarkCommand : public Command {
    Territory& territory;
    std::string landmarkName;
    std::unique_ptr<Landmark> removedLandmark;

public:
    RemoveLandmarkCommand(Territory& t, const std::string& name);
    void execute() override;
    void undo() override;
    std::string description() const override;
};

class SetDangerLevelCommand : public Command {
    Territory& territory;
    int oldLevel;
    int newLevel;

public:
    SetDangerLevelCommand(Territory& t, int level);
    void execute() override;
    void undo() override;
    std::string description() const override;
};