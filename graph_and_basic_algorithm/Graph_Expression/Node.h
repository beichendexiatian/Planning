/*************************************************************************
	> File Name: Node.h
	> Author: 
	> Mail: 
	> Created Time: 2023年06月01日 星期四 15时36分09秒
 ************************************************************************/
// 图中的节点表达

#ifndef _NODE_H
#define _NODE_H
#include <vector>
#include <queue>
#include "Edge.h"

struct Node {
    int value; // 本节点的值 
    int in;    // 入度（指向我的边数）
    int out;   // 出度（我指向的边数）
    std::vector<Node *> nexts;  // 本节点发散出去的相邻节点
    std::vector<Edge *> edges;  // 本节点发散出去的边

    Node() {};
    Node(int value) : value(value) {}
};

#endif
