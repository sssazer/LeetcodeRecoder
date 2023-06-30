#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> dp;
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        dp = vector<int>(n + 1);
        dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

//int main() {
//
//	return 0;
//}