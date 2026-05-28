#pragma once
#include "Territory.h"

class Command {
protected:
    Territory& context;
public:
    Command(Territory& target) : context(target) {}
    virtual ~Command() = default;

    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual std::string description() const = 0;
};

// 1. AddLandmarkCommand
class AddLandmarkCommand : public Command {
private:
    std::unique_ptr<Landmark> landmark;
    std::string landmarkName;
public:
    AddLandmarkCommand(Territory& target, std::unique_ptr<Landmark> l, const std::string& name)
        : Command(target), landmark(std::move(l)), landmarkName(name) {
    }

    void execute() override {
        context.addLandmark(std::move(landmark));
    }
    void undo() override {
        landmark = context.removeLandmark(landmarkName);
    }
    std::string description() const override {
        return "Added landmark: " + landmarkName;
    }
};

// 2. RemoveLandmarkCommand
class RemoveLandmarkCommand : public Command {
private:
    std::string landmarkName;
    std::unique_ptr<Landmark> savedLandmark;
public:
    RemoveLandmarkCommand(Territory& target, const std::string& name)
        : Command(target), landmarkName(name) {
    }

    void execute() override {
        savedLandmark = context.removeLandmark(landmarkName);
    }
    void undo() override {
        context.addLandmark(std::move(savedLandmark));
    }
    std::string description() const override {
        return "Removed landmark: " + landmarkName;
    }
};

// 3. SetDangerLevelCommand
class SetDangerLevelCommand : public Command {
private:
    int newLevel;
    int oldLevel;
public:
    SetDangerLevelCommand(Territory& target, int level)
        : Command(target), newLevel(level), oldLevel(1) {
    }

    void execute() override {
        oldLevel = context.getDangerLevel();
        context.setDangerLevel(newLevel);
    }
    void undo() override {
        context.setDangerLevel(oldLevel);
    }
    std::string description() const override {
        return "Changed danger level to " + std::to_string(newLevel);
    }
};
