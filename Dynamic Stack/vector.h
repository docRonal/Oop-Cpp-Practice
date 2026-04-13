#include <vector>
#include <iostream>
#include <cstdlib> 
class Stack
{
private:
public:
    int* dane;   
    int size;      
    int capacity; 

    void resize(int newCapacity)
    {
        int* newData = (int*)std::realloc(dane, newCapacity * sizeof(int));
        if (!newData)
        {
            std::cout << "blad \n";
            std::exit(1);
        }
        dane = newData;
        capacity = newCapacity;
    }
    Stack()
    {
        size = 0;
        capacity = 4;
        dane = (int*)std::calloc(capacity, sizeof(int));
        if (!dane)
        {
            std::cout << "blad\n";
            std::exit(1);
        }
    }
    ~Stack()
    {
        std::free(dane);
    }
    void push(int a)
    {
        if (size >= capacity)
        {
            resize(capacity * 2);
        }
        dane[size++] = a;
    }
    int pop()
    {
        if (size == 0)
        {
            std::cout << "pusty stos\n";
            return 0;
        }
        return dane[--size];
    }
    void clear()
    {
        size = 0;
    }
};



	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
/*
private:
public:
    //std::vector<int> dane;
    Stack();
    ~Stack();
	int* dane;
    void push(int a);
    int pop();
    void clear();
    void show();
};

Stack::Stack()
{
}

Stack::~Stack()
{
}

void Stack::push(int a) // wnutri klassa 
{
    dane.push_back(a);
}

int Stack::pop()
{
    int temp = dane.back();
    dane.pop_back();
    return temp;
}

void Stack::clear()
{#include <cstdlib> // malloc, realloc, free
    for (int i = 0; i < (int)dane.size() - 1; i++) {
        dane.pop_back();
    }
}

void Stack::show()
{
    for (int i : dane)
    {
        std::cout << i << "\n";
    }
}
*/
