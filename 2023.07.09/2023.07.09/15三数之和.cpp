#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3) {
			return {};
		}
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) { // 确定第一个数的位置，然后用双指针遍历找后二个数
			if (nums[i] > 0) return result; // 因为数组已经为升序，如果第一个数都大于零，那后面一定都大于零
			if (i > 0 && nums[i] == nums[i - 1]) continue; // 避免出现重复解
			int left = i + 1, right = nums.size() - 1; // 使用双指针进行遍历
			while (left < right) {
				if (nums[i] + nums[left] + nums[right] == 0) {
					result.push_back({nums[i], nums[left], nums[right]});
					// 把所有重复的都跳过
					while (left < right && nums[left + 1] == nums[left]) left++;
					while (left < right && nums[right - 1] == nums[right]) right--;
					left++, right--;
				}
				else if (nums[i] + nums[left] + nums[right] < 0) {
					left++;
				}
				else {
					right--;
				}
			}
		}
		return result;
	}
};

int main() {

	cout << "this is C++" << endl;

	return 0;
}