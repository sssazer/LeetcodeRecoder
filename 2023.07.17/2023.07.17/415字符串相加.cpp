#include<iostream>
#include<vector>
#include<deque>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int jinwei = 0;
        deque<char> res_de;
        int index1 = num1.size() - 1, index2 = num2.size() - 1;
        while (index1 >= 0 && index2 >= 0) {
            res_de.push_front((num1[index1] - '0' + num2[index2] - '0' + jinwei) % 10 + '0');
            jinwei = (num1[index1] - '0' + num2[index2] - '0' + jinwei) / 10;
            index1--, index2--;
        }
        while (index1 >= 0) {
            res_de.push_front((num1[index1] - '0' + jinwei) % 10 + '0');
            jinwei = (num1[index1] - '0' + jinwei) / 10;
            index1--;
        }
        while (index2 >= 0) {
            res_de.push_front((num2[index2] - '0' + jinwei) % 10 + '0');
            jinwei = (num2[index2] - '0' + jinwei) / 10;
            index2--;
        }
        if (jinwei) {
            res_de.push_front('1');
        }
        return string(res_de.begin(), res_de.end());
    }
};

int main() {

	return 0;
}