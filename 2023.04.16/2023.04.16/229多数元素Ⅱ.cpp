#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1, count1 = 0;
        int candidate2, count2 = 0;
        for (auto& i : nums) {
            if (count1 == 0 || count2 == 0) { // �����һ��λ��û�к�ѡ��
                if (count1 == 0 && count2 == 0) { // ����λ�ö�û�к�ѡ�ˣ�ֱ����һ��
                    candidate1 = i;
                    count1 = 1;
                    continue;
                }
                else if (count1 == 0) { // �����һ����ѡ�˿���
                    if (i == candidate2) {
                        count2++;
                        continue;
                    }
                    else {
                        candidate1 = i;
                        count1 = 1;
                        continue;
                    }
                }
                else { // ����ڶ�����ѡ�˿���
                    if (i == candidate1) {
                        count1++;
                        continue;
                    }
                    else {
                        candidate2 = i;
                        count2 = 1;
                        continue;
                    }
                }
            }
            else { // ������к�ѡ��
                if (i != candidate1 && i != candidate2) {
                    count1--;
                    count2--;
                }
                else if (i == candidate1) {
                    count1++;
                }
                else {
                    count2++;
                }
            }
        }
        vector<int> result;
        count1 = count2 = 0;
        for (auto& i : nums) {
            if (i == candidate1) {
                count1++;
            }
            else if (i == candidate2) {
                count2++;
            }
        }
        if (count1 > nums.size() / 3) {
            result.push_back(candidate1);
        }
        if (count2 > nums.size() / 3) {
            result.push_back(candidate2);
        }
        return result;
    }
};

int main() {

    Solution s;
    vector<int> nums = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,4,5,6,7,8,9 };
    s.majorityElement(nums);
	return 0;
}