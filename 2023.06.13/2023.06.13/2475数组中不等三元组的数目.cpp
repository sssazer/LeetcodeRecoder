#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>

using namespace std;

class Solution1 { // 三重循环
public:
    int unequalTriplets(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == nums[i]) {
                    continue;
                }
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[k] != nums[j] && nums[k] != nums[i]) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

class Solution2 { // 暴力回溯，效率极差
public:
    int count;
    int unequalTriplets(vector<int>& nums) {
        count = 0;
        set<int> now;
        traceback(nums, now, 0);
        return count;
    }
    void traceback(vector<int>& nums, set<int>& now, int start) {
        for (int i = start; i < nums.size(); i++) {
            if (now.size() == 0) {
                set<int>::iterator sit = now.insert(nums[i]).first;
                traceback(nums, now, i + 1);
                now.erase(sit);
            }
            else if (now.size() == 1) {
                pair<set<int>::iterator, bool> p = now.insert(nums[i]);
                if (p.second) {
                    traceback(nums, now, i + 1);
                    now.erase(p.first);
                }
            }
            else {
                pair<set<int>::iterator, bool> p = now.insert(nums[i]);
                if (p.second) {
                    count++;
                    now.erase(p.first);
                }
            }
        }
        return;
    }
};

class Solution { // 哈希表
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> map; // key:nums中的元素，value：key在nums中出现的次数
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        int sum = nums.size();
        int left = 0, right = 0;
        int res = 0;
        for (const pair<int, int>& p : map) {
            if (left == 0) {
                left += p.second;
                continue;
            }
            res += left * p.second * (sum - left - p.second);
            left += p.second;
        }
        return res;
    }
};

//int main() {
//
//	return 0;
//}