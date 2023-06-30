#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> powx, powy;
        if (x == 1) {
            powx.push_back(1);
        }
        else {
			for (int i = 0; ; i++) {
				int xpowi = pow(x, i);
				if (xpowi < bound) {
					powx.push_back(xpowi);
				}
				else {
					break;
				}
			}
        }
        if (y == 1) {
            powy.push_back(1);
        }
        else {
			for (int i = 0; ; i++) {
				int ypowi = pow(y, i);
				if (ypowi < bound) {
					powy.push_back(ypowi);
				}
				else {
					break;
				}
			}
        }
        unordered_set<int> result;
        for (int i = 0; i < powx.size(); i++) {
            for (int j = 0; j < powy.size(); j++) {
                if (powx[i] + powy[j] <= bound) {
                    result.insert(powx[i] + powy[j]);
                }
                else {
                    break;
                }
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};

//int main() {
//
//	return 0;
//}