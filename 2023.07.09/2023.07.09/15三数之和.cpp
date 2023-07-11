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
		for (int i = 0; i < nums.size(); i++) { // ȷ����һ������λ�ã�Ȼ����˫ָ������Һ������
			if (nums[i] > 0) return result; // ��Ϊ�����Ѿ�Ϊ���������һ�����������㣬�Ǻ���һ����������
			if (i > 0 && nums[i] == nums[i - 1]) continue; // ��������ظ���
			int left = i + 1, right = nums.size() - 1; // ʹ��˫ָ����б���
			while (left < right) {
				if (nums[i] + nums[left] + nums[right] == 0) {
					result.push_back({nums[i], nums[left], nums[right]});
					// �������ظ��Ķ�����
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