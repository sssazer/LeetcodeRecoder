#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> map;
        for (char c : word) { // 统计每个字符出现的次数
            map[c]++;
        }
        unordered_map<int, int> frequencyShowTime; // 统计每个频率出现的次数
        for (const pair<char, int>& p : map) {
            frequencyShowTime[p.second]++;
        }
        for (const pair<char, int>& p : map) { // 依次删除每个字符，看能否使频率相同
            unordered_map<int, int> temp(frequencyShowTime);
            if (!(--temp[p.second])) { // 删除字符后，这个字符对应的频率就要减一
                temp.erase(p.second); // 所以frequencyShowTime 原频率出现次数-1，现频率出现次数+1
            }
            int minusOne = p.second - 1;
            if (minusOne) temp[minusOne]++;
            if (temp.size() == 1) {
                return true;
            }
        }
        return false;
    }
};

//int main() {
//
//	return 0;
//}