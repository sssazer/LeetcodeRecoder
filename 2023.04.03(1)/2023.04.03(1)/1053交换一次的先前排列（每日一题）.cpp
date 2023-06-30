#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int left_pos = -1;
        bool flag = true;
        for (int i = arr.size() - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                left_pos = i;
                break;
            }
        }
        if (left_pos == -1) { // 如果数组本身就升序，直接返回
            return arr;
        }
        int right_pos = arr.size() - 1;
        int diff = INT_MAX;
        for (int i = arr.size() - 1; i > left_pos; i--) {
            if (arr[i] < arr[left_pos] && arr[left_pos] - arr[i] <= diff) {
                right_pos = i;
                diff = arr[left_pos] - arr[i];
            }
        }
        // 交换两个位置的值
        arr[left_pos] ^= arr[right_pos];
        arr[right_pos] ^= arr[left_pos];
        arr[left_pos] ^= arr[right_pos];
        return arr;
    }
};

//int main() {
//
//    Solution s;
//    vector<int> arr = { 3,2,1 };
//    s.prevPermOpt1(arr);
//    return 0;
//}