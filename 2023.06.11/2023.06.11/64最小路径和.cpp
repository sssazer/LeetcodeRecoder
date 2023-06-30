#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i == 0 && j == 0) { // ���Ͻǵ�Ԫ��û��·���Թ���
                    continue;
                }
                else if (i == 0) {
                    grid[i][j] = grid[i][j - 1] + grid[i][j]; // �ڵ�һ�е�����ֻ�д���߹�����·
                }
                else if (j == 0){ // �ڵ�һ�е�����ֻ�ܴ��������
                    grid[i][j] = grid[i - 1][j] + grid[i][j];
                }
                else {
                    grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
                }
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};

//int main() {
//
//	return 0;
//}