#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int>> result;
    vector<int> path;
    vector<int> nums;

    void traceback(int num) {
        if (num >= nums.size()) {
            return;
        }
        for (int i = num; i < nums.size(); i++) {
            if (i == num || nums[i] != nums[i - 1]) {
                path.push_back(nums[i]);
                result.push_back(path);
                traceback(i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        result.push_back({});
        traceback(0);
        return result;
    }
};

//int main() {
//
//	return 0;
//}