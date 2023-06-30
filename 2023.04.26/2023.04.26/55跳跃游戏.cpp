#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        int maxPos = 0;
        for (int i = 0; i <= maxPos; i++) {
            maxPos = max(i + nums[i], maxPos);
            if (maxPos >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
	return 0;
}
