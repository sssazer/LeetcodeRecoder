#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void traceback(vector<int> &nums, unordered_set<int> &used) {
        if (path.size() >= nums.size()) { // ��·���ϵ�Ԫ�ظ����Ѿ��ﵽ������Ԫ�ظ���ʱ��˵�����Ѿ���һ��ȫ����
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) { // ��ÿһ�㶼Ҫѡ��һ����·����Ԫ�ض�����ͬ��Ԫ��
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
