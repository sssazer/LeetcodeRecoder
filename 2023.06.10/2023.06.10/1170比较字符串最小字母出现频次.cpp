#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        // 计算所有words中的单词的最小字母出现频次，并按出现频次降序排序
        vector<int> fW(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            fW[i] = f(words[i]);
        }
        sort(fW.begin(), fW.end(), greater<int>());
        
        // 对于每一个quries，找到f(quries[i]) < f(W)的词的数目（二分查找）
        vector<int> result;
        for (string& s : queries) {
            int target = f(s); // 用二分法找到target要插入的位置
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

    int f(string s) { // 返回s中最小字母的出现频次
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