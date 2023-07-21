#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int minLen = 200000;
        int curSum = 0;
        while (right < nums.size()) {
            curSum += nums[right];
            while (left <= right && curSum >= k) {
                minLen = min(minLen, right - left + 1);
                curSum -= nums[left++];
            }
            right++;
        }
        if (minLen == 200000) {
            return -1;
        }
        return minLen;
    }
};

int main() {

	return 0;
}