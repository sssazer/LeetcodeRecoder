#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        // 先给每一行分别从大到小排序，再竖着遍历找到每次要加到答案上的值
        for (vector<int>& v : grid) {
            sort(v.begin(), v.end(), less<int>());
        }
        int result = 0;
        for (int i = 0; i < grid[0].size(); i++) {
            int max_val = 0;
            for (int j = 0; j < grid.size(); j++) {
                max_val = max(grid[j][i], max_val);
            }
            result += max_val;
        }
        return result;
    }
};

int main() {

	return 0;
}