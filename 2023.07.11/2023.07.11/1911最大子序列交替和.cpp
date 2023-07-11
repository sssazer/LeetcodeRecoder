#include<iostream>
#include<vector>

using namespace std;

// ͬ122.������Ʊ�����ʱ����ֻ�����൱�����ǿ����������һ���ɱ�Ϊ0Ԫ�Ĺ�Ʊ

class Solution { // ̰��
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum = nums[0];
        int flag = 0; // flag=0��ʾ��ǰ�ҵ���ż��λ�ã�flag=1��ʾ��ǰ������λ��
        for (int i = 1; i < nums.size(); i++) {
            if (flag == 0) { // Ѱ��ż��λ��
                if (nums[i] >= nums[i - 1]) { // ż��λ��Խ��Խ��
                    sum += nums[i] - nums[i - 1];
                }
                else { // ��������С��ʱ�򣬾Ϳ�ʼѰ������λ��
                    sum -= nums[i];
                    flag = 1;
                }
            }
            else { // Ѱ������λ��
                if (nums[i] <= nums[i - 1]) { // ����λ��ԽСԽ��
                    sum += nums[i - 1] - nums[i];
                }
                else { // ����������ʱ��Ϳ�ʼѰ��ż��λ��
                    sum += nums[i];
                    flag = 0;
                }
            }
        }
        if (flag == 1) {
            sum += nums[nums.size() - 1];
        }
        return sum;
    }
};


class Solution { // ��̬�滮
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // dp[i][0]��ʾѡ��nums[i]Ϊż���±�Ԫ��ʱ����������н����
        // dp[i][1]��ʾѡ��nums[i]Ϊ�����±�Ԫ��ʱ����������н����
        vector<vector<long long>> dp(2, vector<long long>(nums.size(), 0));
        dp[0][0] = nums[0], dp[1][0] = 0;
        for (int i = 1; i < nums.size(); i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + nums[i]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - nums[i]);
        }
        return max(dp[0][nums.size() - 1], dp[1][nums.size() - 1]);

    }
};

int main() {

	return 0;
}