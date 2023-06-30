#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // 解题思路：理想状态下我们有穿越回去的能力
    // 每天都买股票，如果第二天价格更高就直接卖掉然后继续买，
    // 如果第二天价格更低就前一天卖掉（买的那天卖掉）
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int curPrice = prices[0]; // 现在手里有的股票的买入价格
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > curPrice) { // 股票涨了
                profit += (prices[i] - curPrice);
            }
            curPrice = prices[i];
        }
        return profit;
    }
};

//int main() {
//
//	return 0;
//}