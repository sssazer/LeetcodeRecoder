#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int maxPos = 0;
        int curPos = 0;
        int jumpTime = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxPos = max(maxPos, nums[i] + i); // ������Զ���Ƿ�Χ
            if (curPos <= i) { // ����������˵�ǰ����λ�ã�����ǰ��һ��
                if (maxPos >= nums.size() - 1) {
                    jumpTime++;
                    break;
                }
                curPos = maxPos;
                jumpTime++;
            }
        }
        return jumpTime;
    }
};

//int main() {
//
//	return 0;
//}
