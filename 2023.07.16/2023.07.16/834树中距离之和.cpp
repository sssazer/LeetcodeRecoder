#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> sizeOfTree; // ����Ըý��Ϊrootʱ��������С
    vector<int> result; // ��Ÿ�������������������֮��ľ���֮��
    vector<bool> visited; // ����������ȱ���
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        result = vector<int>(n, 0);
        vector<vector<int>> matric(n, vector<int>()); // ���ڽӱ�洢��
        sizeOfTree = vector<int>(n, 1);
        for (vector<int>& v : edges) { // ��ʼ���ڽӱ�
            matric[v[0]].push_back(v[1]);
            matric[v[1]].push_back(v[0]);
        }
        visited = vector<bool>(n, false); // ����������ȱ���
        DFS(matric, 0, 1); // ��0��ʼ������ȱ���
        // result[i] = result[x] + n - 2 * sizeOfTree[i] ����x��y�ĸ��ڵ�
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

    int DFS(vector<vector<int>>& matric, int x, int depth) { // ��x��㿪ʼ������ȱ���, ������xΪ�����������Ľ����
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