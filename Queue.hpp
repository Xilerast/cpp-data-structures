#pragma once

#include <algorithm>
#include <assert.h>

template <typename T>
class Queue
{
private:
    T *Data;
    unsigned int MaxElemNum, Beginning, End, ElemCount;
public:
    Queue(void);
    Queue(unsigned int MaxSize);
    Queue(const Queue<T> &other);
    ~Queue();
};

template<typename T>
Queue<T>::Queue(void)
{
}

template <typename T>
inline Queue<T>::Queue(unsigned int MaxSize) : MaxElemNum(MaxSize)
{
    this->Data = new T[this->MaxElemNum];
    this->Beginning = 0;
    this->End = 0;
    this->ElemCount = 0;
}

template <typename T>
inline Queue<T>::Queue(const Queue<T> &other) : MaxElemNum(other.MaxElemNum), ElemCount(other.ElemCount)
{
    this->Data = new T[this->MaxElemNum];
    this->Beginning = other.Beginning;
    this->End = other.End;
    // TODO: COPY THE DATA
}

template<typename T>
Queue<T>::~Queue()
{
    delete[] this->data;
    this->Data = nullptr;
}
