//
// Created by atomfjf on 2022/7/20.
//

#ifndef DATA_STRUCTURE_AMGRAPH_H
#define DATA_STRUCTURE_AMGRAPH_H

#pragma once

#include <iostream>

using namespace std;
#define MaxInt 32767
#define MVNum 100

class AMGraph {
private:
    char vexs[MVNum];//顶点表
    int arcs[MVNum][MVNum];//邻接矩阵
    int _vexnum, _arcnum;//顶点数和边数

public:
    AMGraph() {}//默认构造
    AMGraph(int vexnum, int arcnum);//构造函数
    int LocateVex(char v);//返回节点v在所有节点中的位置，以此推断邻接表的位置
    void CreateAMGraph();//创建图
    void ShowAMGraph();//显示图
    void DFS(int v,int* visited)//深度优先遍历
};

AMGraph::AMGraph(int vexnum, int arcnum) {
    this->_vexnum = vexnum;
    this->_arcnum = arcnum;
    //输入节点信息
    cout << "请输入节点信息：" << endl;
    for (int i = 0; i < this->_vexnum; i++) {
        cout << "请输入第" << i + 1 << "个节点: ";
        cin >> this->vexs[i];
    }
    cout << "节点表初始化完毕" << endl;
    //给邻接矩阵赋值
    for (int i = 0; i < this->_vexnum; i++) {
        for (int j = 0; j < this->_vexnum; j++) {
            this->arcs[i][j] = MaxInt;
        }
    }
    cout << "邻接矩阵初始化完毕" << endl;
    system("pause");
    system("cls");
}

int AMGraph::LocateVex(char v) {
    for (int i = 0; i < this->_vexnum; i++) {
        if (this->vexs[i] == v) {
            return i;
        }
    }
    cout << "节点不存在" << endl;
    return -1;
}

void AMGraph::CreateAMGraph() {
    cout << "请输入邻接矩阵信息（v1,v2,w）用空格分割： " << endl;
    for (int i = 0; i < this->_arcnum; i++) {
        char v1, v2;
        int w;
        cout << "请输入第" << i + 1 << "条边的信息： ";
        cin >> v1 >> v2 >> w;

        int i1 = this->LocateVex(v1);
        int i2 = this->LocateVex(v2);
        this->arcs[i1][i2] = w;
        this->arcs[i2][i1] = w;//无向图邻接矩阵对称
    }
    cout << "邻接矩阵构建完毕" << endl;
    this->ShowAMGraph();
    system("pause");
    system("cls");
}

void AMGraph::ShowAMGraph() {
    cout << "\t";
    for (int k = 0; k < this->_vexnum; k++) {
        cout << this->vexs[k] << "\t";
    }
    cout << endl;

    for (int i = 0; i < this->_vexnum; i++) {
        cout << this->vexs[i] << "\t";
        for (int j = 0; j < this->_vexnum; j++) {
            cout << this->arcs[i][j] << " ";
        }
        cout << endl;
    }
}

void AMGraph::DFS(int v,int* visited){
    visited[v] = 1;
    cout << this->vexs[v] << " ";
    for (int i = 0; i < this->_vexnum; i++) {
        if (this->arcs[v][i] != MaxInt && visited[i] == 0) {
            DFS(i,visited);
        }
    }
}

#endif //DATA_STRUCTURE_AMGRAPH_H
