#include<iostream>
#include<vector>

using namespace std;

class Solution1 {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0); // dp[i]��ʾǰi�ŷ��������͵����Ǯ����
        dp[0] = 0, dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]); // ÿ�������޷����������͵��͵
        }
        return dp[nums.size()];
    }
};

class Solution { // ��������
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        int dpi_2 = nums[0], dpi_1 = max(nums[0], nums[1]);
        int dpi = 0;
        for (int i = 2; i < nums.size(); i++) {
            dpi = max(dpi_2 + nums[i], dpi_1);
            dpi_2 = dpi_1;
            dpi_1 = dpi;
        }
        return dpi;
    }
};

//int main() {
//
//	return 0;
//}