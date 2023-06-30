#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:

    vector<int> candidates;
    vector<vector<int>> result;
    vector<int> current;

    void traceback(int startIndex, int target, int sum) {
        if (sum == target) {
            result.push_back(current);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            if (i == startIndex || candidates[i] != candidates[i - 1]) {
                current.push_back(candidates[i]);
                traceback(i + 1, target, sum + candidates[i]);
                current.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        traceback(0, target, 0);
        return result;
    }
};

int main() {

	return 0;
}