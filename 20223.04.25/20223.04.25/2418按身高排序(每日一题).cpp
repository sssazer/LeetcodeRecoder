#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<functional>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string, greater<int>> heighttoName;
        for (int i = 0; i < names.size(); i++) {
            heighttoName.insert(make_pair(heights[i], names[i]));
        }
        vector<string> result;
        result.reserve(names.size());
        for (pair<int, string> p : heighttoName) {
            result.push_back(p.second);
        }
        return result;
    }
};

//int main() {
//
//	return 0;
//}