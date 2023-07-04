#include<iostream>
#include<vector>

using namespace std;

class Solution { // 动态规划
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums2.size(), vector<int>(nums1.size(), 0)); // dp[i][j]表示两个数组中以nums2[i]和nums1[j]为结尾的最长公共子数组长度
        int maxLen = 0;
        for(int i = 0; i < nums2.size(); i++){
            for(int j = 0; j < nums1.size(); j++){
                if(nums2[i] == nums1[j]){
                    if(i > 0 && j > 0){
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }else{
                        dp[i][j] = 1;
                    }
                    maxLen = max(dp[i][j], maxLen);
                }
            }
        }
        return maxLen;
    }
};

class Solution { // 滚动数组
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dp(nums1.size() + 1, 0);
        int maxLen = 0;
        for(int i = 1; i <= nums2.size(); i++){
            for(int j = nums1.size(); j >= 1; j--){
                if(nums1[j - 1] == nums2[i - 1]){
                    dp[j] = dp[j - 1] + 1;
                }
                else{
                    dp[j] = 0;
                }
                maxLen = max(maxLen, dp[j]);
            }
        }
        return maxLen;
    }
};

int main(){

    return 0;
}