/*************************************************************************
	> File Name: 图的深度与广度优先遍历.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年06月01日 星期四 16时44分12秒
 ************************************************************************/

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include "./Graph_Expression/Graph.h"

// 图的广度优先遍历
void bfs(Node* node) {
    if (!node) return;
    std::queue<Node*> nodeQueue;
    std::unordered_set<Node*> nodeSet; // 防止重复遍历同一个节点
    nodeQueue.push(node);
    nodeSet.insert(node);

    while (!nodeQueue.empty()) {
        Node* cur = nodeQueue.front();
        nodeQueue.pop();
        std::cout << cur->value << " ";
        for (Node *next : cur->nexts) {
            if (nodeSet.find(next) == nodeSet.end()) {
                nodeQueue.push(next);
                nodeSet.insert(next);
            }
        }
    }
}

// 图的深度优先遍历
void dfs(Node *node) {
    if (!node) return ;
    std::stack<Node *> nodeStack;
    std::unordered_set<Node*> nodeSet;  // 防止重复遍历同一个节点
    nodeStack.push(node);
    std::cout << node->value << " ";
    nodeSet.insert(node);
    while (!nodeStack.empty()) {
        Node* cur = nodeStack.top();
        nodeStack.pop();
        for (Node * next : cur->nexts) {
            if (nodeSet.find(next) == nodeSet.end()) {
                nodeStack.push(cur);
                nodeStack.push(next);
                std::cout << next->value << " ";
                nodeSet.insert(next);
                break;
            }
        }
    }
}

// 拓扑排序（解决有向无环图的拓扑排序）
std::vector<Node *> sortTopology(const Graph &graph) {
    std::vector<Node *> result;
    std::queue<Node *> zeroInQueue;    // 入度为 0 的节点
    std::unordered_map<Node *, int> inMap; // 记录每个节点的入度
    for (auto tmp : graph.nodes) {
        inMap[tmp.second] = tmp.second->in;
        if (tmp.second->in == 0) {
            zeroInQueue.push(tmp.second);
        }
    }

    while (!zeroInQueue.empty()) {
        Node *tmp = zeroInQueue.front();
        zeroInQueue.pop();
        result.push_back(tmp);
        // 将 tmp 指向的节点的入度都减1
        for (Node *next : tmp->nexts) {
            inMap[next] -= 1;
            if (inMap[next] == 0) {
                zeroInQueue.push(next);
            }
        }
    }
    return result;
}

int main() {
    Node *A = new Node(1);
    Node *B = new Node(2);
    Node *C = new Node(3);
    Node *D = new Node(4);
    Node *F = new Node(5);
    Node *E = new Node(6);
    A->in = 0;
    A->nexts.push_back(B);
    B->in = 1;
    A->nexts.push_back(C);
    B->nexts.push_back(C);
    C->in = 2;
    C->nexts.push_back(D);
    D->in = 1;
    B->nexts.push_back(F);
    F->in = 1;
    C->nexts.push_back(E);
    E->in = 1;

    std::cout << "广度优先遍历：" << std::endl;
    bfs(A);
    std::cout << std::endl;
    std::cout << "深度优先遍历：" << std::endl;
    dfs(A);

    Graph graph;
    graph.nodes[A->value] = A;
    graph.nodes[B->value] = B;
    graph.nodes[C->value] = C;
    graph.nodes[D->value] = D;
    graph.nodes[E->value] = E;
    graph.nodes[F->value] = F;
    std::vector<Node*> result = sortTopology(graph);
    std::cout << "拓扑排序结果：" << std::endl;
    for (Node* r : result) {
        std::cout << r->value << " ";
    }

    return 0;
}
