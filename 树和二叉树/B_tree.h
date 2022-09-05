#include <iostream>

#define m 3
typedef int KeyType;
using namespace std;
typedef struct {
    KeyType key;
    char data;
} Record;

typedef struct BTNode {
    int keynum;//节点中关键字个数，即节点的大小
    struct BTNode *parent;//指向双亲节点
    KeyType key[m + 1];//关键字向量，0号单元未用
    struct BTNode *ptr[m + 1];//指向孩子节点的指针向量，0号单元未用
    Record *recptr[m + 1];//记录指针向量，0号单元未用
} BTNode, *BTree;

typedef struct {
    BTree pt; //指向找到的节点
    int i; //1..m，指示关键字在节点中的位置
    int tag; //1：查找成功，0：查找失败
} Result;

int Search(BTree p, KeyType key)
{
    int i = 1;
    while (i <= p->keynum && key > p->key[i])
        i++;
    return i;
}

void SearchBTree(BTree t, KeyType key, Result &r)
{
    int i = 0;
    int found = 0;
    BTree p = t;//一开始指向根节点,之后指向待查节点
    BTree q = NULL;//指向待查节点的双亲
    while (p != NULL && found == 0)
    {
        i = Search(p, key);//在p中查找关键字key
        if (i <= p->keynum && key == p->key[i])//查找成功
            found = 1;
        else
        {
            q = p;
            p = p->ptr[i - 1];//指针下移
        }
    }
    //查找成功，返回key的位置p和i
    if (1 == found)
    {
        r.pt = p;
        r.i = i;
        r.tag = 1;
    }
    else
    {
        r.pt = q;
        r.i = i;
        r.tag = 0;
    }
}

void newRoot(BTree &t, BTree p, KeyType key, BTree ap)
{
    t = (BTree) malloc(sizeof(BTNode));
    t->keynum = 1;
    t->ptr[0] = p;
    t->ptr[1] = ap;
    t->key[1] = key;
    if (p != NULL)
        p->parent = t;
    if (ap != NULL)
        ap->parent = t;
    t->parent = NULL;
}

void Insert(BTree &q, int i, KeyType key, BTree ap)
{
    int j;
    int n = q->keynum;
    for (j = n; i >= i; j--)
    {
        q->key[j + 1] = q->key[j];
        q->ptr[j + 1] = q->ptr[j];
    }
    q->key[i] = key;
    q->ptr[i] = ap;
    if (ap != NULL)
        ap->parent = q;
    q->keynum++;
}

void split(BTree &q, int s, BTree &ap)
{
    int i, j;
    int n = q->keynum;
    ap = (BTree) malloc(sizeof(BTNode));
    ap->ptr[0] = q->ptr[s];
    for (i = s + 1, j = 1; i <= n; i++, j++)
    {
        ap->key[j] = q->key[i];
        ap->ptr[j] = q->ptr[i];
    }
    ap->keynum = n - s;
    ap->parent = q->parent;
    for (i = 0; i <= n - s; i++)
    {
        if (ap->ptr[i] != NULL)
            ap->ptr[i]->parent = ap;
    }
    q->keynum = s - 1;
}

void InsertBTree(BTree &t, KeyType key, BTree q, int i)
{
    KeyType x;
    int s;
    int finished = false;
    int needNewRoot = false;
    BTree ap;
    if (NULL == q)
        newRoot(t, NULL, key, NULL);
    else
    {
        x = key;
        ap = NULL;
        while (false == needNewRoot && false == finished)
        {
            Insert(q, i, x, ap);//x和ap分别插入到q->key[i-1]和q->ptr[i]
            if (q->keynum < m)
                finished = true;
            else
            {
                s = (m + 1) / 2;//得到中间节点位置
                split(q, s, ap);//分裂q节点
                x = q->key[s];
                if (q->parent != NULL)
                {
                    q = q->parent;
                    i = Search(q, x);
                }
                else
                    needNewRoot = true;
            }
        }
    }
    if (needNewRoot)
        newRoot(t, q, x, ap);
}