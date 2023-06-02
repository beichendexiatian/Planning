/*************************************************************************
	> File Name: Edge.h
	> Author: 
	> Mail: 
	> Created Time: 2023年06月01日 星期四 15时39分29秒
 ************************************************************************/
// 图中的边的表示

#ifndef _EDGE_H
#define _EDGE_H
#include "Node.h"

struct Node;

struct Edge {
    int weight; // 边的权重
    Node *from; // 边的起始节点
    Node *to;   // 边的末端节点

    Edge() {};
    Edge(int weight, Node *from, Node *to) : weight(weight), from(from), to(to) {}; 
};

#endif
