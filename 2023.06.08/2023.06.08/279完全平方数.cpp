#include<iostream>
#include<vector>

using namespace std;

class Solution { // 完全背包
public:
    int numSquares(int n) {
        vector<int> perfectSquares;
        for (int i = 1; ;i++) {
            if (i * i <= n)
                perfectSquares.push_back(i * i);
            else
                break;
        }
        vector<int> dp(n + 1, 10001); // dp[j]表示和为j的完全平方数的最小数量
        dp[0] = 0;
        for (int i = 0; i < perfectSquares.size(); i++) {
            for (int j = perfectSquares[i]; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - perfectSquares[i]] + 1);
            }
        }
        return dp[n];
    }
};

//int main() {
//    Solution s;
//    s.numSquares(12);
//	return 0;
//}