#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum % 2){
            return {};
        }
        vector<long long> res;
        for(int i = 2; finalSum > i; i += 2){
            res.push_back(i);
            finalSum -= i;
        }
        res[res.size() - 1] += finalSum;
        return res;
    }
};

int main(){

    return 0;
}