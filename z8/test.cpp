#include <iostream>
#include "queue.h"
int main() {
    MyQueue<int> myQueue;

    // Test dodawania elementów
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // Test wyświetlania
    std::cout << "Queue elements: ";
    myQueue.display();

    // Test rozmiaru
    std::cout << "Queue size: " << myQueue.size() << std::endl;

    // Test odczytu elementu z przodu
    std::cout << "Front element: " << myQueue.front() << std::endl;

    // Test odczytu elementu z tyłu
    std::cout << "Back element: " << myQueue.back() << std::endl;

    // Test usuwania elementu
    myQueue.pop();
    std::cout << "Queue elements after pop: ";
    myQueue.display();

    // Test czy jest pusta
    std::cout << "Is queue empty? " << (myQueue.empty() ? "Yes" : "No") << std::endl;

    // Test czyszczenia
    myQueue.clear();
    std::cout << "Queue elements after clear: ";
    myQueue.display();

    return 0;
}
