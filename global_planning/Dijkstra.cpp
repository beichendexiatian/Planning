/*************************************************************************
	> File Name: Dijkstra.cpp
	> Author: YangJun
	> Mail: 2820031394@qq.com
	> Created Time: Sun 28 May 2023 04:06:04 PM CST
 ************************************************************************/
 // 用 Dijkstra 算法求解图中从一个点到另一个点的最短路径与距离
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;

struct Node;

// 边
struct Edge {
    int weight;
    Node* to;
};

// 节点
struct Node {
    Node() {}
    Node(int _node) : node(_node) {}
    int node;           // 节点号
    vector<Edge> edges; // 节点拥有的边
};

struct Result {
    stack<Node*> routine; // 出栈顺序就是从起始点到终点的路径
    int distance;         // 最优路径的距离
};

Node* getMinDistanceAndUnselect(unordered_map<Node*, int> &distanceMap, unordered_set<Node*> &selected) {
    Node* ret = nullptr;
    int distance = INT_MAX;
    for (auto x : distanceMap) {
        if (distance > x.second && selected.find(x.first) == selected.end()) {
            ret = x.first;
            distance = x.second;
        }
    }
    return ret;
}

// Dijkstra 算法求解图中一个点到另一个点的最短路径，及最短路径的距离
Result* dijkstra(Node *from, Node *to) {
    Result* result = new Result();
    unordered_map<Node*, int> distanceMap; // 用于记录 from 到图中每个点的距离，没有录入就是无穷大
    unordered_set<Node*> selected;        // 用于记录该节点是否已经收录到最优路径中
    unordered_map<Node*, Node*>  pre;    // 用于存储路径中每个节点的前节点

    distanceMap[from] = 0;
    Node* tmp = getMinDistanceAndUnselect(distanceMap, selected);
    while (tmp != nullptr) {
        selected.insert(tmp);  // 收录 tmp 到最优路径集
        // 更新相邻节点的距离和前点
        for (auto edge : tmp->edges) {
            if (edge.weight == INT_MAX) continue;
            if (distanceMap.find(edge.to) != distanceMap.end() && distanceMap[tmp] + edge.weight >= distanceMap[edge.to]) continue;
            distanceMap[edge.to] = distanceMap[tmp] + edge.weight;
            pre[edge.to] = tmp;
        }
        tmp = getMinDistanceAndUnselect(distanceMap, selected);
    }

    // 生成路径求解的结果
    if (distanceMap.find(to) == distanceMap.end()) return nullptr;
    result->distance = distanceMap[to];
    tmp = to;
    while (tmp != from) {
        result->routine.push(tmp);
        tmp = pre[tmp];
    }
    result->routine.push(tmp);

    return result;
}

int main() {
    Node* zero = new Node(0);
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);

    // 0-1
    Edge zero_one = { 10, one };
    zero->edges.push_back(zero_one);
    Edge one_zero = { 10, zero };
    one->edges.push_back(one_zero);

    // 0-2
    Edge zero_two = { 20, two };
    zero->edges.push_back(zero_two);
    Edge two_zero = { 20, zero };
    two->edges.push_back(two_zero);

    // 1-2
    Edge one_two = { 3, two };
    one->edges.push_back(one_two);
    Edge two_one = { 3, one };
    two->edges.push_back(two_one);

    // 1-3
    Edge one_three = { INT_MAX, three };
    one->edges.push_back(one_three);
    Edge three_one = { INT_MAX, one };
    three->edges.push_back(three_one);

    Result* result = dijkstra(zero, two);
    if (result != nullptr) {
        cout << "最短路径的距离是：" << result->distance << " ， 路径是：";
        while (result->routine.empty() == false) {
            Node* tmp = result->routine.top();
            result->routine.pop();
            cout << tmp->node << " ";
        }
    }
    else {
        cout << "不可到达" << endl;
    }

    return 0;
}

