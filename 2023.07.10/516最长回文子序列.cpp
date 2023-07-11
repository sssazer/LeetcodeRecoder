#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // dp[i][j] s[i:j]中最长回文子序列的长度 
        int maxLen = 1;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i = s.size() - 1; i >= 0; i--){
            for(int j = i; j < s.size(); j++){
                if(i == j){
                    dp[i][j] = 1;
                    continue;
                }
                if(s[i] != s[j]){
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
                if(s[i] == s[j]){
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        return maxLen;
    }
};

int main(){

    return 0;
}