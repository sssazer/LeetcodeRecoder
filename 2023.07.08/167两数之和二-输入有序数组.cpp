#include<iostream>
#include<vector>

using namespace std;

class Solution { // 二分查找
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); i++){
            int goal = target - numbers[i];
            int left = i + 1, right = numbers.size() - 1;
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(numbers[mid] == goal){
                    return {i + 1, mid + 1};
                }
                else if(numbers[mid] < goal){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return {};
    }
};

class Solution { // 双指针
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                return {left + 1, right + 1};
            }
            else if (sum < target){
                left++;
            }
            else{
                right--;
            }
        }
        return {};
    }
};

int main(){

    return 0;
}