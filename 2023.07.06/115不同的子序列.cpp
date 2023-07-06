#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        // dp[i][j]表示s[0:j]的子序列中t[0:i]出现的个数
        vector<vector<int>> dp(t.size(), vector<int>(s.size(), 0));
        int showTimes = 0;
        for(int i = 0; i < s.size(); i++){ // 初始化dp数组第一行
            if(t[0] == s[i]){
                dp[0][i] = ++showTimes;
            }else{
                dp[0][i] = showTimes;
            }
        }
        for(int i = 1; i < t.size(); i++){
            for(int j = i; j < s.size(); j++){
                if(t[i] == s[j]){
                    dp[i][j] += dp[i - 1][j - 1];
                }
                dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[t.size() - 1][s.size() - 1];
    }
};

int main(){

    return  0;
}