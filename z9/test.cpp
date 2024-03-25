#include <iostream>
#include "pqueue.h"  // Wstaw właściwą nazwę pliku nagłówkowego

int main() {
    // Test default constructor
    MyPriorityQueue<int> pq1;
    std::cout << "Test: Default Constructor\n";
    std::cout << "Result: ";
    pq1.display();

    // Test constructor with size
    MyPriorityQueue<int> pq2(5);
    std::cout << "\nTest: Constructor with Size\n";
    std::cout << "Result: ";
    pq2.display();

    // Test adding elements using push
    pq1.push(10);
    pq1.push(30);
    pq1.push(20);
    std::cout << "\nTest: Adding Elements using push to pq1\n";
    std::cout << "Result: ";
    pq1.display();

    // Test copy constructor
    MyPriorityQueue<int> pq3(pq1);
    std::cout << "\nTest: Copy Constructor with pq3 and pq1\n";
    std::cout << "Result: ";
    pq3.display();
    pq1.display();

    // Test copy assignment operator
    MyPriorityQueue<int> pq4;
    pq4 = pq1;
    std::cout << "\nTest: Copy Assignment Operator\n";
    std::cout << "Result: ";
    pq4.display();

    // Test top method
    std::cout << "\nTest: Top Method\n";
    std::cout << "Top element of pq3: " << pq3.top() << std::endl;

    // Test pop method
    pq3.pop();
    std::cout << "\nTest: Pop Method\n";
    std::cout << "After pop, top element of pq3: " << pq3.top() << std::endl;

    // Test size method
    std::cout << "\nTest: Size Method\n";
    std::cout << "Size of pq3: " << pq3.size() << std::endl;

    // Test empty method
    std::cout << "\nTest: Empty Method\n";
    std::cout << "Is pq3 empty? " << (pq3.empty() ? "Yes" : "No") << std::endl;

    // Test clear method
    pq3.clear();
    std::cout << "\nTest: Clear Method\n";
    std::cout << "After clear, size of pq3: " << pq3.size() << std::endl;

    // Test display method
    std::cout << "\nTest: Display Method\n";
    std::cout << "Elements in pq4: ";
    pq4.display();

    return 0;
}

