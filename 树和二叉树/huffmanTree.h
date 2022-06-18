#pragma once

#include <iostream>

using namespace std;

class HuffmanTree;

class H_Node {
private:
    float weight;
    int parent, lch, rch;
    char *code;//定义存储哈夫曼编码的字符串指针备用
public:
    friend class HuffmanTree;//友元类，能够访问私有属性
    H_Node() {
        this->weight = 0;
        this->parent = 0;
        this->lch = 0;
        this->rch = 0;
        this->code = NULL;
    }
};

class HuffmanTree {
private:
    H_Node *HT;
public:
    HuffmanTree();

    H_Node *CreateHuffmanTree();//默认构造
    H_Node *CreateHuffmanTree(float *weight, int n);//有参构造
    void ShowHuffmanTree(int length);//打印哈夫曼树
    void CreateHuffmanCode(float *weight, int n);//通过HC返回
    void ShowHuffmanCode(int n);

    ~HuffmanTree();//析构函数
};

HuffmanTree::HuffmanTree() {

}

H_Node *HuffmanTree::CreateHuffmanTree(float *weight, int n) {
    if (n <= 1)
        return NULL;
    //计算最终存储哈夫曼树所需的存储空间
    int m = 2 * n - 1;
    //创建存储空间
    this->HT = new H_Node[m + 1];//从序号1开始存储，方便计算
    //将原始结点输入到哈夫曼树存储空间内
    for (int i = 1; i <= n; ++i)
        this->HT[i].weight = weight[i - 1];
//构造哈夫曼树
    H_Node *p = HT;
    for (int j = n + 1; j <= m; j++) {
        //提取未使用的最下的两个结点
        int S1 = 0, S2 = 0;
        int count1 = 0, count2 = 0;
        //提取S1
        for (int k = 1; k <= j - 1; k++) {
            if (p[k].parent == 0) {
                if (count1 == 0)//第一次循环时给S1赋初始值
                {
                    S1 = k;
                    count1++;
                }
                if (p[S1].weight >= p[k].weight)
                    S1 = k;
            }
        }
        //提取S2
        for (int h = 1; h <= j - 1; h++) {
            if (p[h].parent == 0 && h != S1)//如果双亲为0，才进行比较
            {
                if (count2 == 0)//第一次循环时给S2赋初始值
                {
                    S2 = h;
                    count2++;
                }
                if (p[S2].weight >= p[h].weight)
                    S2 = h;
            }
        }
        //存储双亲结点,孩子结点的index,构造新的结点
        HT[S1].parent = j;
        HT[S2].parent = j;
        HT[j].lch = S1;
        HT[j].rch = S2;
        HT[j].weight = HT[S1].weight + HT[S2].weight;
    }
    this->ShowHuffmanTree(m);
    return HT;
}

void HuffmanTree::ShowHuffmanTree(int length) {
    cout << "index" << "\t" << "weight" << "\t" << "parent" << "\t" << "lch" << "\t" << "rch" << endl;
    for (int i = 0; i <= length; i++)
        cout << i << "\t" << HT[i].weight << "\t" << HT[i].parent << "\t" << HT[i].lch << "\t" << HT[i].rch << endl;
}

void HuffmanTree::CreateHuffmanCode(float *weight, int n) {
    H_Node *HT = CreateHuffmanTree(weight, n);
    for (int i = 1; i <= n; i++) {
        char *cd = new char[n];//建立存放临时编码的字符串，反向存储，正向读取
        cd[n - 1] = '\0';
        int start = n - 1;
        int c = i;//临时存放结点的索引
        int f = HT[i].parent;//保存结点的双亲索引
        while (f != 0)//双亲不为0，说明编码没有结束，一直执行
        {
            --start;//临时字符串数组的指针先指向倒数第二个位置
            if (HT[f].lch == c)//左节点给0
                cd[start] = '0';
            else//右结点给1
                cd[start] = '1';
            c = f;
            f = HT[f].parent;
        }
        HT[i].code = new char[n - start];
        for (int j = start; j <= n - 1; j++)
            HT[i].code[j - start] = cd[j];
    }
    this->ShowHuffmanCode(n);
}

void HuffmanTree::ShowHuffmanCode(int n) {
    cout << "index" << "\t" << "weigth" << "\t" << "code" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << "\t" << HT[i].weight << "\t";
        char *p = HT[i].code;
        while (*p)//判断是否到截止符号'\0'
            cout << *(p++);
        cout << endl;
    }
}

HuffmanTree::~HuffmanTree() {

}

