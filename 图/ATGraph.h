//
// Created by atomfjf on 2022/7/20.
//

#ifndef DATA_STRUCTURE_ATGRAPH_H
#define DATA_STRUCTURE_ATGRAPH_H

#pragma once

#include <iostream>

using namespace std;
#define MVNum 100

class ArcNode;

class VNode {
public:
    char data;//节点名称
    ArcNode *firstarc;//指向第一个边节点的指针
};

class ArcNode {
public:
    int adjvex;//该边所指向的邻接点的位置
    ArcNode *nextarc = NULL;//指向下一条边的指针
    int info;//和边相关的信息（权值）
};

class ATGraph {
private:
    VNode *vertex;//指向邻接表的头指针
    int _vexnum, _arcnum;//顶点数和边数
public:
    ATGraph(int vexnum, int arcnum);//构造函数
    int LocateVex(char v);//定位节点位置
    void CreateATGraph();//创建图
    void ShowATGraph();//显示图
    BFS(int v,int* visited);//广度优先遍历
};

ATGraph::ATGraph(int vexnum, int arcnum) {
    this->_vexnum = vexnum;
    this->_arcnum = arcnum;//创建邻接表
    this->vertex = new VNode[this->_vexnum];//给邻接表分配空间
    //输入节点信息
    cout << "请输入节点信息：" << endl;
    for (int i = 0; i < this->_vexnum; i++) {
        cout << "请输入第" << i + 1 << "个节点: " << endl;
        cin >> this->vertex[i].data;
        this->vertex[i].firstarc = NULL;
    }
    cout << "邻接表初始化完毕" << endl;
    system("pause");
    system("cls");
}

int ATGraph::LocateVex(char v) {
    for (int i = 0; i < this->_vexnum; i++) {
        if (this->vertex[i].data == v) {
            return i;
        }
    }
    cout << "节点不存在" << endl;
    return -1;
}

void ATGraph::CreateATGraph() {
    cout << "请输入邻接矩阵信息（v1，v2，w）用空格分割：" << endl;

    for (int j = 0; j < this->_arcnum; j++) {
        char v1, v2;
        int w;
        cout << "请输入第" << j + 1 << "条结点信息：" << endl;
        cin >> v1 >> v2 >> w;
        int a = this->LocateVex(v1);
        int b = this->LocateVex(v2);
        ArcNode *p1 = new ArcNode;
        p1->adjvex = b;//邻接点的序号为b
        p1->info = w;
        p1->nextarc = this->vertex[a].firstarc;
        this->vertex[a].firstarc = p1;
        //若为有向图，则下面可以省略
        ArcNode *p2 = new ArcNode;
        p2->adjvex = a;//邻接点的序号为a
        p2->info = w;
        p2->nextarc = this->vertex[b].firstarc;
        this->vertex[b].firstarc = p2;
    }
    cout << "邻接表创建完毕" << endl;
    this->ShowATGraph();
    system("pause");
    system("cls");
}

void ATGraph::ShowATGraph() {

    for (int i = 0; i < this->_vexnum; i++) {
        cout << this->vertex[i].data << "\t";
        ArcNode *p = this->vertex[i].firstarc;
        while (p != NULL) {
            cout << char('a' + p->adjvex) << " " << p->info << "\t";
            p = p->nextarc;
        }
        cout << endl;
    }
}

void ATGraph::BFS(int v,int* visited)//非递归
{
    cout<<this->vertex[v].data<<endl;//先打印第v个顶点
    visited[v]=1;//标记第v个顶点已访问
    SeqQueue<int> SQ;//创建队列
    SQ.EnQueue(v);//入队列
    while(!SQ.QueueEmpty()){
        int temp;
        SQ.DeQueue(temp);//出队列
        for(ArcNode* p=this->vertex[temp].firstarc;p!=NULL;p=p->nextarc){
            int i = p->adjvex;
            if(visited[i] == 0){
                cout << this->vertex[i].data << endl;
                visited[i]=1;
                SQ.EnQueue(i);
            }
        }
    }
}


#endif //DATA_STRUCTURE_ATGRAPH_H
