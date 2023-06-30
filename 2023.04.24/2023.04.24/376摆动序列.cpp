#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }
        int i;
        bool minus;
        for (i = 1; i < nums.size(); i++) {
            if (!(nums[i] == nums[i - 1])) {
                minus = (nums[i] - nums[i - 1]) > 0;
                break;
            }
        }
        int left = i;
        if (i == nums.size()) {
            return 1;
        }
        int maxLen = 2;
        for (i++; i < nums.size(); i++) {
            if (nums[i] == nums[left]) {
                continue;
            }
            bool temp = (nums[i] - nums[left]) > 0;
            if (temp != minus) {
                maxLen++;
                minus = temp;
                left = i;
            }
        }
        return maxLen;
    }
};

int main() {

    Solution s;
    vector<int> nums = { 33,53,12,64,50,41,45,21,97,35,47,92,39,0,93,55,40,46,69,42,6,95,51,68,72,9,32,84,34,64,6,2,26,98,3,43,30,60,3,68,82,9,97,19,27,98,99,4,30,96,37,9,78,43,64,4,65,30,84,90,87,64,18,50,60,1,40,32,48,50,76,100,57,29,63,53,46,57,93,98,42,80,82,9,41,55,69,84,82,79,30,79,18,97,67,23,52,38,74,15 };
    cout << s.wiggleMaxLength(nums);


	return 0;
}