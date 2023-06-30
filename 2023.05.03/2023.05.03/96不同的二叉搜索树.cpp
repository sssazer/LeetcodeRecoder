#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0); // dp[i]表示由i个不同节点组成的二叉搜索树种数
        dp[1] = 1, dp[0] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
};

int main() {

	return 0;
}