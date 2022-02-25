#pragma once

#include<iostream>

using namespace std;

#define MAXSIZE 100


template<typename T>
class SeqList {
private:
    T *elem;        //存储空间基址
    int size;        //当前顺序表长度
    int length;        //顺序表长度
public:
    SeqList();//默认构造
    bool ListEmpty();//判断顺序表是否为空
    bool ListFull();//判断顺序表是否满
public:
    void ShowList();//打印顺序表
    void PushBack(const T &e);//尾插
    void PushFront(const T &e);//头插
    void PopBack();//尾删
    void PopFront();//头删
    void InsertPos(int index, const T &e);//按位置插入
    void DeletePos(int index);//按位置删除
    void DeleteVal(const T &e);//按值删除
    int Find(const T &e);//按值查询,返回第一个值的位置
    void FindPos(int index, T &e);//按位置查询，通过e返回
    int GetSize();//求顺序表的长度
    void ClearList();//清空顺序表
    void DestroyList();//销毁顺序表
    void Reversal();//反转顺序表
    void Sort();//排序，从小到大
    void Union(SeqList<T> &La, SeqList<T> Lb);//合并两个顺序表，通过La返回合并后的，并集！
    void MergeSort(SeqList<T> La, SeqList<T> Lb, SeqList<T> &Lc);//有序表合并!合并La，Lb(La、Lb均为有序的)，并进行排序，通过Lc返回
    ~SeqList();//析构函数

};

template<typename T>
SeqList<T>::SeqList() {
    this->elem = (T *) malloc(MAXSIZE * sizeof(T));//分配内存，并强制转换为T*
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
        //cout << "顺序表为空" << endl;
        return true;
    }
    return false;
}

template<typename T>
bool SeqList<T>::ListFull() {
    if (this->size == this->length) {
        //cout << "顺序表已满" << endl;
        return true;
    }
    return false;
}


template<typename T>
void SeqList<T>::ShowList() {
    if (this->size == 0) {
        cout << "顺序表为空！" << endl;
        return;
    }

    for (int i = 0; i < this->size; i++) {
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
        cout << "顺序表已满，无法插入" << endl;
        return;
    }
    for (int i = this->size; i > 0; i--) {
        elem[i] = elem[i - 1];
    }
    elem[0] = e;
    this->size++;
}


template<typename T>
void SeqList<T>::PopBack() {
    if (this->ListEmpty()) {
        cout << "顺序表为空，无法删除" << endl;
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
    //注意这里index不是元素的下标，而是第几个元素
    if (index > this->size || index < 1) {
        cout << "输入位置违法！" << endl;
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
        cout << "输入位置违法！" << endl;
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
            i = 0;//i重新从0开始
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
    //cout << "查无此值！" << endl;
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
    //cout << "线性表当前长度/总长度:" << this->size << "/" << this->length << endl;
    return (this->size);
}

template<typename T>
void SeqList<T>::Reversal() {
    T temp;
    for (int i = 0; i < (this->size) / 2; i++) {
        temp = elem[i];
        elem[i] = elem[this->size - i - 1];
        elem[this->size - i - 1] = temp;
    }
}

template<typename T>
void SeqList<T>::Sort() {
    //选择排序
    for (int i = 0; i < this->size - 1; i++) {
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
    //获得表a、b的长度
    int La_len = La.GetSize();
    int Lb_len = Lb.GetSize();
    for (int i = 1; i <= Lb_len; i++) {
        T e;
        Lb.FindPos(i, e);//按位置查找，返回数据到e
        if (La.Find(e) == -1)//按值查找，返回查找值的位置，若查无此值，返回-1
        {
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
    Lc.elem = new T[Lc.length];//开辟一块内存，让Lc指向这块内存首地址
    T *pc = Lc.elem;
    T *pa_last = La.elem + La.size - 1;
    T *pb_last = Lb.elem + Lb.size - 1;
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb) {
            //cout << *pa << endl;
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
