//
// Created by atomfjf on 2022/2/25.
//

#ifndef CPPSTUDY_LINKLIST_H
#define CPPSTUDY_LINKLIST_H

#pragma once

#include<iostream>

using namespace std;

template<typename T>
class LinkList;

template<typename T>
class LinkNode {
    friend class LinkList<T>;

public:
    LinkNode() {
        this->m_data = 0;
        this->next = NULL;
    }

    ~LinkNode() {

    }

private:
    T m_data;
    LinkNode<T> *next;
};

template<typename T>
class LinkList {
private:
    LinkNode<T> *head;
public:
    LinkList();

    void ShowList();

    bool ListEmpty();

    void ListDestroy();

    void ListClear();

    int GetListSize();

    void GetElem(int i, T &e);

    LinkNode<T> *FindElem(const T &e);

    int FindLocateElem(const T &e);

    void InsertPos(const int i, const T &e);

    void DeletePos(const int i);

    void PushFront(const T &e);

    void PushBack(const T &e);

    void Union(LinkList<T> &La, LinkList<T> Lb);

    void MergeSort(LinkList<T> &La, LinkList<T> &Lb, LinkList<T> &Lc);
};

template<typename T>
LinkList<T>::LinkList() {
    this->head = new LinkList<T>;
}

template<typename T>
void LinkList<T>::ShowList(){
    if(!this->GetListSize()){
        cout<<"链表为空，无法打印"<<endl;
        return;
    }
    LinkNode<T> *p=this->head;
    while(p->next){
        cout << p->next->m_data<<endl;
        p=p->next;
    }
}

template<typename T>
bool LinkList<T>::ListEmpty(){
    if(this->head->next==NULL){
        cout<<"头结点指向为空，链表为空，返回1"<<endl;
        return 1;
    }else{
        cout<<"链表不为空，返回0"<<endl;
        return 0;
    }
}

template<typename T>
void LinkList<T>::ListDestroy(){
    LinkNode<T> *p;
    while(this->head){
        p=this->head;
        this->head=this->head->next;
        delete p;
    }
    cout<<"ListDestroy"<<endl;
}

template<typename T>
void LinkList<T>::ListClear(){
    LinkNode<T> *p,*q;
    p=this->head->next;
    while(p){
        q=p->next;
        delete p;
        p=q;
    }
    this->head->next=NULL;
    cout << "ListClear"<<endl;
}

template<typename T>
int LinkList<T>::GetListSize(){
    LinkNode<T> *p;
    p=this->head->next;
    int i=0;
    while(p){
        i++;
        p=p->next;
    }
    return i;
}

template<typename T>
void LinkList<T>::GetElem(int i, T &e) {
    if(i<=0||i>this->GetListSize()){
        cout << "位置"<<i<<"输入错误！"<<endl;
        return;
    }
    LinkNode<T> *p;
    p=this->head->next;
    int j=1;
    while(p){
        if(i==j){
            e=p->m_data;
            break;
        }
        p=p->next;
        j++;
    }
}

template<typename T>
LinkNode<T> *LinkList<T>::FindElem(const T &e) {
    LinkNode<T> *p;
    p=this->head->next;

    while (p){
        if(p->m_data==e){
            return p;
        }
        p=p->next;
    }
    cout<<"查无此值，返回空"<<endl;
    return p;
}

template<typename T>
int LinkList<T>::FindLocateElem(const T &e) {
    LinkNode<T> *p=this->head->next;
    int j=1;
    while(p){
        if(p->m_data==e){
            return j;
        }
        p=p->next;
        j++;
    }
    return -1;
}

template<typename T>
void LinkList<T>::InsertPos(const int i,const T &e){
    if(i<1||i>this->getSize()+1){
        cout <<"插入位置"<<i<<"输入不合法！"<<endl;
        return;
    }
    int j=1;
    LinkList<T> *p=this->head;
    while(j<=i-1){
        p=p->next;
        j++;
    }
    LinkNode<T> *s=new LinkNode<T>;
    s->m_data=e;
    s->next=p->next;
    p->next=s;
}

template<typename T>
void LinkList<T>::DeletePos(const int i){
    if (i < 1 || i > this->GetListSize()) {
        cout << "删除位置" << i << "不合法" << endl;
        return;
    }
    int j=1;
    LinkList<T> *p=this->head;
    while(j<=i-1){
        j++;
        p=p->next;
    }
    LinkList<T> *q=p->next;
    p->next=q->next;
    delete q;
}

template<typename T>
void LinkList<T>::PushFront(const T &e){
    this->InsertPos(1,e);
}

template<typename T>
void LinkList<T>::PushBack(const T &e){
    this->InsertPos(this->GetListSize()+1,e);
}

template<typename T>
void LinkList<T>::Union(LinkList<T> &La, LinkList<T> Lb) {
    int La_len = La.GetSize();
    int Lb_len = Lb.GetSize();

    for (int i = 1; i <= Lb_len; ++i) {
        T e;
        Lb.GetElem(i,e);
        if(La.FindLocateElem(e)==-1){
            La.PushBack(e);
        }
    }
}

template<typename T>
void LinkList<T>::MergeSort(LinkList<T> &La, LinkList<T> &Lb, LinkList<T> &Lc) {
    LinkNode<T> *pa=La.head->next;
    LinkNode<T> *pb=Lb.head->next;
    LinkNode<T> *pc=Lc.head=La.head;

    while(pa&&pb){
        if(pa->m_data<=pb->m_data){
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }else{
            pc->next=pb;
            pc=pb;
            pb->next;

        }
    }
    pc->next=pa?pa:pb;

}
























#endif //CPPSTUDY_LINKLIST_H
