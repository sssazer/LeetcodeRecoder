#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 对数组是负数的情况单独处理，同时处理掉数组开头的负数
        int maxSum = 0;
        int sum = -1 * INT_MAX;
        int i;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                sum = 0;
                break;
            }
            sum = max(sum, nums[i]);
        }
        if (sum <= 0) {
            return sum;
        }
        for (; i < nums.size(); i++) {
            if (sum == 0 && nums[i] < 0) {
                continue;
            }
            if (nums[i] > 0) {
                sum += nums[i];
                maxSum = max(maxSum, sum);
            }
            else {
                sum = (sum + nums[i]) > 0 ? sum + nums[i] : 0;
            }
        }
        return maxSum;
    }
};

int main() {

	return 0;
}