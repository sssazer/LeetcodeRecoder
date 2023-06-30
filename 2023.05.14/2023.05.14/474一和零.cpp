#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> count; // ��Ӧλ�õ��ַ���������0��1������������counts[0][0]��ʾstrs[0]������0������
        for (string& s : strs) {
            vector<int> temp = {0, 0};
            for (char c : s) {
                temp[c - '0']++;
            }
            count.push_back(temp);
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // dp[i][j]��ʾ ����� i��0 �� j��1 ������Ӽ�����
        for (int i = 0; i < strs.size(); i++) { // ��ʾ���ڿ��Դ�strs[0]~strs[i]����ȡ�ַ�����������װ
            for (int j = m; j >= count[i][0]; j--) { // ��������װ0����������Ҫ���ڵ�ǰҪװ��i
                for (int k = n; k >= count[i][1]; k--) { // ��������װ1���������ٴ��ڵ�ǰҪװ��i
                    dp[j][k] = max(dp[j][k], dp[j - count[i][0]][k - count[i][1]] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {

	return 0;
}