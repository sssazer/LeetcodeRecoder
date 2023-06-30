#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> nums;
    void traceback(int n, vector<int> current) {
        for (; n < nums.size(); n++) {
            current.push_back(nums[n]);
            traceback(n + 1, current);
            result.push_back(current);
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        result.push_back({});
        this->nums = nums;
        traceback(0, {});
        return result;
    }
};

int main() {

	return 0;

}