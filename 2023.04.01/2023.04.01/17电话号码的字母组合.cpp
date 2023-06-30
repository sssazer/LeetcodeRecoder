#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> mapTab = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<int> pushOrder;
    vector<string> result;
    string current;

    void traceback(int index, int n) {
        if (current.size() == n) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < mapTab[pushOrder[index]].size(); i++) {
            current.push_back(mapTab[pushOrder[index]][i]);
            traceback(index + 1, n);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        pushOrder = vector<int>(digits.size(), 0);
        for (int i = 0; i < digits.size(); i++) {
            pushOrder[i] = digits[i] - '0';
        }
        traceback(0, digits.size());
        return result;
    }
};

int main() {



	return 0;
}