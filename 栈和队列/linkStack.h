#pragma once

#include <iostream>

using namespace std;

template<typename T>
class LinkStack;

template<typename T>
class LinkNode_Stack {
    friend class LinkStack<T>;

public:
    LinkNode_Stack() {
        this->next = NULL;
    }

    ~LinkNode_Stack() {

    }

private:
    T m_data;
    LinkNode_Stack<T> *next;
};

template<typename T>
class LinkStack {
private:
    LinkNode_Stack<T> *head;
public:
    LinkStack();

    bool StackEmpty();

    void ShowLinkStack();

    void Push(const T &e);

    void Pop(T &e);

    ~LinkStack();
};

template<typename T>
LinkStack<T>::LinkStack() {
    this->head = new LinkNode_Stack<T>;
}

template<typename T>
bool LinkStack<T>::StackEmpty() {
    if (this->head->next == NULL)
        return true;
    return false;
}

template<typename T>
void LinkStack<T>::ShowLinkStack() {
    if (this->StackEmpty()) {
        cout << "链栈为空，无法打印" << endl;
        return;
    }
    LinkNode_Stack<T> *p = this->head;
    while (p->next) {
        cout << p->m_data << endl;
        p = p->next;
    }
}

template<typename T>
void LinkStack<T>::Push(const T &e) {
    LinkNode_Stack<T> *p = new LinkNode_Stack<T>;
    p->m_data = e;
    p->next = this->head;
    this->head = p;
}

template<typename T>
void LinkStack<T>::Pop(T &e) {
    if (this->StackEmpty()) {
        cout << "链栈为空，无法出栈" << endl;
        return;
    }
    e = this->head->m_data;
    LinkNode_Stack<T> *p = this->head;
    this->head = this->head->next;
    delete p;
}

template<typename T>
LinkStack<T>::~LinkStack<T>() {

}