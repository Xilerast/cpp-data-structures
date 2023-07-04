#ifndef STACK_HPP
#define STACK_HPP

#include <algorithm>
#include <assert.h>

template <typename T>
class Stack
{
private:
    T *Data;
    int CurrElemNum;
    unsigned int MaxElemNum;
public:
    // Constructors
    Stack(void);
    Stack(unsigned int MaxSize);
    Stack(const Stack<T> &Other); // Copy constructor
    Stack(Stack<T> &&Other) noexcept; // Move constructor

    // Destructor
    ~Stack();

    void Push(const T &elem);
    T Pop();
    const T& Peek(int Depth) const;

    Stack<T>& operator=(const Stack<T> &Other); // Copy assignment
    Stack<T>& operator=(Stack<T> &&Other) noexcept; // Move assignment
};

template <typename T>
Stack<T>::Stack(void)
{
}

template <typename T>
Stack<T>::Stack(unsigned int MaxSize) : MaxElemNum(MaxSize)
{
    this->Data = new T[this->MaxElemNum];
    this->CurrElemNum = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T> &Other) : MaxElemNum(Other.MaxElemNum)
{
    this->Data = new T[this->MaxElemNum];
    this->CurrElemNum = Other.CurrElemNum;
    std::copy(Other.Data, Other.Data + (Other.CurrElemNum - 1) * sizeof(T), this->Data);
}

template <typename T>
Stack<T>::Stack(Stack<T> &&Other) noexcept : Data(Other.Data), CurrElemNum(Other.CurrElemNum), MaxElemNum(Other.MaxElemNum)
{
    this->Data = nullptr;
    this->CurrElemNum = 0;
    this->MaxElemNum = 0;
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] this->Data;
    this->Data = nullptr;
}

template <typename T>
void Stack<T>::Push(const T &elem)
{
    assert(this->CurrElemNum < this->MaxElemNum);

    this->Data[this->CurrElemNum++] = elem;
}

template <typename T>
T Stack<T>::Pop()
{
    assert(this->CurrElemNum > 0);

    return this->Data[--this->CurrElemNum];
}

template <typename T>
const T &Stack<T>::Peek(int Depth) const
{
    assert(Depth < this->CurrElemNum);

    const unsigned int elemIndex = this->CurrElemNum - Depth - 1;
    return this->Data[elemIndex];
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &Other)
{
    this->CurrElemNum = Other.CurrElemNum;
    this->MaxElemNum = Other.MaxElemNum;
    this->Data = new T[this->MaxElemNum];
    std::copy(Other.Data, Other.Data + sizeof(T) * (Other.CurrElemNum - 1), this->Data);
    return *this;
}

template <typename T>
Stack<T> &Stack<T>::operator=(Stack<T> &&Other) noexcept
{
    this->CurrElemNum = Other.CurrElemNum;
    Other.CurrElemNum = 0;
    this->MaxElemNum = Other.MaxElemNum;
    Other.MaxElemNum = 0;
    this->Data = Other.Data;
    Other.Data = nullptr;
    return *this;
}

#endif