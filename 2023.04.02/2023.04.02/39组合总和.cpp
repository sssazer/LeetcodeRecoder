#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:

    vector<int> candidates;
    vector<vector<int>> result;
    vector<int> current;

    void traceback(int start, int target, int sum) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            result.push_back(current);
            return;
        }
        for (; start < candidates.size(); start++) {
            current.push_back(candidates[start]);
            traceback(start, target, sum + candidates[start]);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->candidates = candidates;
        traceback(0, target, 0);
        return result;
    }
};

#include<forward_list>

//int main() {
//
//    forward_list<int> l;
//    vector<int> v;
//    for (int i = 1; i <= 10; i++) {
//        l.push_front(i);
//        v.push_back(i);
//    }
//    for (auto vit = v.begin(); vit != v.end(); vit++) {
//        cout << *vit << " ";
//    }
//    cout << endl;
//    for (auto lit = l.begin(); lit != l.end(); lit++) {
//        cout << *lit << " ";       
//    }
//
//	return 0;
//}