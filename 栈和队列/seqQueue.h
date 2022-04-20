#pragma once

#include <iostream>

using namespace std;
#define MAXQSIZE 5

template<typename T>
class SeqQueue {
private:
    T *base;
    int front;
    int rear;
public:
    SeqQueue();

    int QueueLength();

    void ShowQueue();

    void EnQueue(const T &e);

    void DeQueue(T &e);

    ~SeqQueue();
};

template<typename T>
SeqQueue<T>::SeqQueue() {
    this->base = new T[MAXQSIZE];
    if (!this->base) {
        cout << "内存分配失败" << endl;
        return;
    }
    this->front = 0;
    this->rear = 0;
}

template<typename T>
int SeqQueue<T>::QueueLength() {
    return (this->rear - this->front + MAXQSIZE) % MAXQSIZE;
}

template<typename T>
void SeqQueue<T>::ShowQueue() {
    if (this->front == this->rear) {
        cout << "队列为空，无法打印" << endl;
        return;
    }
    int length = this->QueueLength();
    int i = this->front;
    while (length) {
        cout << this->base[i] << endl;
        i = (i + 1) % MAXQSIZE;
        length--;
    }
}

template<typename T>
void SeqQueue<T>::EnQueue(const T &e) {
    if ((this->rear + 1) % MAXQSIZE == this->front) {
        cout << "队列已满，无法插入" << endl;
        return;
    }
    this->base[this->rear] = e;
    this->rear = (this->rear + 1) % MAXQSIZE;
}

template<typename T>
void SeqQueue<T>::DeQueue(T &e) {
    if (this->front == this->rear) {
        cout << "队列为空，无法删除" << endl;
        return;
    }
    e = this->base[this->front];
    this->front = (this->front + 1) % MAXQSIZE;
}

template<typename T>
SeqQueue<T>::~SeqQueue() {

}