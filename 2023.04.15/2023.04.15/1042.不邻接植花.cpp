#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

class Solution1 { // 邻接矩阵超时
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> metric(n + 1, vector<int>(n + 1, 0)); // 邻接矩阵
        vector<int> result(n, 0);
        result[0] = 1; // 给1号花园种1号花
        // 构造邻接矩阵
        for (auto v : paths) {
            metric[v[0]][v[1]] = metric[v[1]][v[0]] = 1;
        }
        // 广度优先搜索
        queue<int> que; // 广度优先搜索中用到的队列
        que.push(1);
        while (que.size()) {
            int i = que.front();
            que.pop();
            // 遍历到谁就给谁种花，种花前要先看看它所连接的所有花园中哪些种过花了，把这些花种类排除掉
            vector<int> choice{0, 1, 2, 3, 4};
            for (int j = 1; j <= n; j++) { 
                if (!metric[i][j]) { // 如果没有路就直接跳过
                    continue;
                }
                else {
                    if (!result[j - 1]) { // 如果未被访问过
                        que.push(j);
                        continue;
                    }
                    else {
                        choice[result[j - 1]] = 0;
                    }
                }
            }
            for (int k = 1; k <= 4; k++) { // 挑一个不冲突的花种上
                if (choice[k]) {
                    result[i - 1] = k;
                }
            }

            if (que.size() == 0) { // 由于图可能不是联通的，所以要手动添加一些离散的点
                for (int k = 0; k < n; k++) {
                    if (result[k] == 0) {
                        que.push(k + 1);
                        break;
                    }
                }
            }
        } // 广度优先搜索
        return result;
    }
};

class Solution2 { // 邻接表 超时
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n + 1); // 邻接表
        vector<int> result(n, 0);
        // 构造邻接表
        for (auto &v : paths) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        // 广度优先搜索
        queue<int> que; // 广度优先搜索中用到的队列
        que.push(1);
        while (que.size()) {
            int i = que.front();
            que.pop();
            // 遍历到谁就给谁种花，种花前要先看看它所连接的所有花园中哪些种过花了，把这些花种类排除掉
            vector<int> choice{0, 1, 2, 3, 4};
            for (auto &j : adj[i]) { 
				if (!result[j - 1]) { // 如果未被访问过
					que.push(j);
					continue;
				}
				else {
					choice[result[j - 1]] = 0;
				}
            }
            for (int k = 1; k <= 4; k++) { // 挑一个不冲突的花种上
                if (choice[k]) {
                    result[i - 1] = k;
                    break;
                }
            }
            if (que.size() == 0) { // 由于图可能不是联通的，所以要手动添加一些离散的点
                for (int k = 0; k < n; k++) {
                    if (result[k] == 0) {
                        que.push(k + 1);
                        break;
                    }
                }
            }
        } // 广度优先搜索
        return result;
    }

};

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n); // 邻接表
        vector<int> result(n, 0);
        // 构造邻接表
        for (auto& v : paths) {
            adj[v[0] - 1].push_back(v[1] - 1);
            adj[v[1] - 1].push_back(v[0] - 1);
        }
        int i = 0;
        for (auto v : adj) { // v是当前要种花的花园编号
			// 遍历到谁就给谁种花，种花前要先看看它所连接的所有花园中哪些种过花了，把这些花种类排除掉
			vector<int> choice{ 0, 1, 2, 3, 4 };
			for (auto& j : v) { // j是邻接的花园编号
                if (result[j]) {
                    choice[result[j]] = 0;
                }
			}
			for (int k = 1; k <= 4; k++) { // 挑一个不冲突的花种上
				if (choice[k]) {
					result[i++] = k;
					break;
				}
			}
        }
        return result;
    }
};

int main(){

    Solution s;
    vector<vector<int>> paths = { {1,2} };
    s.gardenNoAdj(10, paths);
	return 0;

}