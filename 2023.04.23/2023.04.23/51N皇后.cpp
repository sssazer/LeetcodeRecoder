#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    unordered_map<int, int> pos; // 分别记录每行的皇后放在什么位置, unordered_map<col, row>

    void traceback(int n, int curRow) { // curRow：本次要在第几行放皇后
        if (curRow >= n) {
            // 找到一种放法，根据pos来构造答案
            vector<string> oneRes(n, "");
            for (const pair<int, int> p : pos) {
                string temp(n, '.');
                temp[p.first] = 'Q';
                oneRes[p.second] = temp;
            }
            result.push_back(oneRes);
            return;
        }
        for (int i = 0; i < n; i++) { // 在本行中，将皇后分别放在每个位置
            bool canPut = true; // 表示该位置能否放皇后
            if (pos.find(i) != pos.end()) { // 如果这列已经有一个皇后，就不能再放皇后
                continue;
            }
            for (const pair<int, int> p : pos) { // 检查之前每一行中的皇后，看是否有皇后与当前位置在同一斜线上
                if (abs(i - p.first) == abs(curRow - p.second)) { // 如果有在同一斜线上，这个位置就不能再放皇后
                    canPut = false;
                    break;
                }
            }
            if (canPut) { // 如果这个位置能放皇后
                unordered_map<int, int>::iterator pit = pos.insert(make_pair(i, curRow)).first;
                traceback(n, curRow + 1);
                pos.erase(pit);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        traceback(n, 0);
        return result;
    }
};

//int main() {
//
//	return 0;
//}