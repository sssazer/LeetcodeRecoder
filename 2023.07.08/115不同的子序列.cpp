#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        // dp[i][j]表示s[0:j-1]的子序列中t[0:i-1]出现的次数
        vector<vector<u_int64_t>> dp(t.size() + 1, vector<u_int64_t>(s.size() + 1, 0));
        for(int i = 0; i <= s.size(); i++){ 
            // 当t取空串时，s的任意子序列中t出现的次数都是1
            dp[0][i] = 1; 
        }
        for(int i = 1; i <= t.size(); i++){
            for(int j = 1; j <= s.size(); j++){
                if(t[i - 1] == s[j - 1]){
                    dp[i][j] += dp[i - 1][j - 1];
                }
                dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[t.size()][s.size()];
    }
};

int main(){

    return 0;
}