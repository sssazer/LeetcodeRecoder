#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.begin(), cost.end()); // dp[i]表示爬到i阶楼梯总共所需最小花费，再加上从i阶楼梯出发需要的总花费
        dp.push_back(0);
        for (int i = 2; i <= cost.size(); i++) {
            dp[i] += min(dp[i - 1], dp[i - 2]);
        }
        return  dp[cost.size()];
    }
};

int main() {

	return 0;
}