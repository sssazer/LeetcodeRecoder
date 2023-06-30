#include<iostream>
#include<vector>
#include<unordered_map>
#include<ctime>
#include<random>

using namespace std;

class MajorityChecker1 {
public:

    unordered_map<int, vector<int>> locations; // 记录每个元素出现的位置，key为元素的值，value为元素出现过的所有位置
    vector<int> arr;
    mt19937 gen{ random_device{}() };
   
    MajorityChecker1(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
			locations[arr[i]].push_back(i);
        }
        this->arr = arr;
    }

    int query(int left, int right, int threshold) {
        if (arr.size() < 100 || right - left < 100) {
            unordered_map<int, int> map;
            for (int i = left; i <= right; i++) {
                map[arr[i]]++;
                if (map[arr[i]] >= threshold) {
                    return arr[i];
                }
            }
            return -1;
        }
        else {
            int k = 30; // 在left和right中随机选取30个位置
            uniform_int_distribution<int> dis(left, right);
            while (k--) {
                int x = arr[dis(gen)];
				// 在这个位置对应的数所出现的所有位置的数组中进行二分查找
				auto left_pos = lower_bound(locations[x].begin(), locations[x].end(), left);  // 查找left出现的位置
				auto right_pos = upper_bound(locations[x].begin(), locations[x].end(), right); // 查找right出现的位置
				int show_time = right_pos - left_pos; // 这两个位置之间的元素个数就是这个数在left和right之间出现的次数
				if (show_time >= threshold) { // 如果元素出现的次数满足要求直接输出
                    return x;
				}
				else if (show_time >= left + (right - left) / 2) { // 如果元素出现的次数没达到threshold但是超过了子数组长度的一半
					return -1;
				}
				else {
					continue;
				}
            }
            return -1;
        }
    }

};


class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr) : arr(arr) {
        for (int i = 0; i < arr.size(); ++i) {
            loc[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int threshold) {
        int length = right - left + 1;
        uniform_int_distribution<int> dis(left, right);

        for (int i = 0; i < k; ++i) {
            int x = arr[dis(gen)];
            vector<int>& pos = loc[x];
            int occ = upper_bound(pos.begin(), pos.end(), right) - lower_bound(pos.begin(), pos.end(), left);
            if (occ >= threshold) {
                return x;
            }
            else if (occ * 2 >= length) {
                return -1;
            }
        }

        return -1;
    }

private:
    static constexpr int k = 20;

    const vector<int>& arr;
    unordered_map<int, vector<int>> loc;
    mt19937 gen{ random_device{}() }; // 随机数种子
};

//int main() {
//
//    vector<int> test = { 1, 1, 2, 2, 1, 1 };
//    MajorityChecker s(test);
//    s.query(0, 3, 3);
//
//	return 0;
//}