#pragma once

#include <iostream>
#include "linkStack.h"
#include "seqQueue.h"

using namespace std;


template<typename T>
class BinaryTree;

template<typename T>
class BinaryTreeNode {
    friend class BinaryTree<T>;

private:
    BinaryTreeNode<T> *_left;//左子树
    BinaryTreeNode<T> *_right;//右子树
    T _data;//数据
public:
    BinaryTreeNode(T data) {
        this->_left = NULL;
        this->_right = NULL;
        this->_data = data;
    }

    BinaryTreeNode() {}//默认构造
};

template<typename T>
class BinaryTree {
private:
    BinaryTreeNode<T> *_root;//根节点
public:
    BinaryTreeNode<T> *_MakeTree(const T *a, size_t size, int &index, const T &invalid);//构造函数使用的递归函数
    BinaryTreeNode<T> *CopyTree(const BinaryTreeNode<T> *_root);//拷贝构造使用的递归函数
    void _PreOrder(BinaryTreeNode<T> *_root);//前序遍历使用的递归函数
    void _InOrder(BinaryTreeNode<T> *_root);//中序遍历使用的递归函数
    void _PostOrder(BinaryTreeNode<T> *_root);//后序遍历使用的递归函数
    void Destroy(BinaryTreeNode<T> *_root);//析构函数使用的递归函数
    int _Depth(BinaryTreeNode<T> *_root);//计算二叉树深度所使用的递归函数
    int _NodeCount(BinaryTreeNode<T> *_root);//计算二叉树结点总数的递归函数
    int _LeafCount(BinaryTreeNode<T> *_root);//计算二叉树叶子节点数的递归函数

public:
    BinaryTree(const T *a, size_t size, int index, const T &invalid);//构造函数
    BinaryTree(const BinaryTree<T> &t);//拷贝构造函数
    BinaryTree() {}//默认构造

    void PreOrder();//前序遍历
    void InOrder();//中序遍历
    void PostOrder();//后序遍历

    void PreOrderTraverse();//非递归前序遍历,使用栈
    void InOrderTraverse();//非递归中序遍历

    void LevelOrder();//层次遍历，使用队列

    int Depth();//计算二叉树深度
    int NodeCount();//计算二叉树节点总数递归函数
    int LeafCount();//计算二叉树叶子结点数

    ~BinaryTree();
};

template<typename T>
BinaryTreeNode<T> *BinaryTree<T>::_MakeTree(const T *a, size_t size,
                                            int &index, const T &invalid) {
    /*
递归：当我们从数组读取到一个数据时，我们先要判断这个值是不是合法，
     如果合法则new出一个结点并初始化作为当前结点，
     此时，进入左孩子递归函数读取下一个数据（++index），
     并把这个函数的返回值链到当前结点root的Left，
     同理，将右孩子递归函数的返回值链到当前结点的right。
     如果不合法则return，返回上一层函数，最后我们会得到一个根结点。
     注：以什么样的顺序建树，就以什么样的顺序传参，NULL用非法值代替
     这里用的先序建树
     */
    BinaryTreeNode<T> *root = NULL;//先定义一个指向空的指针
    if (index < size && a[index] != invalid) {
        root = new BinaryTreeNode<T>(invalid);//给root指针分配内存，默认无效结点
        root->_data = a[index];
        root->_left = _MakeTree(a, size, ++index, invalid);
        root->_right = _MakeTree(a, size, ++index, invalid);
    }
    return root;
}

template<typename T>
BinaryTree<T>::BinaryTree(const T *a, size_t size, int index, const T &invalid) {
    //T类型的指针a，传参时传一个数组，负责传入数据。size保存数组a大小，
    //index记录下标，invalid表示非法值。
    this->_root = _MakeTree(a, size, index, invalid);
}

template<typename T>
BinaryTreeNode<T> *BinaryTree<T>::CopyTree(const BinaryTreeNode<T> *_root) {
    if (_root == NULL)
        return NULL;
    else {
        BinaryTreeNode<T> *root = new BinaryTreeNode<T>(_root->_data);//给root指针分配内存，并存入数据
        root->_left = CopyTree(_root->_left);
        root->_right = CopyTree(_root->_right);
        return root;
    }
}

