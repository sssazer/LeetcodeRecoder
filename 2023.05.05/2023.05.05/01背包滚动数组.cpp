#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int bagpack(vector<int> &weight, vector<int> &value, int capacity) {
		vector<int> dp(capacity + 1, 0);
		for (int i = 1; i <= capacity; i++) { // 初始化第一行
			if (i >= weight[0]) {
				dp[i] = value[0];
			}
		}
		for (int i = 1; i < weight.size(); i++) {
			for (int j = 1; j <= capacity; j++) {
				if (j >= weight[i]) {
					dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
				}
			}
			for (int num : dp) {
				cout << num << "  ";
			}
			cout << endl;
		}
		return dp[capacity];
	}
};

//int main() {
//
//	Solution s;
//	vector<int> weight = {1, 3, 4, 5};
//	vector<int> value = {15, 20, 30, 60};
//	cout << s.bagpack(weight, value, 5);
//
//	return 0;
//}