#include<iostream>
#include<vector>

using namespace std;

class Solution { // 前缀和
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<int> sums(nums.size() + 1, 0); // 用于存储nums的前缀和，其中sums[i]是nums[0]~nums[i - 1]的和，sums[0] = 0
        sums[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        // 对于任意一个子数组nums[i:j]，他的和为sums[j + 1] - sums[i]
        int minLen = nums.size() + 1;
        // 枚举i~j，找到最小的和至少为k的子数组
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (sums[j + 1] - sums[i] >= k) {
                    minLen = min(minLen, j - i + 1);
                }
            }
        }
        if (minLen == nums.size() + 1) {
            return -1;
        }
        return minLen;
    }
};

//int main() {
//
//	return 0;
//}