template<typename T>
int BinaryTree<T>::_Depth(BinaryTreeNode<T> *_root) {
    if (_root == NULL)
        return 0;
    else {
        int m = _Depth(_root->_left) + 1;
        int n = _Depth(_root->_right) + 1;
        return m > n ? m : n;

    }
}

template<typename T>
int BinaryTree<T>::Depth() {
    return _Depth(this->_root);
}

template<typename T>
int BinaryTree<T>::_NodeCount(BinaryTreeNode<T> *_root) {
    if (_root == NULL)
        return 0;
    else
        return _NodeCount(_root->_left) + _NodeCount(_root->_right) + 1;
}

template<typename T>
int BinaryTree<T>::NodeCount() {
    return _NodeCount(this->_root);
}

template<typename T>
int BinaryTree<T>::_LeafCount(BinaryTreeNode<T> *_root) {
    if (_root == NULL)
        return 0;
    if (_root->_left == NULL && _root->_right == NULL)
        return 1;
    else
        return _LeafCount(_root->_left) + _LeafCount(_root->_right);
}

template<typename T>
void BinaryTree<T>::_PreOrder(BinaryTreeNode<T> *_root) {
    if (_root == NULL)
        return;
    else {
        cout << _root->_data << " " << endl;
        _PreOrder(_root->_left);
        _PreOrder(_root->_right);
        return;
    }
}

template<typename T>
void BinaryTree<T>::PreOrder() {
    _PreOrder(_root);//递归遍历
}

template<typename T>
void BinaryTree<T>::_InOrder(BinaryTreeNode<T> *_root) {
    if (_root == NULL) {
        return;
    } else {
        _InOrder(_root->_left);
        cout << _root->_data << " " << endl;
        _InOrder(_root->_right);
        return;
    }
}

template<typename T>
void BinaryTree<T>::InOrder() {
    _InOrder(this->_root);//递归遍历
}

template<typename T>
void BinaryTree<T>::_PostOrder(BinaryTreeNode<T> *_root) {
    if (_root == NULL) {
        return;
    } else {
        _PostOrder(_root->_left);
        _PostOrder(_root->_right);
        cout << _root->_data << " " << endl;
        return;

    }
}

template<typename T>
void BinaryTree<T>::PostOrder() {
    _PostOrder(_root);
}

template<typename T>
void BinaryTree<T>::PreOrderTraverse() {
    BinaryTreeNode<T> *p = this->_root;
    LinkStack<BinaryTreeNode<T>> S;
    if (p == NULL)
        return;
    while (p || !S.StackEmpty()) {
        if (p) {
            S.Push(*p);
            cout << p->_data << endl;
            p->_left;
        } else {
            BinaryTreeNode<T> tem;
            S.Pop(tem);
            p = tem._right;
        }
    }
}

template<typename T>
void BinaryTree<T>::InOrderTraverse() {
    BinaryTreeNode<T> *p = this->_root;
    LinkStack<BinaryTreeNode<T>> S;
    if (p == NULL)
        return;

    while (p || !S.StackEmpty()) {
        if (p) {
            S.Push(*p);
            p = p->_left;
        } else {
            BinaryTreeNode<T> tem;
            S.Pop(tem);
            cout << tem._data << endl;
            p = tem._right;
        }
    }
}

template<typename T>
void BinaryTree<T>::LevelOrder() {
    BinaryTreeNode<T> *b = this->_root;//定义指针p指向二叉树头结点
    BinaryTreeNode<T> *dequ = new BinaryTreeNode<T>;//定义一个二叉树结点，接受出队的结点
    SeqQueue<BinaryTreeNode<T>> *qu = new SeqQueue<BinaryTreeNode<T>>;//初始化一个队列
    qu->EnQueue(*b);
    while (!qu->QueueEmpty()) {
        qu->DeQueue(*dequ);
        cout << dequ->_data << endl;
        if (dequ->_left != NULL)
            qu->EnQueue(*dequ->_left);
        if (dequ->_right != NULL)
            qu->EnQueue(*dequ->_right);
    }
}

template<typename T>
void BinaryTree<T>::Destroy(BinaryTreeNode<T> *_root) {
    BinaryTreeNode<T> *tmp = _root;
    if (tmp == NULL)
        return;
    Destroy(tmp->_left);
    Destroy(tmp->_right);
    delete tmp;
    tmp = NULL;
}

template<typename T>
BinaryTree<T>::~BinaryTree() {
    Destroy(_root);
}








