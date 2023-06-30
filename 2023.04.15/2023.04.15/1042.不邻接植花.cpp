#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

class Solution1 { // �ڽӾ���ʱ
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> metric(n + 1, vector<int>(n + 1, 0)); // �ڽӾ���
        vector<int> result(n, 0);
        result[0] = 1; // ��1�Ż�԰��1�Ż�
        // �����ڽӾ���
        for (auto v : paths) {
            metric[v[0]][v[1]] = metric[v[1]][v[0]] = 1;
        }
        // �����������
        queue<int> que; // ��������������õ��Ķ���
        que.push(1);
        while (que.size()) {
            int i = que.front();
            que.pop();
            // ������˭�͸�˭�ֻ����ֻ�ǰҪ�ȿ����������ӵ����л�԰����Щ�ֹ����ˣ�����Щ�������ų���
            vector<int> choice{0, 1, 2, 3, 4};
            for (int j = 1; j <= n; j++) { 
                if (!metric[i][j]) { // ���û��·��ֱ������
                    continue;
                }
                else {
                    if (!result[j - 1]) { // ���δ�����ʹ�
                        que.push(j);
                        continue;
                    }
                    else {
                        choice[result[j - 1]] = 0;
                    }
                }
            }
            for (int k = 1; k <= 4; k++) { // ��һ������ͻ�Ļ�����
                if (choice[k]) {
                    result[i - 1] = k;
                }
            }

            if (que.size() == 0) { // ����ͼ���ܲ�����ͨ�ģ�����Ҫ�ֶ����һЩ��ɢ�ĵ�
                for (int k = 0; k < n; k++) {
                    if (result[k] == 0) {
                        que.push(k + 1);
                        break;
                    }
                }
            }
        } // �����������
        return result;
    }
};

class Solution2 { // �ڽӱ� ��ʱ
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n + 1); // �ڽӱ�
        vector<int> result(n, 0);
        // �����ڽӱ�
        for (auto &v : paths) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        // �����������
        queue<int> que; // ��������������õ��Ķ���
        que.push(1);
        while (que.size()) {
            int i = que.front();
            que.pop();
            // ������˭�͸�˭�ֻ����ֻ�ǰҪ�ȿ����������ӵ����л�԰����Щ�ֹ����ˣ�����Щ�������ų���
            vector<int> choice{0, 1, 2, 3, 4};
            for (auto &j : adj[i]) { 
				if (!result[j - 1]) { // ���δ�����ʹ�
					que.push(j);
					continue;
				}
				else {
					choice[result[j - 1]] = 0;
				}
            }
            for (int k = 1; k <= 4; k++) { // ��һ������ͻ�Ļ�����
                if (choice[k]) {
                    result[i - 1] = k;
                    break;
                }
            }
            if (que.size() == 0) { // ����ͼ���ܲ�����ͨ�ģ�����Ҫ�ֶ����һЩ��ɢ�ĵ�
                for (int k = 0; k < n; k++) {
                    if (result[k] == 0) {
                        que.push(k + 1);
                        break;
                    }
                }
            }
        } // �����������
        return result;
    }

};

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n); // �ڽӱ�
        vector<int> result(n, 0);
        // �����ڽӱ�
        for (auto& v : paths) {
            adj[v[0] - 1].push_back(v[1] - 1);
            adj[v[1] - 1].push_back(v[0] - 1);
        }
        int i = 0;
        for (auto v : adj) { // v�ǵ�ǰҪ�ֻ��Ļ�԰���
			// ������˭�͸�˭�ֻ����ֻ�ǰҪ�ȿ����������ӵ����л�԰����Щ�ֹ����ˣ�����Щ�������ų���
			vector<int> choice{ 0, 1, 2, 3, 4 };
			for (auto& j : v) { // j���ڽӵĻ�԰���
                if (result[j]) {
                    choice[result[j]] = 0;
                }
			}
			for (int k = 1; k <= 4; k++) { // ��һ������ͻ�Ļ�����
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