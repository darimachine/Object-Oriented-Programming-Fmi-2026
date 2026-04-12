#pragma warning (disable: 4996)
#include <iostream>

namespace Constants {
    const int MAX_TEXT_LENGTH = 50;
    const int MAX_ANSWERS_AMOUNT = 4;
    const int MAX_QUESTIONS_AMOUNT = 5;
}

enum class AnswerOption {
    A, B, C, D, Undefined
};

using namespace Constants;

struct Answer {
    char text[MAX_TEXT_LENGTH] = "";
};

struct Question {
    char text[MAX_TEXT_LENGTH] = "";
    Answer answers[MAX_ANSWERS_AMOUNT];
    AnswerOption correctAnswer = AnswerOption::Undefined;
    unsigned points = 0;
};

struct Test {
    unsigned questionsAmount = 0;
    Question questions[MAX_QUESTIONS_AMOUNT];
};

void printQuestion(const Question& question) {
    std::cout << question.text << std::endl;
    for (unsigned i = 0; i < MAX_ANSWERS_AMOUNT; i++) {
        std::cout << (char)('A' + i) << ") " << question.answers[i].text << std::endl;
    }
}

Answer initAnswer(const char* text) {
    Answer result;
    strcpy(result.text, text);
    return result;
}

Question initQuestion(const char* question, Answer answers[MAX_ANSWERS_AMOUNT], AnswerOption correct, unsigned points) {
    Question result;
    strcpy(result.text, question);
    result.correctAnswer = correct;
    result.points = points;
    for (unsigned i = 0; i < MAX_ANSWERS_AMOUNT; i++) {
        strcpy(result.answers[i].text, answers[i].text);
    }

    return result;
}

AnswerOption readUserAnswer() {
    char answer;
    std::cin >> answer;

    switch (answer) {
        case 'A': return AnswerOption::A;
        case 'B': return AnswerOption::B;
        case 'C': return AnswerOption::C;
        case 'D': return AnswerOption::D;
        default: return AnswerOption::Undefined;
    }
}

void doTest(const Test& test) {
    unsigned accumulatedPoints = 0, maxPointsPossible = 0;
    for (unsigned i = 0; i < MAX_QUESTIONS_AMOUNT; i++) {
        printQuestion(test.questions[i]);

        maxPointsPossible += test.questions[i].points;
        if (test.questions[i].correctAnswer == readUserAnswer()) {
            accumulatedPoints += test.questions[i].points;
        }
    }

    std::cout << "You got " << accumulatedPoints << " / " << maxPointsPossible << " points!";
}

int main() {
    Answer firstQuestionAnswers[MAX_ANSWERS_AMOUNT] = {
        initAnswer("correct"), initAnswer("wrong"), initAnswer("very wrong"), initAnswer("incorrect")
    };
    Answer secondQuestionAnswers[MAX_ANSWERS_AMOUNT] = {
        initAnswer("wrong"), initAnswer("correct"), initAnswer("very wrong"), initAnswer("incorrect")
    };
    Answer thirdQuestionAnswers[MAX_ANSWERS_AMOUNT] = {
        initAnswer("very wrong"), initAnswer("wrong"), initAnswer("correct"), initAnswer("incorrect")
    };
    Answer fourthQuestionAnswers[MAX_ANSWERS_AMOUNT] = {
        initAnswer("incorrect"), initAnswer("wrong"), initAnswer("very wrong"), initAnswer("correct")
    };
    Answer fifthQuestionAnswers[MAX_ANSWERS_AMOUNT] = {
        initAnswer("incorrect"), initAnswer("correct"), initAnswer("very wrong"), initAnswer("wrong")
    };

    Test test{
        5,
        {
            initQuestion("question1?", firstQuestionAnswers, AnswerOption::A, 3),
            initQuestion("question2?", secondQuestionAnswers, AnswerOption::B, 3),
            initQuestion("question3?", thirdQuestionAnswers, AnswerOption::C, 3),
            initQuestion("question4?", fourthQuestionAnswers, AnswerOption::D, 3),
            initQuestion("question5?", fifthQuestionAnswers, AnswerOption::B, 3)
        } 
    };

    doTest(test);
}
