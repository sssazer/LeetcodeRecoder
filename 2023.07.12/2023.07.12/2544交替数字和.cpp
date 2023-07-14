#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> nums;
        while (n > 0) {
            nums.push_back(n % 10);
            n /= 10;
        }
        int sign = 1; // sign��ʾ��ǰ���ַ��䵽�ķ���
        int sum = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            sum += sign * nums[i];
            sign = -sign;
        }
        return sum;
    }
};

class Solution {
public:
    int alternateDigitSum(int n) {
        int sum = 0;
        // �����λ��ʼ��������n����λ����abcde��ʾ����
        // 1: sum = e - 0
        // 2: sum = d - (e - 0) = d - e
        // 3: sum = c - (d - e) = c - d + e
        // 4: sum = b - (c - d + e) = b - c + d - e
        // 5: sum = a - (b - c + d - e) = a - b + c - d + e
        // ��֤��ÿ�����λ��������������������ַ��Ž���
        while (n > 0) {
            sum = n % 10 - sum;
            n /= 10;
        }
        return sum;
    }
};

int main() {

	return 0;
}