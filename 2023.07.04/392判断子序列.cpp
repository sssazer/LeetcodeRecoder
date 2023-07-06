#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.size() <= 1){
            if(t.size() == 0 && s.size() == 0){
                return true;
            }
            if(t.size() == 1 && s.size() == 1){
                return s[0] == t[0];
            }
            if(s.size() != t.size()){
                return false;
            }
        }
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= t.size(); j++){
                if(s[i] == t[j]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[s.size()][t.size()] == s.size();
    }
};

int main(){

    return 0;
}