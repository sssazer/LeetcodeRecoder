#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // 分别考虑一遍左边和右边，不能同时考虑一个孩子的左边和右边，不然两边无限传递和累加
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) {
            return 1;
        }
        vector<int> distribution(ratings.size(), 0);
        int leftChild = ratings.size(); // 记录还有几个孩子没得到糖果
        for (int i = 0; i < ratings.size(); i++) { // 找到评分中的所有极小值，并分给他们一个糖果
            // 处理端点值
            if (i == 0) {
                if (ratings[1] >= ratings[0]) {
                    distribution[0] = 1;
                    leftChild--;
                }
                continue;
            }
            else if (i == ratings.size() - 1) {
                if (ratings[i] <= ratings[i - 1]) {
                    distribution[i] = 1;
                    leftChild--;
                }
                continue;
            }
            // 处理中间值
            if ((ratings[i + 1] > ratings[i] && ratings[i - 1] > ratings[i]) //  \/情况
                || (ratings[i + 1] == ratings[i] && ratings[i - 1] > ratings[i]) //  \__情况 
                || (ratings[i + 1] > ratings[i] && ratings[i - 1] == ratings[i])) { // --/情况 
                distribution[i] = 1;
                leftChild--;
            }
            else if (ratings[i + 1] == ratings[i] && ratings[i - 1] == ratings[i]) { // ---情况
                distribution[i] = 1;
                leftChild--;
            }
        }
        
        // 先只考虑每个孩子的左边
        for (int i = 1; i < ratings.size(); i++) {
            if (distribution[i] == 1) {
                continue;
            }
            if (ratings[i] > ratings[i - 1]) {
                distribution[i] = distribution[i - 1] + 1;
            }
        }
        // 再只考虑每个孩子的右边
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (distribution[i] == 1) {
                continue;
            }
            if (ratings[i] > ratings[i + 1]) {
                distribution[i] = max(distribution[i], distribution[i + 1] + 1);
            }
        }
        int sumCandy = 0;
        for (int i : distribution) {
            sumCandy += i;
        }
        return sumCandy;
    }
};

int main() {

    Solution s;
    vector<int> ratings = { 0 };
    cout << s.candy(ratings);
    
	return 0;
}