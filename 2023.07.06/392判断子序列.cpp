#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution1 { // 动态规划（最长公共子序列）
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= t.size(); j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[s.size()][t.size()] == s.size();
    }
};

class Solution2 { // 挨个查找字母
public:
    bool isSubsequence(string s, string t) {
        int lastPos = -1;
        for(int i = 0; i < s.size(); i++){
            lastPos = t.find(s[i], lastPos + 1);
            if(lastPos == -1){
                return false;
            }
        }
        return true;
    }
};


class Solution3 { // 双指针 
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while(i < s.size() && j < t.size()){
            if(s[i] == t[j]){
                i++;
            } 
            j++;
        }
        return i == s.size();
    }
};


class Solution { // 动态规划 
public:
    bool isSubsequence(string s, string t) {
    }
};

int main(){

    return 0;
}