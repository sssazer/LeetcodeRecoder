#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        float minimum = -1, maximum = -1, mode = 0; 
        double mean = 0, median = 0;
        int maxTimes = 0; // ��¼�������Ĵ���
        int countNum = 0; // ��¼һ���ж��ٸ�����
        for (int i = 0; i <= 255; i++) {
            if (!count[i]) {
                continue;
            }
            if (minimum < 0) { // ��¼��Сֵ
                minimum = i;
            }
            maximum = i; // ��¼���ֵ
            mean += (double)i * count[i]; // ��¼���������ܺ������ƽ����
            countNum += count[i]; // ��¼����������
            if (count[i] > maxTimes) { // ��¼����
                maxTimes = count[i];
                mode = i;
            }
        }
        mean /= countNum;
        int flag = countNum % 2;
        int midPos = countNum / 2 + flag;
        countNum = 0;
        for (int i = 0; i <= 255; i++) { // Ѱ����λ��
            countNum += count[i];
            if (countNum == midPos && !flag) {
                median += i;
                for (++i; i <= 255; i++) {
                    if (count[i] > 0) {
                        median += i;
                        break;
                    }
                }
                median /= 2;
                break;
            }
            if (countNum >= midPos) {
                median = i;
                break;
            }
        }
        return {minimum, maximum, mean, median, mode};
    }
};

//int main() {
//
//	return 0;
//}