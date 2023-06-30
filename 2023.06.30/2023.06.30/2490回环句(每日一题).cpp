#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        for (int i = 1; i < sentence.size() - 1; i++) {
            if (sentence[i] == ' ') {
                if (sentence[i - 1] != sentence[i + 1]) {
                    return false;
                }
            }
        }
        return sentence[0] == sentence[sentence.size() - 1];
    }
};

//int main() {
//
//	return 0;
//}