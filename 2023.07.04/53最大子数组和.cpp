#include<iostream>
#include<vector>

using namespace std;

class Solution {  // 贪心
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int maxSum = nums[0];
        for(int i : nums){
            curSum += i;
            maxSum = max(curSum, maxSum);
            if(curSum < 0){
                curSum = 0;
            }
        }
        return maxSum;
    }
};

class Solution { // 动态规划
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0); // dp[i]表示以nums[i]结尾的最大连续子数组的最大和
        dp[0] = nums[0];
        int maxLen = nums[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};

int main(){

    return 0;
}