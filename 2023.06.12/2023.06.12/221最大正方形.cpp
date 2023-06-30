#include<iostream>
#include<vector>

using namespace std;

class Solution1 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0)); // dp[i][j]表示以matrix[i][j]为右下角的最大正方形的边长
        int maxLen = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                    maxLen = max(maxLen, dp[i][j]);
                    continue;
                }
                if (matrix[i][j] == '0') {
                    continue;
                }
                if (matrix[i - 1][j - 1] == '0') {
                    dp[i][j] = 1;
                    maxLen = max(maxLen, dp[i][j]);
                    continue;
                }
                dp[i][j] = 1;
                for (int k = 1; k <= dp[i - 1][j - 1]; k++) {
                    if (matrix[i - k][j] == '1' && matrix[i][j - k] == '1') {
                        dp[i][j]++;
                    }
                    else {
                        break;
                    }
                }
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        return maxLen * maxLen;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int maxLen = 0;
        for (int i = 0; i < matrix[0].size(); i++) {
            dp[0][i] = matrix[0][i] - '0';
            maxLen = max(maxLen, dp[0][i]);
        }
        for (int i = 1; i < matrix.size(); i++) {
            dp[i][0] = matrix[i][0] - '0';
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '0') {
                    continue;
                }
                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        return maxLen * maxLen;
    
    }
};

//int main() {
//
//	return 0;
//}