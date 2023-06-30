#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false); // dp[j]��ʾ�����ֵ��г��ֵĵ����ܷ�ƴ�ӳ�s��ǰj���ַ�
        dp[0] = true;
		for (int j = 0; j <= s.size(); j++) {
			for (int i = 0; i < wordDict.size(); i++) {
				int len = wordDict[i].size();
                if (j >= len && !dp[j]) {
                    dp[j] = dp[j - len] && wordSet.find(s.substr(j - len, len)) != wordSet.end();
                }
            }
        }
        return dp[s.size()];
    }
};

int main() {

    Solution s;
    string str = "leetcode";
    vector<string> wordDict = { "leet", "code" };
    cout << s.wordBreak(str, wordDict);
	return 0;
}