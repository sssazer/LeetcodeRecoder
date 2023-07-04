#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxLen = 1, curLen = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]){
                curLen++;
                maxLen = max(maxLen, curLen);
            }
            else{
                curLen = 1;
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0); // dp[i]表示以nums[i]为结尾的最长连续递增序列长度
        dp[0] = 1;
        int maxLen = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]){
                dp[i] = dp[i - 1] + 1;
                maxLen = max(dp[i], maxLen);
            }else{
                dp[i] = 1;
            }
        }
        return maxLen;
    }
};

int main(){

    return 0;
}