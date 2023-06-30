#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // ��nums�����Ϊ�����֣�һ����Ϊplus����һ����Ϊminus
        // ���� plus + minus = sum��plus - minus = target������plus = ��sum+target��/2
        // ��ת��Ϊ0-1�������⣬��nums�е�Ԫ��װ����Ϊplus�ı���������װ�������ķ�����
        if (nums.size() == 1) {
            if (nums[0] == 0) {
                return 2;
            }
            return nums[0] == target;
        }
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        int capacity = target + (sum - target) / 2;
        if (capacity % 2 == 1) {
            return 0;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(capacity + 1, 0)); // dp[i][j]��ʾ��ѡnums[0]~nums[i]װ����Ϊj�ı����м��ַ�����װ��
        // ��ʼ��dp����
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = 1; // ��������Ϊ0ʱ����ֵ�� nums[i] = jʱ���õ�
            // ��ʱ dp[i][j] = dp[i - 1][j] + dp[i - 1][0]����ȻҪ+1������+0
        }
        for (int i = 1; i <= capacity; i++) {
            dp[0][i] = nums[0] == i;
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j <= capacity; j++) {
                dp[i][j] += dp[i - 1][j]; // ��װ��ǰnums[i]�ķ�����
                // װnums[i]�ķ�����
                if (j >= nums[i]) {
                    dp[i][j] += dp[i - 1][j - nums[i]];
                }
            }
        }
        return dp[nums.size() - 1][capacity];
    }
};

int main() {

	return 0;
}