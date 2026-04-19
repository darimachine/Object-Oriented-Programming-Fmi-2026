#include <iostream>
#include <string>
#include "Queue.hpp"

template <typename T>
void goThroughQueue(Queue<T> q) {
    while (!q.isEmpty()) {
        std::cout << q.peek() << ' ';
        q.pop();
    }
    std::cout << '\n';
}

int main() {
    std::cout << "Queue<int>:\n";
    Queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    std::cout << "Front: " << q.peek() << '\n';
    std::cout << "Size: " << q.getSize() << '\n';

    q.pop();
    std::cout << "After one pop, front: " << q.peek() << '\n';

    goThroughQueue(q);

    q.push(40);
    q.push(50);

    std::cout << "Current queue: ";
    goThroughQueue(q);

    std::cout << "\nTesting circular buffer:\n";
    Queue<int> circular(4);
    circular.push(1);
    circular.push(2);
    circular.push(3);
    circular.push(4);

    circular.pop();
    circular.pop();

    circular.push(5);
    circular.push(6);

    std::cout << "Queue after wrap-around: ";
    goThroughQueue(circular);

    std::cout << "\nTesting resize:\n";
    Queue<int> resized(2);
    resized.push(100);
    resized.push(200);
    resized.push(300);
    resized.push(400);

    std::cout << "Resized queue: ";
    goThroughQueue(resized);

    std::cout << "\nQueue<std::string>:\n";
    Queue<std::string> words;
    words.push("templates");
    words.push("are");
    std::string text = "useful";
    words.push(std::move(text));

    std::cout << "Front: " << words.peek() << '\n';
    std::cout << "All elements: ";
    goThroughQueue(words);

    return 0;
}
