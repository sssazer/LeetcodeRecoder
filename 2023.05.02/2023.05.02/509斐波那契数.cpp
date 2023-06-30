#include<iostream>
#include<vector>

using namespace std;

class Solution1 { // µÝ¹é
public:
    int fib(int n) { 
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        return fib(n - 1) + fib(n - 2);
    }
};

class Solution { // ¶¯Ì¬¹æ»®
public:
    vector<int> dp;
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        dp = vector<int>(n + 1);
        dp[0] = 0, dp[1] = 1;
        int i = 2;
        while (i <= n) {
            dp[i] = dp[i - 1] + dp[i - 2];
            i++;
        }
        return dp[n];
    }
};

//int main() {
//
//	return 0;
//}