#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> R; // R.key表示行数据，R.value表示该行出现的次数
        for (vector<int>& v : grid) {
            string tempR;
            for (int num : v) {
                tempR.append(to_string(num));
                tempR.push_back('.');
            }
            R[tempR]++;
        }
        unordered_map<string, int> C; // R.key表示行数据，R.value表示该行出现的次数
        for (int j = 0; j < grid.size(); j++) {
            string tempC;
            for (int i = 0; i < grid[0].size(); i++) {
                tempC.append(to_string(grid[i][j]));
                tempC.push_back('.');
            }
            C[tempC]++;
        }
        int res = 0;
        for (const pair<string, int>& Rpair : R) {
            unordered_map<string, int>::iterator mit = C.find(Rpair.first);
            if (mit != C.end()) {
                res += Rpair.second * mit->second;
            }
        }
        return res;
    }
};

int main() {

    Solution s;
    vector<vector<int>> grid = {{250, 78, 253}, {334, 252, 253}, {250, 253, 253}};
    cout << s.equalPairs(grid);

	return 0;
}