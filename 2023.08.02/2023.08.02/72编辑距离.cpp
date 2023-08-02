#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j]��ʾword1[0:i]��word2[0:j]�������ִ�����̱༭����
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        // ��ʼ��dp����
        for (int i = 0; i <= word1.size(); i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= word2.size(); i++) {
            dp[0][i] = i;
        }
        // ��ʼ����
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    // ִ���滻��������������һ������ĸ�滻����ͬ��
                    int substitude = dp[i - 1][j - 1] + 1;
                    // ɾ��word1�еĸ��ַ�
                    int del_word1 = dp[i - 1][j] + 1;
                    // ɾ��word2�еĸ��ַ�
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