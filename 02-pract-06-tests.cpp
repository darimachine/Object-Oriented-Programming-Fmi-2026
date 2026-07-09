#include <iostream>
#include <cstring>
#include <print>

#pragma warning (disable:4996)

namespace Constants {
	constexpr int MaxTextLength = 100;
	constexpr int QuestionsCount = 10;
}

enum class CorrectAnswer {
	A = 1,
	B,
	C,
	D
};

CorrectAnswer CharToCorrectAnswer(char answer) {
	switch (answer) {
		case 'A': return CorrectAnswer::A;
		case 'B': return CorrectAnswer::B;
		case 'C': return CorrectAnswer::C;
		case 'D': return CorrectAnswer::D;
	}
}

struct Question {
private:
    char text[Constants::MaxTextLength];
	char A[Constants::MaxTextLength];
	char B[Constants::MaxTextLength];
	char C[Constants::MaxTextLength];
	char D[Constants::MaxTextLength];
	CorrectAnswer correctAnswer;
	int points;

public:
	const char* getText() const {
		return text;
	}

	void setText(const char* text) {
		if (!text) return;
		strcpy(this->text, text);
	}

	const char* getOptionA() const {
		return A;
	}

	void setOptionA(const char* optionA) {
		if (!optionA) return;
		strcpy(this->A, optionA);
	}

	const char* getOptionB() const {
		return B;
	}

	void setOptionB(const char* optionB) {
		if (!optionB) return;
		strcpy(this->B, optionB);
	}

	const char* getOptionC() const {
		return C;
	}

	void setOptionC(const char* optionC) {
		if (!optionC) return;
		strcpy(this->C, optionC);
	}

	const char* getOptionD() const {
		return D;
	}

	void setOptionD(const char* optionD) {
		if (!optionD) return;
		strcpy(this->D, optionD);
	}

	CorrectAnswer getCorrectAnswer() const {
		return correctAnswer;
	}

	void setCorrectAnswer(CorrectAnswer correctAnswer) {
		this->correctAnswer = correctAnswer;
	}

	int getPoints() const {
		return points;
	}

	void setPoints(int points) {
		if (points < 0) return;
		this->points = points;
	}

	void setAll(const char* text, const char* optionA, const char* optionB, const char* optionC, const char* optionD, CorrectAnswer correctAnswer, int points) {
		setText(text);
		setOptionA(optionA);
		setOptionB(optionB);
		setOptionC(optionC);
		setOptionD(optionD);
		setCorrectAnswer(correctAnswer);
		setPoints(points);
	}
};

struct Quiz {
private:
	char title[Constants::MaxTextLength];
	Question questions[Constants::QuestionsCount];
	int questionsCount = 0;

public:
	const char* getTitle() const {
		return title;
	}

	void setTitle(const char* title) {
		if (!title) return;
		strcpy(this->title, title);
	}

	int getQuestionsCount() const {
		return questionsCount;
	}

	void addQuestion(const Question& question) {
		if (questionsCount >= Constants::QuestionsCount) {
			std::println("Cannot add more questions. Maximum capacity reached.");
			return;
		}
		questions[questionsCount++] = question;
	}

	void start() const {
		std::println("Starting quiz: {}", title);
		int totalPoints = 0;

		for (int i = 0; i < questionsCount; i++) {
			const Question& question = questions[i];
			std::println("Question {}: {}", i + 1, question.getText());
			std::println("A) {}", question.getOptionA());
			std::println("B) {}", question.getOptionB());
			std::println("C) {}", question.getOptionC());
			std::println("D) {}", question.getOptionD());
			std::print("Correct Answer: ");
			char answer;
			std::cin >> answer;

			if(CharToCorrectAnswer(answer) == question.getCorrectAnswer()) {
				std::println("Correct! You earned {} points.", question.getPoints());
				totalPoints += question.getPoints();
			} else {
				std::println("Wrong answer!");
			}
			std::println();
		}

		std::println();
		std::println("Total points: {}", totalPoints);
	}
};

int main()
{
	Question question1;
	question1.setAll("What is the capital of France?", "Berlin", "Madrid", "Paris", "Rome", CorrectAnswer::C, 10);
	Question question2;
	question2.setAll("What is the largest planet in our solar system?", "Earth", "Jupiter", "Mars", "Saturn", CorrectAnswer::B, 10);
	Question question3;
	question3.setAll("What is the chemical symbol for water?", "H2O", "CO2", "O2", "NaCl", CorrectAnswer::A, 10);
	Question question4;
	question4.setAll("Who wrote 'To Kill a Mockingbird'?", "Harper Lee", "Mark Twain", "J.K. Rowling", "Ernest Hemingway", CorrectAnswer::A, 10);
	Question question5;
	question5.setAll("What is the smallest prime number?", "0", "1", "2", "3", CorrectAnswer::C, 10);
	Question question6;
	question6.setAll("What is the speed of light?", "299,792 km/s", "150,000 km/s", "1,080,000 km/s", "300,000 km/s", CorrectAnswer::A, 10);
	Question question7;
	question7.setAll("Who painted the Mona Lisa?", "Vincent van Gogh", "Pablo Picasso", "Leonardo da Vinci", "Michelangelo", CorrectAnswer::C, 10);
	Question question8;
	question8.setAll("What is the largest mammal?", "Elephant", "Blue Whale", "Giraffe", "Hippopotamus", CorrectAnswer::B, 10);
	Question question9;
	question9.setAll("What is the currency of Japan?", "Yen", "Dollar", "Euro", "Pound", CorrectAnswer::A, 10);
	Question question10;
	question10.setAll("What is the tallest mountain in the world?", "K2", "Kangchenjunga", "Lhotse", "Mount Everest", CorrectAnswer::D, 10);

	Quiz quiz;
	quiz.setTitle("General Knowledge Quiz");
	quiz.addQuestion(question1);
	quiz.addQuestion(question2);
	quiz.addQuestion(question3);
	quiz.addQuestion(question4);
	quiz.addQuestion(question5);
	quiz.addQuestion(question6);
	quiz.addQuestion(question7);
	quiz.addQuestion(question8);
	quiz.addQuestion(question9);
	quiz.addQuestion(question10);

	quiz.start();

}