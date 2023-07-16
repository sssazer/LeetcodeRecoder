#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> sizeOfTree; // 存放以该结点为root时的子树大小
    vector<int> result; // 存放各个结点与所有其他结点之间的距离之和
    vector<bool> visited; // 用于深度优先遍历
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        result = vector<int>(n, 0);
        vector<vector<int>> matric(n, vector<int>()); // 用邻接表存储树
        sizeOfTree = vector<int>(n, 1);
        for (vector<int>& v : edges) { // 初始化邻接表
            matric[v[0]].push_back(v[1]);
            matric[v[1]].push_back(v[0]);
        }
        visited = vector<bool>(n, false); // 用于深度优先遍历
        DFS(matric, 0, 1); // 从0开始深度优先遍历
        // result[i] = result[x] + n - 2 * sizeOfTree[i] 其中x是y的父节点
        visited = vector<bool>(n, false);
        DFSforRes(matric, 0, n);
        return result;
    }

    void DFSforRes(vector<vector<int>>& matric, int x, int total) {
        if (visited[x]) {
            return;
        }
        visited[x] = true;
        for (int next : matric[x]) {
            if (!visited[next]) {
                result[next] = result[x] + total - 2 * sizeOfTree[next];
                DFSforRes(matric, next, total);
            }
        }
    }

    int DFS(vector<vector<int>>& matric, int x, int depth) { // 从x结点开始深度优先遍历, 返回以x为根结点的子树的结点数
        if (visited[x]) {
            return 0;
        }
        visited[x] = true;
        for (int next : matric[x]) {
            if (!visited[next]) {
                sizeOfTree[x] += DFS(matric, next, depth + 1);
                result[0] += depth;
            }
        }
        return sizeOfTree[x];
    }
};

int main() {

    Solution s;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {2, 3},
        {2, 4},
        {2, 5}
    };
    vector<vector<int>> edges1 = { {1, 0} };
    vector<int> res = s.sumOfDistancesInTree(2, edges1);
    for (int i : res) {
        cout << i << " ";
    }
	return 0;
}