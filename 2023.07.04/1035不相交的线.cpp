#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // dp[i][j]表示在nums1[0]~nums[i - 1]和nums2[0]~nums2[j - 1]中绘制的最大连线数
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        for(int i = 1; i <= nums1.size(); i++){
            for(int j = 1; j <= nums2.size(); j++){
                if(nums1[i - 1] == nums2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};

int main(){

    return 0;
}