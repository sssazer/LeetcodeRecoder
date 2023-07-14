#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sum = 0;
    int distributeCoins(TreeNode* root) {
        countMoveTimes(root);
        return sum;
    }
    vector<int> countMoveTimes(TreeNode* root) { // ������rootΪ���ڵ�Ķ�������{�������Ӳ����}
        if (!root) {
            return {0, 0};
        }
        vector<int> leftTree = countMoveTimes(root->left);
        vector<int> rightTree = countMoveTimes(root->right);
        // ��rootΪ���ڵ�Ķ������� ����� - Ӳ���� ����Ҫ�øö������������Ӳ������ͬ��Ҫ����罻����Ӳ����
        sum += abs(leftTree[0] + rightTree[0] + 1 - leftTree[1] - rightTree[1] - root->val);
        return {leftTree[0] + rightTree[0] + 1, leftTree[1] + rightTree[1] + root->val};
    }
};

int main() {

	return 0;
}