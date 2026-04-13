#include "vectors.h"
#include <iostream>
#include <cassert>

void test_push_pop() {
    Stack s1;
    Stack s2;
    s1.push(10);
    s1.push(20);
    s2.push(30);

    assert(s2.pop() == 30);
    assert(s1.pop() == 20);
    assert(s1.pop() == 10);//proverka cisel dla oszybki
}

void test_lifo_order() {
    Stack s1;
    for (int i = 1; i <= 5; ++i)
        s1.push(i);

    for (int i = 5; i >= 1; --i)
        assert(s1.pop() == i);
}


int main() {
    Stack s1;
    Stack s2;

    std::cout << "testy wykladowe\n";

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s2.push(4);
    s2.push(5);

    std::cout << s1.pop() << " " << s2.pop() << "\n";
    std::cout << s1.pop() << "\n";

    std::cout << "test lifo order\n";
    test_lifo_order();
    

    std::cout << "test push pop\n";
    test_push_pop();

    return 0;
}

