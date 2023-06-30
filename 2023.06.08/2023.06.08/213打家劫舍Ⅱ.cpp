#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        if (nums.size() == 3) {
            return max(max(nums[0], nums[1]), nums[2]);
        }
        // 考虑偷第一家不偷最后一家
        int dpi_2 = nums[0], dpi_1 = max(nums[1], nums[0]);
        int dp1 = 0;
        for (int i = 2; i < nums.size() - 1; i++) {
            dp1 = max(dpi_2 + nums[i], dpi_1);
            dpi_2 = dpi_1;
            dpi_1 = dp1;
        }
        // 考虑偷最后一家不偷第一家
        dpi_2 = nums[1], dpi_1 = max(nums[1], nums[2]);
        int dp2 = 0;
        for (int i = 3; i < nums.size(); i++) {
            dp2 = max(dpi_2 + nums[i], dpi_1);
            dpi_2 = dpi_1;
            dpi_1 = dp2;
        }
        return max(dp1, dp2);
    }
};

//int main() {
//
//	return 0;
//}