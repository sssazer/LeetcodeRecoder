#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLen = 0;
        unordered_map<int, int> dp; // <子串长度，该长度所有子串中末尾元素最小的那个末尾元素的值>
        dp[0] = -100001;
        for(int i = 0; i < nums.size(); i++){
            for(int k = maxLen; k >= 0; k--){
                if(nums[i] > dp[k]){
                    if(k + 1 > maxLen){
                        maxLen++;
                        dp[k + 1] = nums[i];
                    }else{
                        if(nums[i] < dp[k + 1]){
                            dp[k + 1] = nums[i];
                        }
                    }
                    break;
                }
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1); // dp[i]表示以nums[i]为末尾的最长递增子序列的长度
        dp[0] = 1;
        int maxLen = 1;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1); 
                } 
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};

int main(){
    return 0;
}