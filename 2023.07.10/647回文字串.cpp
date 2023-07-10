#include<iostream>
#include<vector>

using namespace std;

class Solution { // 动态规划
public:
    int countSubstrings(string s) {
        // dp[i][j]表示s[i:j]是否是回文字串，那么如果s[i]==s[j]，只需s[i+1:j-1]是回文字串s[i:j]即为回文字串
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), 1)); 
        int count = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            for(int j = i; j < s.size(); j++){ // 只有当i<j时s[i:j]子区间才有意义
                if(i == j){ // i=j时该子串只有一个字母组成，这总是一个回文子串
                    dp[i][j] = 1;
                    count++;
                    continue;
                }
                if(s[i] != s[j]) {// 如果这个子串首尾都不相同，那肯定不是回文子串
                    dp[i][j] = 0;
                    continue;
                } 
                dp[i][j] = dp[i + 1][j - 1]; // 如果该子串首尾相同，那它是否是回文子串取决于中间部分是不是回文子串
                count += dp[i][j];
            }
        }
        return count;
    }
};

class Solution { // 双指针
public:
    int countSubstrings(string s) {
        // 遍历中心点，然后以中心点往外扩展找回文子串
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            // 以一个元素为中心点
            result++; // 一个元素总是回文子串
            int left = i - 1, right = i + 1;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                result++;
                left--, right++;
            }
            // 以两个元素为中心点
            if(i + 1 < s.size() && s[i] == s[i + 1]){
                result++;
                int left = i - 1, right = i + 2;
                while(left >= 0 && right < s.size() && s[left] == s[right]){
                    result++;
                    left--, right++;
                } 
            }
        }
        return result;
    }
};

int main(){

    return 0;
}