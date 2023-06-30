#include<iostream>
#include<vector>

using namespace std;

// ������������¥�ݣ���Ҫn�ײ��ܵ���¥��
// ÿ���������1~m��̨�ף����ж����ֲ�ͬ�ķ�����������¥����
// ��ʱ�൱�ڱ�������Ϊn����ƷΪ1~m��������Ʒװ�����б�����������(Ԫ��˳��ͬ�㲻ͬ����)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= n; j++) {
            for (int i = 1; i <= 2; i++) {
                if (j >= i) {
                    dp[j] += dp[j - i];
                }
            }
        }
        return dp[n];
    }
};

int main() {

	return 0;
}