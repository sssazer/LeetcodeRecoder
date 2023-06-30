#include<iostream>
#include<vector>

using namespace std;

class Solution { // ��ȫ����
public:
    int numSquares(int n) {
        vector<int> perfectSquares;
        for (int i = 1; ;i++) {
            if (i * i <= n)
                perfectSquares.push_back(i * i);
            else
                break;
        }
        vector<int> dp(n + 1, 10001); // dp[j]��ʾ��Ϊj����ȫƽ��������С����
        dp[0] = 0;
        for (int i = 0; i < perfectSquares.size(); i++) {
            for (int j = perfectSquares[i]; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - perfectSquares[i]] + 1);
            }
        }
        return dp[n];
    }
};

//int main() {
//    Solution s;
//    s.numSquares(12);
//	return 0;
//}