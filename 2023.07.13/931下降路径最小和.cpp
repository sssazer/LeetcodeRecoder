#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // dp[i][j] 即下降到matrix[i][j]的下降路径最小和
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        dp[0] = matrix[0];
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                dp[i][j] = dp[i - 1][j];
                if(j > 0){
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);
                }
                if(j < matrix.size() - 1){
                    dp[i][j] = min(dp[i - 1][j + 1], dp[i][j]);
                }
                dp[i][j] += matrix[i][j];

            }
        }
        int res = dp.back()[0];
        for(int i = 1; i < dp.back().size(); i++){
            res = min(res, dp.back()[i]);
        }
        return res;
    }
};

int main(){

    return 0;
}