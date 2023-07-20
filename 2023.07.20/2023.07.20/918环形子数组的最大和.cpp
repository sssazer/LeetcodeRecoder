#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) { // ̰��
        // �����������
        // 1����������������м䣬û�п�Խͷ��β���������ֱ�����������Ϳ�����
        // 2����������Խ��ͷβ����������൱�������ܺͼ�ȥ���м����������飬�����������Ϳ�����
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int curSumMax = 0, curSumMin = 0;
        int flag = 0, maxNum = 0; // flag���ڼ�¼�����Ƿ�ȫ�Ǹ��������ȫ�Ǹ������ͷ�������Ԫ��
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                flag = 1;
            }
            maxNum = max(maxNum, nums[i]);
            curSumMax += nums[i];
            curSumMin += nums[i];
            maxSum = max(maxSum, curSumMax);
            minSum = min(minSum, curSumMin);
            if (curSumMax < 0) { // �����ǰ�������Ϊ������������ѡ��������
                curSumMax = 0;
            }
            if (curSumMin > 0) {
                curSumMin = 0;
            }
        }
        if (!flag) {
            return maxNum;
        }
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        return max(maxSum, minSum);
    }
};

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) { // ��̬�滮
        // �����������
        // 1����������������м䣬û�п�Խͷ��β���������ֱ�����������Ϳ�����
        // 2����������Խ��ͷβ����������൱�������ܺͼ�ȥ���м����������飬�����������Ϳ�����
        // ˼·��������ͬ��ֻ����������������ķ�ʽ��Ϊ��̬�滮
        int maxSum = 0, minSum = 0;
        vector<int> maxDp(nums.size(), 0); // dp[i]����nums[i]Ϊ��β������������
        vector<int> minDp(nums.size(), 0); // dp[i]: ��nums[i]Ϊ��β����С�������
        maxDp[0] = minDp[0] = nums[0];
        int flag = 1, maxNum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                flag = 0;
            }
            else {
                maxNum = max(maxNum, nums[i]);
            }
            maxDp[i] = max(maxDp[i - 1] + nums[i], nums[i]);
            minDp[i] = min(minDp[i - 1] + nums[i], nums[i]);
            maxSum = max(maxSum, maxDp[i]);
            minSum = min(minSum, minDp[i]);
        }
        if (flag) {
            return maxNum;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return max(maxSum, sum - minSum);
    }
};
int main() {

	return 0;
}