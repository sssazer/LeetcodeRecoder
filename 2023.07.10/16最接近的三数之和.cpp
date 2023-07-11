#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDiff = INT32_MAX; // 记录三数和中与target的最小差值
        int result = 0;
        sort(nums.begin(), nums.end(), less<int>()); 
        for(int i = 0; i < nums.size(); i++){
            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                int diff = nums[i] + nums[left] + nums[right] - target;
                if(abs(diff) < minDiff){
                    minDiff = abs(diff);
                    result = nums[i] + nums[left] + nums[right];
                }
                if(diff == 0){
                    return target;
                }
                else if(diff > 0){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return result;
    }
};

int main(){

    return 0;
}