#include<iostream>
#include<vector>

using namespace std;

// 假设你正在爬楼梯，需要n阶才能到达楼顶
// 每次你可以爬1~m个台阶，你有多少种不同的方法可以爬到楼顶呢
// 此时相当于背包容量为n，物品为1~m，求用物品装满所有背包的排列数(元素顺序不同算不同排列)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= n; j++) {
            for (int i = 1; i <= 2; i++) {
                if (j >= i) {
                    dp[j] += dp[j - i];
                }
            }
        }
        return dp[n];
    }
};

int main() {

	return 0;
}