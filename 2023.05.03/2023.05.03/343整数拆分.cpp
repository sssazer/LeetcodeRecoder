#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0); // dp[i]表示拆分i能够获得的最大乘积，最终dp[n]就是所求结果
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(max(dp[i], j * (i - j)), j * dp[i - j]);
            }
        }
        return dp[n];
    }
};

//int main() {
//
//    Solution s;
//    s.integerBreak(5);
//	return 0;
//}