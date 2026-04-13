/*
Dokończyć (niczego nie zmieniając, jedynie dopisując) deklarację klas CElement i CStack tak, żeby poprawnie działały w podanej funkcji main.
*/

#include <string.h>
#include <iostream>


class EmptyStack
{
};

class CElement
{
private:
    int value;

public:
    CElement() : value(0) {}
    CElement(int val) : value(val) {}

    int getValue() const { return value; }
    int setValue(int val)
    {
        value = val;
        return value;
    }
};

class CStack
{
private:
    CElement *pData;
    unsigned int top;
    unsigned int size;

public:
    CStack() : pData(nullptr), top(0), size(10)
    {
        pData = new CElement[size];
    }
    CStack(const CStack &other) : pData(nullptr), top(other.top), size(other.size)
    {
        pData = new CElement[size];
        for (unsigned int i = 0; i < top; i++)
        {
            pData[i] = other.pData[i];
        }
    }
    CStack &operator=(const CStack &other)
    {
        if (this != &other)
        {
            delete[] pData;
            size = other.size;
            top = other.top;
            pData = new CElement[size];
            for (unsigned int i = 0; i < top; i++)
            {
                pData[i] = other.pData[i];
            }
        }
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const CStack &stack)
    {
        for (int i = stack.top - 1; i >= 0; i--)
        {
            os << stack.pData[i].getValue();
            if (i > 0)
                os << ' ';
        }
        return os;
    }
    void push(int val)
    {
        if (top >= size)
        {
            CElement *newData = new CElement[size * 2];
            for (unsigned int i = 0; i < size; i++)
            {
                newData[i] = pData[i];
            }
            delete[] pData;
            pData = newData;
            size *= 2;
        }
        pData[top].setValue(val);
        top++;
    }
    int pop()
    {
        if (top == 0)
        {
            throw EmptyStack();
        }
        top--;
        return pData[top].getValue();
    }
    ~CStack()
    {
        delete[] pData;
    }
};
