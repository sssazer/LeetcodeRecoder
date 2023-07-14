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
    vector<int> countMoveTimes(TreeNode* root) { // 返回以root为根节点的二叉树的{结点数，硬币数}
        if (!root) {
            return {0, 0};
        }
        vector<int> leftTree = countMoveTimes(root->left);
        vector<int> rightTree = countMoveTimes(root->right);
        // 以root为根节点的二叉树的 结点数 - 硬币数 就是要让该二叉树结点数与硬币数相同需要与外界交换的硬币数
        sum += abs(leftTree[0] + rightTree[0] + 1 - leftTree[1] - rightTree[1] - root->val);
        return {leftTree[0] + rightTree[0] + 1, leftTree[1] + rightTree[1] + root->val};
    }
};

int main() {

	return 0;
}