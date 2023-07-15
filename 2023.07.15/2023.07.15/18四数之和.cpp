#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end(), less<int>());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) { // 避免出现重复四元组
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++) { 
                if (j > i + 1 && nums[j] == nums[j - 1]) { // 避免出现重复四元组
                    continue;
                }
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
					long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < nums.size() - 1 && nums[left] == nums[left + 1]) left++;
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        left++, right--;
                    }
                    else if (sum > target) {
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        right--;
                    }
                    else {
                        while (left < nums.size() - 1 && nums[left] == nums[left + 1]) left++;
                        left++;
                    }
                }
            }
        }
        return result;
    }
};

int main() {

	return 0;
}