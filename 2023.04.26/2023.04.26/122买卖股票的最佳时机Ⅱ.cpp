#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // ����˼·������״̬�������д�Խ��ȥ������
    // ÿ�춼���Ʊ������ڶ���۸���߾�ֱ������Ȼ�������
    // ����ڶ���۸���;�ǰһ���������������������
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int curPrice = prices[0]; // ���������еĹ�Ʊ������۸�
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > curPrice) { // ��Ʊ����
                profit += (prices[i] - curPrice);
            }
            curPrice = prices[i];
        }
        return profit;
    }
};

//int main() {
//
//	return 0;
//}