#include<iostream>
#include<vector>

using namespace std;

class Solution { // 数学题，看不懂证明
public:
    int tilingRectangle(int n, int m) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= min(n, m); i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= m; k++) {
                    if (i == 1) {
                        dp[j][k] = j * k;
                    }
                    else if (j >= i && k >= i) {
                        dp[j][k] = min(dp[j][k], dp[j - i][k - i] + dp[i][k - i] + dp[j - i][i] + 1);
                    }
                }
            }
        }
        return dp[n][m];
    }
};

//int main() {
//
//	return 0;
//}