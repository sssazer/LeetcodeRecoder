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
    int rob(TreeNode* root) {
        vector<int> res = robTest(root);
        return max(res[0], res[1]);
    }
    vector<int> robTest(TreeNode* root) { // 返回 {不偷该节点得到的最大金额，偷该结点得到的最大金额}
        if (!root) {
            return { 0, 0 };
        }
        vector<int> left = robTest(root->left); // 获取左节点偷与不偷的最大值
        vector<int> right = robTest(root->right); // 获取右节点偷与不偷的最大值

        int stole = root->val + left[0] + right[0]; // 如果偷本节点，那左右孩子节点都不能偷
        int notStole = max(left[0], left[1]) + max(right[0], right[1]); // 如果不偷本节点，那左右孩子随便偷

        return {notStole, stole};
    }
};

//int main() {
//
//	return 0;
//}