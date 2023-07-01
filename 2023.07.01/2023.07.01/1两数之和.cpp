#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> map; // key-数组元素值 value-该值在数组中出现的所有下标
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]].push_back(i);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target - nums[i]) {
                if (map[nums[i]].size() == 2) {
                    return {map[nums[i]][0], map[nums[i]][1]};
                }
            }
            else {
                if (map.find(target - nums[i]) != map.end()) {
                    return { i, map.find(target - nums[i])->second[0] };
                }
            }
        }
        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        map.insert(make_pair(nums[0], 0));
        for (int i = 1; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                return { map.find(target - nums[i])->second, i };
            }
            map.insert(make_pair(nums[i], i));
        }
        return {};
    }
};

//int main() {
//
//	return 0;
//}