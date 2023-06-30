#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 == 1) {
            return false;
        }
        vector<int> dp(sum / 2 + 1, 0);
        for (int i = 1; i <= sum / 2; i++) {
            if (i >= nums[0]) {
                dp[i] = nums[0];
            }
        }
        for (int num : dp) {
            cout << num << "  ";
        }
        cout << endl;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = sum / 2; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
            for (int num : dp) {
                cout << num << "  ";
            }
            cout << endl;
        }
        return dp[sum / 2] == sum / 2;
    }
};

int main() {

    Solution s;
    vector<int> nums = {1, 2, 5};
    s.canPartition(nums);

	return 0;
}