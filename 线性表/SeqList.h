//
// Created by atomfjf on 2022/2/25.
//

#ifndef CPPSTUDY_SEQLIST_H
#define CPPSTUDY_SEQLIST_H

#pragma once

#include <iostream>

using namespace std;
#define MAXSIZE 100

template<typename T>
class SeqList {
private:
    T *elem;
    int size;
    int length;
public:
    SeqList();

    bool ListEmpty();

    bool ListFull();

public:
    void ShowList();

    void PushBack(const T &e);

    void PushFront(const T &e);

    void PopBack();

    void PopFront();

    void InsertPos(int index, const T &e);

    void DeletePos(int index);

    void DeleteVal(const T &e);

    int Find(const T &e);

    void FindPos(int index, T &e);

    int GetSize();

    void ClearList();

    void DestroyList();

    void Reversal();

    void Sort();

    void Union(SeqList<T> &La, SeqList<T> Lb);

    void MergeSort(SeqList<T> La, SeqList<T> Lb, SeqList<T> &Lc);

    ~SeqList();
};

template<typename T>
SeqList<T>::SeqList() {
    this->elem = (T *) malloc(MAXSIZE * sizeof(T));
    if (!this->elem) {
        cout << "分配地址失败！！！" << endl;
        return;
    }
    this->size = 0;
    this->length = MAXSIZE;
}

template<typename T>
bool SeqList<T>::ListEmpty() {
    if (!this->size) {
        return true;
    }
    return false;
}

template<typename T>
bool SeqList<T>::ListFull() {
    if (this->size == this->length) {
        return true;
    }
    return false;
}

template<typename T>
void SeqList<T>::ShowList() {
    if (this->size == 0) {
        cout << "顺序表为空！ " << endl;
        return;
    }
    for (int i = 0; i < this->size; ++i) {
        cout << elem[i] << endl;
    }
}

template<typename T>
void SeqList<T>::PushBack(const T &e) {
    if (this->ListFull()) {
        cout << "顺序表已满，无法插入" << endl;
        return;
    }
    elem[this->size++] = e;
}

template<typename T>
void SeqList<T>::PushFront(const T &e) {
    if (this->ListFull()) {
        cout << "顺序表已满，无法插入 " << endl;
        return;
    }
    for (int i = this->size; i > 0; --i) {
        elem[i] = elem[i - 1];
    }
    elem[0] = e;
    this->size++;
}

template<typename T>
void SeqList<T>::PopBack() {
    if (this->ListEmpty()) {
        cout << "顺序表为空弄，无法删除" << endl;
        return;
    }
    this->size--;
}

template<typename T>
void SeqList<T>::PopFront() {
    if (this->ListEmpty()) {
        cout << "顺序表为空，无法删除" << endl;
        return;
    }
    for (int i = 0; i < this->size - 1; i++) {
        elem[i] = elem[i + 1];
    }
    this->size--;
}

template<typename T>
void SeqList<T>::InsertPos(int index, const T &e) {
    if (index > this->size || index < 1) {
        cout << "输入位置违法" << endl;
        return;
    }
    if (this->ListFull()) {
        cout << "顺序表已满，无法插入" << endl;
        return;
    }
    for (int i = this->size; i > index - 1; i--) {
        elem[i] = elem[i - 1];
    }
    elem[index - 1] = e;
    this->size++;
}

template<typename T>
void SeqList<T>::DeletePos(int index) {
    if (index > this->size || index < 1) {
        cout << "输入位置违法" << endl;
        return;
    }
    if (this->ListEmpty()) {
        cout << "顺序表为空，无法删除" << endl;
        return;
    }
    for (int i = index - 1; i < this->size - 1; i++) {
        elem[i] = elem[i + 1];
    }
    this->size--;
}

template<typename T>
void SeqList<T>::DeleteVal(const T &e) {
    if (this->ListEmpty()) {
        cout << "顺序表为空，无法删除" << endl;
        return;
    }
    for (int i = 0; i < this->size; i++) {
        if (elem[i] == e) {
            for (int j = i; j < this->size - 1; j++) {
                elem[j] = elem[j + 1];
            }
            this->size--;
            i = 0;
        }
    }
}

template<typename T>
int SeqList<T>::Find(const T &e) {
    for (int i = 0; i < this->size; i++) {
        if (elem[i] == e) {
            return i + 1;
        }
    }
    return -1;
}

template<typename T>
void SeqList<T>::FindPos(int index, T &e) {
    if (index < 1 || index > this->GetSize()) {
        cout << "输入位置不合法" << endl;
        return;
    }
    for (int i = 0; i < this->GetSize(); i++) {
        if (i + 1 == index) {
            e = elem[i];
            break;
        }
    }
}

template<typename T>
void SeqList<T>::DestroyList() {
    if (this->elem) {
        cout << "DestroyList" << endl;
        delete this->elem;
        this->elem = NULL;
        this->length = 0;
        this->size = 0;
    }
}

template<typename T>
void SeqList<T>::ClearList() {
    cout << "ClearList" << endl;
    this->size = 0;
}

template<typename T>
int SeqList<T>::GetSize() {
    return (this->size);
}

template<typename T>
void SeqList<T>::Reversal() {
    T temp;
    for (int i = 0; i < (this->size) / 2; i++) {
        temp = elem[i];
        elem[i] = elem[this->size - 1 - i];
        elem[this->size - 1 - i] = temp;
    }
}

template<typename T>
void SeqList<T>::Sort() {
    //选择排序
    for (int i = 0; i < this->size - 1; ++i) {
        for (int j = i + 1; j < this->size; j++) {
            if (elem[i] > elem[j]) {
                T temp = elem[j];
                elem[j] = elem[i];
                elem[i] = temp;
            }
        }
    }
}

template<typename T>
void SeqList<T>::Union(SeqList<T> &La, SeqList<T> Lb) {
    int La_len = La.GetSize();
    int Lb_len = Lb.GetSize();
    for (int i = 1; i <= Lb_len; i++) {
        T e;
        Lb.FindPos(i, e);
        if (La.find(e) == -1) {
            La.PushBack(e);
        }
    }
}

template<typename T>
void SeqList<T>::MergeSort(SeqList<T> La, SeqList<T> Lb, SeqList<T> &Lc) {
    T *pa = La.elem;
    T *pb = Lb.elem;
    Lc.length = La.length + Lb.length;
    Lc.size = La.size + Lb.size;
    Lc.elem = new T[Lc.length];
    T *pc = Lc.elem;
    T *pa_last = La.elem + La.size - 1;
    T *pb_last = Lb.elem + Lb.size - 1;
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb) {
            *pc++ = *pa++;
        } else {
            *pc++ = *pb++;
        }
    }
    while (pa <= pa_last) {
        *pc++ = *pa++;
    }
    while (pb <= pb_last) {
        *pc++ = *pb++;
    }
}

template<typename T>
SeqList<T>::~SeqList() {

}


#endif //CPPSTUDY_SEQLIST_H

