#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // dp[i][j] 表示到达（i，j）共有多少条路，如果（i，j）上有障碍，那么dp[i][j] = 0;
        if (obstacleGrid[0][0]) {
            return 0;
        }
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        dp[0][0] = 1;
        for (int i = 1; i < dp[0].size(); i++) {
            if (obstacleGrid[0][i]) {
                dp[0][i] = 0;
                break;
            }
            dp[0][i] = 1;
        }
        for (int i = 1; i < dp.size(); i++) {
            if (obstacleGrid[i][0]) {
                dp[i][0] = 0;
                break;
            }
            dp[i][0] = 1;
        }
        for (int i = 1; i < obstacleGrid.size(); i++) {
		    for (int j = 1; j < obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		    }
        }
        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};

//int main() {
//
//	return 0;
//}