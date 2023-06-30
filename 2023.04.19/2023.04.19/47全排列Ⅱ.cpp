#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:

    vector<vector<int>> result;
    vector<int> path;
    void traceback(vector<int>& nums, unordered_set<int> &path_used) { // 路径中使用过的元素的下表
        if (path.size() >= nums.size()) {
            result.push_back(path);
            return;
        }
        unordered_set<int> layer_used; // 同一层中使用过的元素的值
        for (int i = 0; i < nums.size(); i++) {
            if (path_used.find(i) == path_used.end() && layer_used.find(nums[i]) == layer_used.end()) {
                path.push_back(nums[i]);
                layer_used.insert(nums[i]);
                unordered_set<int>::iterator usit = path_used.insert(i).first;
                traceback(nums, path_used);
                path.pop_back();
                path_used.erase(usit);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_set<int> set = {};
        traceback(nums, set);
        return result;
    }
};

int main() {

	return 0;
}