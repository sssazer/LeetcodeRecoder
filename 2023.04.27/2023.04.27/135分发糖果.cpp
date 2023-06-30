#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // �ֱ���һ����ߺ��ұߣ�����ͬʱ����һ�����ӵ���ߺ��ұߣ���Ȼ�������޴��ݺ��ۼ�
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) {
            return 1;
        }
        vector<int> distribution(ratings.size(), 0);
        int leftChild = ratings.size(); // ��¼���м�������û�õ��ǹ�
        for (int i = 0; i < ratings.size(); i++) { // �ҵ������е����м�Сֵ�����ָ�����һ���ǹ�
            // ����˵�ֵ
            if (i == 0) {
                if (ratings[1] >= ratings[0]) {
                    distribution[0] = 1;
                    leftChild--;
                }
                continue;
            }
            else if (i == ratings.size() - 1) {
                if (ratings[i] <= ratings[i - 1]) {
                    distribution[i] = 1;
                    leftChild--;
                }
                continue;
            }
            // �����м�ֵ
            if ((ratings[i + 1] > ratings[i] && ratings[i - 1] > ratings[i]) //  \/���
                || (ratings[i + 1] == ratings[i] && ratings[i - 1] > ratings[i]) //  \__��� 
                || (ratings[i + 1] > ratings[i] && ratings[i - 1] == ratings[i])) { // --/��� 
                distribution[i] = 1;
                leftChild--;
            }
            else if (ratings[i + 1] == ratings[i] && ratings[i - 1] == ratings[i]) { // ---���
                distribution[i] = 1;
                leftChild--;
            }
        }
        
        // ��ֻ����ÿ�����ӵ����
        for (int i = 1; i < ratings.size(); i++) {
            if (distribution[i] == 1) {
                continue;
            }
            if (ratings[i] > ratings[i - 1]) {
                distribution[i] = distribution[i - 1] + 1;
            }
        }
        // ��ֻ����ÿ�����ӵ��ұ�
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (distribution[i] == 1) {
                continue;
            }
            if (ratings[i] > ratings[i + 1]) {
                distribution[i] = max(distribution[i], distribution[i + 1] + 1);
            }
        }
        int sumCandy = 0;
        for (int i : distribution) {
            sumCandy += i;
        }
        return sumCandy;
    }
};

int main() {

    Solution s;
    vector<int> ratings = { 0 };
    cout << s.candy(ratings);
    
	return 0;
}