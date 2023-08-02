#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j]表示word1[0:i]和word2[0:j]这两个字串的最短编辑距离
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        // 初始化dp数组
        for (int i = 0; i <= word1.size(); i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= word2.size(); i++) {
            dp[0][i] = i;
        }
        // 开始动规
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    // 执行替换操作，将两个不一样的字母替换成相同的
                    int substitude = dp[i - 1][j - 1] + 1;
                    // 删除word1中的该字符
                    int del_word1 = dp[i - 1][j] + 1;
                    // 删除word2中的该字符
                    int del_word2 = dp[i][j - 1] + 1;
                    dp[i][j] = min(min(del_word1, del_word2), substitude);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

//int main() {
//
//	return 0;
//}