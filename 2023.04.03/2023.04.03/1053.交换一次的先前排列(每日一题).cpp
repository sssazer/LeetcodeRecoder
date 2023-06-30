#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int max = 0;
        int left_pos = 0;
        bool flag = true;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= max) {
                max = arr[i];
                left_pos = i;
            }
            if (i != 0 && arr[i] < arr[i - 1]) {
                flag = false;
            }
        }
        if (flag) { // 如果数组本身就升序，直接返回
            return arr;
        }
        int right_pos = arr.size() - 1;
        max = 0;
        for (int i = arr.size(); i > left_pos; i++) {
            if (arr[i] >= max) {
                right_pos = i;
                max = arr[i];
            }
        }
        // 交换两个位置的值
        arr[left_pos] ^= arr[right_pos];
        arr[right_pos] ^= arr[left_pos];
        arr[left_pos] ^= arr[right_pos];
        return arr;
    }
};

int main() {

    Solution s;
    vector<int> arr = { 3,2,1 };
    s.prevPermOpt1(arr);
	return 0;
}