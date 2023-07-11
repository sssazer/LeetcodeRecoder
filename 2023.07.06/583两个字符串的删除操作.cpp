#include<iostream>
#include<vector>

using namespace std;

class Solution1 {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1; 
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return word1.size() + word2.size() - 2 * dp[word1.size()][word2.size()];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j]表示使得word1[0:i-1]和word2[0:j-1]相同所需的最小步数
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        // 初始化dp数组  当某个个下标为0时，要使与空数组相等，就得把所有元素都删掉
        for(int i = 0; i <= word1.size(); i++){
            dp[i][0] = i;
        }
        for(int j = 0; j <= word2.size(); j++){
            dp[0][j] = j;
        }
        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                if(word1[i - 1] == word2[j - 1]){
                    // 相等时不用删除
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    // 不等时有三种方案，删除word1[i]或删除word2[j]或两个一起删除，取最小值
                    dp[i][j] = min(min(dp[i - 1][j - 1] + 2, dp[i - 1][j] + 1), dp[i][j - 1] + 1);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main(){

    return 0;
}