#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // dp[i][j]表示s[i:j]是否是回文子串
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), 0));
        string res = s.substr(0, 1);
        int maxLen = 1;
        for(int i = s.size() - 1; i >= 0; i--){
            for(int j = i; j < s.size(); j++){
                if(i == j){
                    dp[i][j] = 1;
                    continue;
                }
                if(s[i] != s[j]){
                    continue;
                }
                if(j - i == 1 || dp[i + 1][j - 1]){
                    dp[i][j] = 1;
                    if(j - i + 1 > maxLen){
                        maxLen = j - i + 1;
                        res = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return res;
    }
};

int main(){

    Solution s;
    string str = "babad";
    s.longestPalindrome(str);

    return 0;
}