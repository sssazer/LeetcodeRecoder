#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>
#include<algorithm>
#include<deque>

using namespace std;

class Solution1 {
public:
    vector<int> partitionLabels(string s) {
        int left = 0, right = 0;
		vector<int> result;
		vector<int> checkedChar(26); // ��¼�Ѿ��������ַ�
        while (left < s.size()) {
			deque<char> que; // ��¼��ǰ�������г��ֹ����ַ�
			que.push_back(s[left]);
            while (right < s.size() - 1 && que.size()) { // ÿ��������һ���ַ�����֤����ַ�ֻ�ڵ�ǰ�������г���
				char curCheck = *que.begin();
				checkedChar[curCheck - 'a']++;
				for (int i = right; i < s.size(); i++) { // ���Ͻ�rightֵ����Ϊ�ַ����һ�γ��ֵ�λ��
					if (s[i] == curCheck) {
						right = i;
						continue;
					}
				}
				for (int i = left + 1; i < right; i++) { // ���������г��ֹ����ַ���������Ķ�����
					if (!checkedChar[s[i] - 'a'] && find(que.begin(), que.end(), s[i]) == que.end()) {
						que.push_back(s[i]);
						break;
					}
				}
				que.pop_front();
            }// while_que.size()
			result.push_back(right - left + 1);
			left = right + 1;
        }
		return result;
    }
};

class Solution {
public:
	vector<int> partitionLabels(string s) {
		vector<int> maxRight(26, 0); // ��¼ÿ����ĸ���ֵ����ұߵ�λ��
		for (int i = 0; i < s.size(); i++) {
			maxRight[s[i] - 'a'] = i;
		}
		vector<int> result;
		int left = 0, right = 0;
		for (int i = 0; i < s.size(); i++) {
			right = max(right, maxRight[s[i] - 'a']);
			if (i == right) {
				result.push_back(right - left + 1);
				left = i + 1;
			}
		}
		return result;
	}
};

int main() {

	Solution s;
	string str = "ababcbacadefegdehijhklij";
	s.partitionLabels(str);

	return 0;
}