#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> count; // 对应位置的字符串包含的0和1的数量，比如counts[0][0]表示strs[0]包含的0的数量
        for (string& s : strs) {
            vector<int> temp = {0, 0};
            for (char c : s) {
                temp[c - '0']++;
            }
            count.push_back(temp);
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // dp[i][j]表示 最多有 i个0 和 j个1 的最大子集长度
        for (int i = 0; i < strs.size(); i++) { // 表示现在可以从strs[0]~strs[i]中任取字符串往背包里装
            for (int j = m; j >= count[i][0]; j--) { // 背包中能装0的数量至少要大于当前要装的i
                for (int k = n; k >= count[i][1]; k--) { // 背包中能装1的数量至少大于当前要装的i
                    dp[j][k] = max(dp[j][k], dp[j - count[i][0]][k - count[i][1]] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {

	return 0;
}