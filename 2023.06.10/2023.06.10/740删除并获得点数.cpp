#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> numsInfo; // �洢nums�����г��ֵ����ּ�����ִ���
        for (int num : nums) {
            numsInfo[num]++;
        }
        vector<vector<int>> dp(numsInfo.size()); // dp[i]��ʾ{nums�е�һ����num����nums��ȡ������0~num���ɵ�subNums�У��ܻ�õ�������}
        int index = 0;
        for (const pair<int, int>& p : numsInfo) {
            if (index == 0) {
                dp[index] = { p.first, p.first * p.second };
                index++;
                continue;
            }
            if (dp[index - 1][0] == p.first - 1) {
                if (index > 1) {
                    dp[index] = { p.first, max(dp[index - 1][1], dp[index - 2][1] + p.first * p.second) };
                }
                else {
                    dp[index] = { p.first, max(dp[index - 1][1], p.first * p.second) };
                }
                index++;
            }
            else {
                dp[index] = { p.first, dp[index - 1][1] + p.first * p.second };
                index++;
            }
        }
        return dp[dp.size() - 1][1];
    }
};

int main() {
    Solution s;
    vector<int> nums = { 1,1,1,2,4,5,5,5,6 };
    cout << s.deleteAndEarn(nums);
	return 0;
}