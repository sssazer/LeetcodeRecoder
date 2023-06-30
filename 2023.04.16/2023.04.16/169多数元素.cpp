#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
                continue;
            }
            if (nums[i] == candidate) {
                count++;
            }
            else {
                count--;
            }
        }
        return candidate;
    }
};

//int main() {
//
//
//
//	return 0;
//}