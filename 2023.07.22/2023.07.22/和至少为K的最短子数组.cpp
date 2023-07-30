#include<iostream>
#include<vector>

using namespace std;

class Solution { // ǰ׺��
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<int> sums(nums.size() + 1, 0); // ���ڴ洢nums��ǰ׺�ͣ�����sums[i]��nums[0]~nums[i - 1]�ĺͣ�sums[0] = 0
        sums[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        // ��������һ��������nums[i:j]�����ĺ�Ϊsums[j + 1] - sums[i]
        int minLen = nums.size() + 1;
        // ö��i~j���ҵ���С�ĺ�����Ϊk��������
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (sums[j + 1] - sums[i] >= k) {
                    minLen = min(minLen, j - i + 1);
                }
            }
        }
        if (minLen == nums.size() + 1) {
            return -1;
        }
        return minLen;
    }
};

//int main() {
//
//	return 0;
//}