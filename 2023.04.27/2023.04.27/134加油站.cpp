#include<iostream>
#include<vector>

using namespace std;

class Solution1 { // �������޷�ac
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int start = 0; start < cost.size(); start++) { // ������ʼ����վ
            if (gas[start] < cost[start]) {
                continue;
            }
            int leftGas = gas[start] - cost[start]; // ��¼ʣ�µ�������
            int i;
            for (i = (start + 1) % cost.size(); i != start; i = (i + 1) % cost.size()) {
                leftGas += (gas[i] - cost[i]);
                if (leftGas <= 0) {
                    break;
                }
            }
            if (i == start || ((i + 1) % cost.size() == start && leftGas >= 0)) {
                return start;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> left(gas.size()); // ����ÿ������վ�����µ���
        int sumLeft = 0;
        for (int i = 0; i < gas.size(); i++) {
            left[i] = gas[i] - cost[i];
            sumLeft += left[i];
        }
        if (sumLeft < 0) { // �������վ���ͼ��������������ѣ��ǿ϶��߲���
            return -1;
        }
        int start = 0;
        int curLeft = 0;
        for (int i = 0; i < gas.size(); i++) {
            curLeft += left[i];
            if (curLeft < 0) { // �����0�ߵ�i֮��ʣ���ͱ�ɸ������ǿ϶����ܴ�0~i֮���κ�һ������վ��ʼ
                start = i + 1;
                curLeft = 0;
            }
        }
        return start;
    }
};

//int main() {
//
//    vector<int> gas = {3,1,1};
//    vector<int> cost = { 1,2,2 };
//    Solution s;
//    s.canCompleteCircuit(gas, cost);
//
//	return 0;
//}