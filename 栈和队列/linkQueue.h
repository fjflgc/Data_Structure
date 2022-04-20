#pragma once

#include <iostream>

using namespace std;
#define MAXLQSIZE 100

template<typename T>
class LinkQueue;

template<typename T>
class LinkNode_Queue {
    friend class LinkQueue<T>;

private:
    T m_data;
    LinkNode_Queue<T> *next;
public:
    LinkNode_Queue() {
        this->m_data = 0;
        this->next = NULL;
    }

    ~LinkNode_Queue() {

    }
};

template<typename T>
class LinkQueue {
private:
    LinkNode_Queue<T> *front;
    LinkNode_Queue<T> *rear;
public:
    LinkQueue();

    void DestroyQueue();

    void ShowQueue();

    void EnQueue(const T &e);

    void DeQueue(T &e);

    ~LinkQueue();

};

template<typename T>
LinkQueue<T>::LinkQueue() {
    this->front = new LinkNode_Queue<T>;
    if (!this->front) {
        cout << "内存分配失败" << endl;
        return;
    }
    this->rear = this->front;
}

template<typename T>
void LinkQueue<T>::DestroyQueue() {
    while (this->front) {
        LinkNode_Queue<T> *p = this->front->next;
        delete this->front;
        this->front = p;
    }
}

template<typename T>
void LinkQueue<T>::ShowQueue() {
    if (this->front == this->rear) {
        cout << "队列为空，无法打印" << endl;
        return;
    }
    //这里存在头结点
    LinkNode_Queue<T> *p = this->front->next;
    while (p) {
        cout << p->m_data << endl;
        p = p->next;
    }
}

template<typename T>
void LinkQueue<T>::EnQueue(const T &e) {
    LinkNode_Queue<T> *p = new LinkNode_Queue<T>;
    p->m_data = e;
    this->rear->next = p;
    this->rear = this->rear->next;
}

template<typename T>
void LinkQueue<T>::DeQueue(T &e) {
    if (!this->front) {
        cout << "队列为空，无法出队" << endl;
        return;
    }
    e = this->front->next->m_data;
    LinkNode_Queue<T> *p = this->front->next;
    this->front->next = this->front->next->next;
    if (this->rear == p)
        this->rear = this->front;
    delete p;
}

template<typename T>
LinkQueue<T>::~LinkQueue() {

}