#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // 只有一个和两个元素的情况单独处理
        if (nums.size() == 1) {
            return 1;
        }
        else if (nums.size() == 2) {
            if (nums[0] == nums[1]) {
                return 1;
            }
            else {
                return 2;
            }
        }
        int i;
        int preDiff;
        for (i = 1; i < nums.size(); i++) {
            preDiff = nums[i] - nums[i - 1];
            if (preDiff != 0) {
                break;
            }
        }
        if (i == nums.size()) {
            return 1;
        }
        int curDiff;
        int maxLen = 2;
        for (int i = 2; i < nums.size(); i++) {
            curDiff = nums[i] - nums[i - 1];
            if (curDiff == 0) {
                continue;
            }
            if ((preDiff < 0 && curDiff > 0) || (preDiff > 0 && curDiff < 0)) {
                preDiff = curDiff;
                maxLen++;
            }
        }
        return maxLen;
    }
};

//int main() {
//
//	return 0;
//}