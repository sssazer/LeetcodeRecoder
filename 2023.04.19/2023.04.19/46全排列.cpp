#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void traceback(vector<int> &nums, unordered_set<int> &used) {
        if (path.size() >= nums.size()) { // 当路径上的元素个数已经达到数组中元素个数时，说明这已经是一个全排列
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) { // 在每一层都要选择一个与路径上元素都不相同的元素
            if (used.find(nums[i]) == used.end()) {
                path.push_back(nums[i]);
                auto usit = used.insert(nums[i]).first;
                traceback(nums, used);
                path.pop_back();
                used.erase(usit);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> set = {};
        traceback(nums, set);
        return result;
    }
};

//int main() {
//    
//    Solution s;
//    vector<int> nums = { 1,2,3 };
//    s.permute(nums);
//	return 0;
//}
