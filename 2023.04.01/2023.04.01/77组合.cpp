#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    vector<vector<int>> result;
    int N, K;

    void traceback(int num, vector<int> nums) {
        nums.push_back(num);
        if (nums.size() == K) {
            result.push_back(nums);
            return;
        }
        for (int i = num + 1; i <= N; i++) {
            traceback(i, vector<int>(nums));
        }
    }

    vector<vector<int>> combine(int n, int k) {
        N = n, K = k;
        for (int i = 1; i <= n; i++) {
            traceback(i, {});
        }
        return this->result;
    }
};

//int main() {
//
//    Solution s;
//    s.combine(4, 2);
//
//    return 0;
//}