#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> set;
        for (int i = 0; i < fronts.size(); i++) {
            if (fronts[i] == backs[i]) {
                set.insert(fronts[i]);
            }
        }
        int min_card = INT_MAX;
        for (int i = 0; i < fronts.size(); i++) {
            if (set.find(fronts[i]) == set.end() && fronts[i] < min_card) {
                min_card = fronts[i];
            }
            if (set.find(backs[i]) == set.end() && backs[i] < min_card) {
                min_card = backs[i];
            }
        }
        if (min_card == INT_MAX) {
            return 0;
        }
        return min_card;
    }
};

int main() {

	return 0;
}