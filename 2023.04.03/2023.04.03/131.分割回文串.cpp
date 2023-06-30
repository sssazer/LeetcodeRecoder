#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:

	bool isHuiWen(string str) {
		int left = 0, right = str.size() - 1;
		while (left < right) {
			if (str[left] != str[right]) {
				return false;
			}
			left++;
			right--;
		}
		return true;
	}

	string s;
	vector<vector<string>> result;
	vector<string> current;
	string curr_str;
	
	void traceback(int startIndex) {
		if (startIndex == s.size()) {
			result.push_back(current);
		}
		for (int len = 1; len <= s.size() - startIndex; len++) { // len表示本次要切割的长度，最小切割一个字母，最多切割剩下的全部字母
			string temp = s.substr(startIndex, len);
			if (!isHuiWen(temp)) { // 如果本次切割出的字符串不是回文串，直接跳过本次循环
				continue;
			}
			current.push_back(temp);
			traceback(startIndex + len);
			current.pop_back();
		}
	}

	vector<vector<string>> partition(string s) {
		this->s = s;
		traceback(0);
		return result;
	}
};

//int main() {
//
//	int i;
//	
//
//	return 0;
//}