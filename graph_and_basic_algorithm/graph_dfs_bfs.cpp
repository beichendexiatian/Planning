/*************************************************************************
	> File Name: 图的深度与广度优先遍历.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年06月01日 星期四 16时44分12秒
 ************************************************************************/

#include <iostream>
#include <queue>
#include <stack>
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

int main() {
    Node *A = new Node(1);
    Node *B = new Node(2);
    Node *C = new Node(3);
    Node *D = new Node(4);
    Node *F = new Node(5);
    Node *E = new Node(6);
    A->nexts.push_back(B);;
    A->nexts.push_back(C);;
    B->nexts.push_back(C);
    C->nexts.push_back(D);
    B->nexts.push_back(F);
    C->nexts.push_back(E);

    std::cout << "广度优先遍历：" << std::endl;
    bfs(A);
    std::cout << std::endl;
    std::cout << "深度优先遍历：" << std::endl;
    dfs(A);

    return 0;
}
