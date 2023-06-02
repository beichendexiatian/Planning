/*************************************************************************
	> File Name: Graph.h
	> Author: 
	> Mail: 
	> Created Time: 2023年06月01日 星期四 15时50分23秒
 ************************************************************************/
// 图的表达

#ifndef _GRAPH_H
#define _GRAPH_H

#include <unordered_set>
#include <unordered_map>
#include "Node.h"
#include "Edge.h"

struct Graph {
    std::unordered_map<int, Node *> nodes; // 图拥有的节点集 <节点号, 节点指针>
    std::unordered_set<Edge *> edges;      // 图拥有的边集
};

#endif
