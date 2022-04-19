#pragma once

#include <iostream>

using namespace std;
#define MAXSIZE 100

template<typename T>
class SeqStack {
private:
    T *top;
    T *base;
    int stackSize;
public:
    SeqStack();

    bool StackEmpty();

    bool StackFull();

    void ClearStack();

    void DestroyStack();

    void ShowStack();

    void Push(const T &e);

    void Pop(T &e);

    ~SeqStack();
};

template<typename T>
SeqStack<T>::SeqStack() {
    this->base = new T[MAXSIZE];
    if (!this->base) {
        cout << "分配地址失败" << endl;
        return;
    }
    this->top = this->base;
    this->stackSize = MAXSIZE;
}

template<typename T>
bool SeqStack<T>::StackEmpty() {
    if (this->base == this->top) {
        cout << "栈为空" << endl;
        return true;
    }
    return false;
}

template<typename T>
bool SeqStack<T>::StackFull() {
    if ((this->top - this->base) == this->stackSize) {
        cout << "栈为满" << endl;
        return true;
    }
    return false;
}

template<typename T>
void SeqStack<T>::ClearStack() {
    if (this->base) {
        this->top = this->base;
        cout << "ClearStack" << endl;
        return;
    }
    cout << "栈不存在，无法清空" << endl;
}

template<typename T>
void SeqStack<T>::DestroyStack() {
    if (this->base) {
        delete this->base;
        this->stackSize = 0;
        this->base = NULL;
        this->top = NULL;
        cout << "DestroyStack" << endl;
        return;
    }
    cout << "栈不存在，无法销毁" << endl;
}

template<typename T>
void SeqStack<T>::ShowStack() {
    if (this->StackEmpty()) {
        cout << "栈为空，无法打印" << endl;
        return;
    }
    T *p = this->base;
    while (p != this->top)
        cout << *p++ << endl;
}

template<typename T>
void SeqStack<T>::Push(const T &e) {
    if (this->StackFull()) {
        cout << "栈已满，无法入栈" << endl;
        return;
    }
    *this->top++ = e;
}

template<typename T>
void SeqStack<T>::Pop(T &e) {
    if (this->StackEmpty()) {
        cout << "栈为空，无法出栈" << endl;
        return;
    }
    e = *--this->top;
}

template<typename T>
SeqStack<T>::~SeqStack() {}
