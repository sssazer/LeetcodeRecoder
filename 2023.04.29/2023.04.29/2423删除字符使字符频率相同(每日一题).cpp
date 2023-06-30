#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> map;
        for (char c : word) { // ͳ��ÿ���ַ����ֵĴ���
            map[c]++;
        }
        unordered_map<int, int> frequencyShowTime; // ͳ��ÿ��Ƶ�ʳ��ֵĴ���
        for (const pair<char, int>& p : map) {
            frequencyShowTime[p.second]++;
        }
        for (const pair<char, int>& p : map) { // ����ɾ��ÿ���ַ������ܷ�ʹƵ����ͬ
            unordered_map<int, int> temp(frequencyShowTime);
            if (!(--temp[p.second])) { // ɾ���ַ�������ַ���Ӧ��Ƶ�ʾ�Ҫ��һ
                temp.erase(p.second); // ����frequencyShowTime ԭƵ�ʳ��ִ���-1����Ƶ�ʳ��ִ���+1
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