#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        // ��������words�еĵ��ʵ���С��ĸ����Ƶ�Σ���������Ƶ�ν�������
        vector<int> fW(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            fW[i] = f(words[i]);
        }
        sort(fW.begin(), fW.end(), greater<int>());
        
        // ����ÿһ��quries���ҵ�f(quries[i]) < f(W)�Ĵʵ���Ŀ�����ֲ��ң�
        vector<int> result;
        for (string& s : queries) {
            int target = f(s); // �ö��ַ��ҵ�targetҪ�����λ��
            int left = 0, right = fW.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (fW[mid] <= target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            result.push_back(right + 1);
        }
        return result;
    }

    int f(string s) { // ����s����С��ĸ�ĳ���Ƶ��
        char minC = 'z';
        for (char c : s) {
            if (c < minC) {
                minC = c;
            }
        }
        int res = 0;
        for (char c : s) {
            if (c == minC) {
                res++;
            }
        }
        return res;
    }
};

//int main() {
//
//	return 0;
//}