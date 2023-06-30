#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        if (croakOfFrogs.size() % 5 != 0) {
            return -1;
        }
        vector<int> frogs(5, 0); // 记录所有现存叫声 frogs[0]表示c，以此类推
        unordered_map<char, int>::iterator mit;
        int minNum = 0;
        for (char c : croakOfFrogs) {
            switch(c) {
                case 'c':
                    if (frogs[4] == 0) {
                        frogs[0]++;
                        minNum++;
                    }
                    else {
                        frogs[4]--;
                        frogs[0]++;
                    }
                    break;
                case 'r':
                    if (frogs[0] == 0) {
                        return -1;
                    }
                    frogs[0]--;
                    frogs[1]++;
                    break;
                case 'o':
                    if (frogs[1] == 0) {
                        return -1;
                    }
                    frogs[1]--;
                    frogs[2]++;
                    break;
                case 'a':
                    if (frogs[2] == 0) {
                        return -1;
                    }
                    frogs[2]--;
                    frogs[3]++;
                    break;
                case 'k':
                    if (frogs[3] == 0) {
                        return -1;
                    }
                    frogs[3]--;
                    frogs[4]++;
                    break;
            }
        }
        for (int i = 0; i < 5; i++) {
            if (i != 4 && frogs[i] != 0) {
                return -1;
            }
        }
        return minNum;
    }
};

int main() {

    Solution s;
    cout << s.minNumberOfFrogs("ccroakroak");

	return 0;
}