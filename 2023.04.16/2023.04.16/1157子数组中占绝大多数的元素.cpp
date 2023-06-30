#include<iostream>
#include<vector>
#include<unordered_map>
#include<ctime>
#include<random>

using namespace std;

class MajorityChecker1 {
public:

    unordered_map<int, vector<int>> locations; // ��¼ÿ��Ԫ�س��ֵ�λ�ã�keyΪԪ�ص�ֵ��valueΪԪ�س��ֹ�������λ��
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
            int k = 30; // ��left��right�����ѡȡ30��λ��
            uniform_int_distribution<int> dis(left, right);
            while (k--) {
                int x = arr[dis(gen)];
				// �����λ�ö�Ӧ���������ֵ�����λ�õ������н��ж��ֲ���
				auto left_pos = lower_bound(locations[x].begin(), locations[x].end(), left);  // ����left���ֵ�λ��
				auto right_pos = upper_bound(locations[x].begin(), locations[x].end(), right); // ����right���ֵ�λ��
				int show_time = right_pos - left_pos; // ������λ��֮���Ԫ�ظ��������������left��right֮����ֵĴ���
				if (show_time >= threshold) { // ���Ԫ�س��ֵĴ�������Ҫ��ֱ�����
                    return x;
				}
				else if (show_time >= left + (right - left) / 2) { // ���Ԫ�س��ֵĴ���û�ﵽthreshold���ǳ����������鳤�ȵ�һ��
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
    mt19937 gen{ random_device{}() }; // ���������
};

//int main() {
//
//    vector<int> test = { 1, 1, 2, 2, 1, 1 };
//    MajorityChecker s(test);
//    s.query(0, 3, 3);
//
//	return 0;
//}