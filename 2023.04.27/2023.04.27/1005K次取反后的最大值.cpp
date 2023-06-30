#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution1 {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            if (k & 1) {
                return -1 * nums[0];
            }
            return nums[0];
        }
        sort(nums.begin(), nums.end());
        int i;
        for (i = 0; i < k && i < nums.size(); i++) {
            if (nums[i] < 0) {
                nums[i] *= -1;
            }
            else {
                break;
            }
        }
        if (i < k && (k - i) & 1) {
            sort(nums.begin(), nums.end());
            nums[0] *= -1;
        }
		int sum = 0;
		for (auto& i : nums) {
			sum += i;
		}
		return sum;
    }
};

class Solution {
public:
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                k--;
            }
        }
        if (k & 1) nums[nums.size() - 1] *= -1;
        int sum = 0;
        for (auto& i : nums) {
            sum += i;
        }
        return sum;
    }
};

//int main() {
//
//    Solution s;
//    vector<int> nums = { -4,-2,-3 };
//    s.largestSumAfterKNegations(nums, 4);
//
//	return 0;
//}