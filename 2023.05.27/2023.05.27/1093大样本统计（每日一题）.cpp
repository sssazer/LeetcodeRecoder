#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        float minimum = -1, maximum = -1, mode = 0; 
        double mean = 0, median = 0;
        int maxTimes = 0; // 记录出现最多的次数
        int countNum = 0; // 记录一共有多少个整数
        for (int i = 0; i <= 255; i++) {
            if (!count[i]) {
                continue;
            }
            if (minimum < 0) { // 记录最小值
                minimum = i;
            }
            maximum = i; // 记录最大值
            mean += (double)i * count[i]; // 记录所有数据总和最后算平均数
            countNum += count[i]; // 记录数据总数量
            if (count[i] > maxTimes) { // 记录众数
                maxTimes = count[i];
                mode = i;
            }
        }
        mean /= countNum;
        int flag = countNum % 2;
        int midPos = countNum / 2 + flag;
        countNum = 0;
        for (int i = 0; i <= 255; i++) { // 寻找中位数
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