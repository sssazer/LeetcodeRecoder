#include<iostream>
#include<vector>
#include<deque>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        deque<int> splitN;
        int tempN = n;
        while (tempN) {
            splitN.push_front(tempN % 10);
            tempN /= 10;
        }
        int i;
        for (i = 1; i < splitN.size(); i++) { // 如果这个数本身就是递增的，直接返回这个数
            if (splitN[i] < splitN[i - 1]) {
                break;
            }
        }
        if (i >= splitN.size()) {
            return n;
        }
        int begin = -1;
        for (i = 1; i < splitN.size(); i++) { // 如果这个数不是递增的，找到开始递减的位置
            if (splitN[i] > splitN[i - 1]) { 
                continue;
            }
            else if (splitN[i] == splitN[i - 1]) { 
                bool findBegin = false;
                int tempBegin = i;
                for (i++; i < splitN.size(); i++) {
                    if (splitN[i] == splitN[i - 1]) {
                        continue;
                    }
                    else if (splitN[i] < splitN[i - 1]) {
                        findBegin = true;
                        begin = tempBegin - 1;
                        break;
                    }
                    else {
                        break;
                    }
                }
                if (findBegin) {
                    break;
                }
            }
            else {
                begin = i - 1;
                break;
            }
        }
        splitN[begin++]--;
        for (; begin < splitN.size(); begin++) {
            splitN[begin] = 9;
        }
        int result = 0;
        for (int i : splitN) {
            result *= 10;
            result += i;
        }
        return result;
    }
};

//int main() {
//
//	return 0;
//}