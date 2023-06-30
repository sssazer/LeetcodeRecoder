#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    vector<vector<int>> result;
    vector<int> current;

    void traceback(int k, int n, int startNum, int sum) {
        if (sum == n) {
            result.push_back(current);
            return;
        }
        for (int i = startNum; i <= 9; i++) {
            current.push_back(i);
            traceback(k, n, i + 1, sum + i);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        // ÅĞ¶Ï±ß½çÌõ¼ş
        int sum = 0;
        for (int i = 1; i <= k; i++) {
            sum += i;
        }
        if (sum >= n) {
            if (sum > n) {
                return {};
            }
            else {
                vector<vector<int> > res(1, vector<int>(k, 0));
                for (int i = 0; i < k; i++) {
                    res[0][i] = i;
                }
                return res;
            }
        }
        traceback(k, n, 1, 0);
        return result;
    }
};

//int main() {
//
//    Solution s;
//    s.combinationSum3(9, 45);
//
//	return 0;
//}