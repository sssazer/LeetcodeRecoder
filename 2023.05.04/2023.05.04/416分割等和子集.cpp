#include<iostream>
#include<vector>

using namespace std;

class Solution1 { // ���ݣ���ʱ
public:
    bool traceback(vector<int>& nums, int startIndex, int sum1, int sum2) {
        if (sum1 == sum2) {
            return true;
        }
        if (startIndex >= nums.size()) return false;
        if (traceback(nums, startIndex + 1, sum1, sum2)) return true;
        if (traceback(nums, startIndex + 1, sum1 + nums[startIndex], sum2 - nums[startIndex]))
            return true;
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int& i : nums) {
            sum += i;
        }
        return traceback(nums, 0, 0, sum);
    }
};

class Solution { // 0-1���������ܷ�պý�����Ϊsum/2�ı���װ����Ҳ���Ǿ����ܶ�װ��������ж��ܲ���װ������
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int& i : nums) {
            sum += i;
        }
        if (sum % 2 == 1) {
            return false;
        }
        // dp[i][j] ��ʾ��nums[0]~nums[i]����ѡ����������Ϊj�ı�����װ�������װ����
        vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, 0));
        for (int i = 1; i <= sum / 2; i++) { // ��ʼ��dp�����һ��
            dp[0][i] = i >= nums[0];
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j <= sum / 2; j++) {
                int choose = 0;
                if (j >= nums[i]) {
                    choose = dp[i - 1][j - nums[i]] + nums[i]; // ����ѵ�i������װ��������
                }
                int notChoose = dp[i - 1][j]; // ������ѵ�i������װ��������
                dp[i][j] = max(choose, notChoose);
            }
        }
        return dp[nums.size() - 1][sum / 2] == (sum / 2);
    }
};

int main() {

    Solution s;
    vector<int> nums = {1,5,11,5};
    s.canPartition(nums);

	return 0;
}