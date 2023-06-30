#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1, count1 = 0;
        int candidate2, count2 = 0;
        for (auto& i : nums) {
            if (count1 == 0 || count2 == 0) { // 如果有一个位置没有候选人
                if (count1 == 0 && count2 == 0) { // 两个位置都没有候选人，直接上一个
                    candidate1 = i;
                    count1 = 1;
                    continue;
                }
                else if (count1 == 0) { // 如果第一个候选人空着
                    if (i == candidate2) {
                        count2++;
                        continue;
                    }
                    else {
                        candidate1 = i;
                        count1 = 1;
                        continue;
                    }
                }
                else { // 如果第二个候选人空着
                    if (i == candidate1) {
                        count1++;
                        continue;
                    }
                    else {
                        candidate2 = i;
                        count2 = 1;
                        continue;
                    }
                }
            }
            else { // 如果都有候选人
                if (i != candidate1 && i != candidate2) {
                    count1--;
                    count2--;
                }
                else if (i == candidate1) {
                    count1++;
                }
                else {
                    count2++;
                }
            }
        }
        vector<int> result;
        count1 = count2 = 0;
        for (auto& i : nums) {
            if (i == candidate1) {
                count1++;
            }
            else if (i == candidate2) {
                count2++;
            }
        }
        if (count1 > nums.size() / 3) {
            result.push_back(candidate1);
        }
        if (count2 > nums.size() / 3) {
            result.push_back(candidate2);
        }
        return result;
    }
};

int main() {

    Solution s;
    vector<int> nums = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,4,5,6,7,8,9 };
    s.majorityElement(nums);
	return 0;
}