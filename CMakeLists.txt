cmake_minimum_required(VERSION 3.20)
project(Data_Structure)

set(CMAKE_CXX_STANDARD 11)

add_executable(cppstudy main.cpp 线性表/SeqList.h 线性表/LinkList.h 线性表/testlist.h 栈和队列/seqStack.h 栈和队列/linkStack.h 栈和队列/seqQueue.h 栈和队列/linkQueue.h 算法/bubbleSort.h 算法/selectionSort.h 算法/insertionSort.h 算法/shellSort.h 树和二叉树/binaryTree.h 树和二叉树/huffmanTree.h 图/AMGraph.h 图/ATGraph.h)


include_directories("D:\\CLionProjects\\Data_Structure\\栈和队列")


#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")