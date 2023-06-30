#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<int> nums;

    void traceback(int startIndex) {
        if (startIndex >= nums.size()) {
            return;
        }
        unordered_set<int> used;
        for (int i = startIndex; i < nums.size(); i++) {
            if (used.find(nums[i]) != used.end()) { // 如果这个元素在本层已经使用过，就不能再使用
                continue;
            }
            if (path.size() == 0 || nums[i] >= path[path.size() - 1]) {
                path.push_back(nums[i]);
                if (path.size() > 1) {
                    result.push_back(path);
                }
                used.insert(nums[i]);
                traceback(i + 1);
                path.pop_back();
            }
        }
        
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        this->nums = nums;
        traceback(0);
        return result;
        
    }
};

//int main() {
//
//	return 0;
//}