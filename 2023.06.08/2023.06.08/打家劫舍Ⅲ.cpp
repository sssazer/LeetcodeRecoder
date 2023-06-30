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
        return max(root->val + robRange(root->left, true, 0) + robRange(root->right, true, 0), robRange(root->left, false, 0) + robRange(root->right, false, 0));
    }
    int robRange(TreeNode* root, bool stoleParent, int res) {
        if (!root) {
            return 0;
        }
        if (stoleParent) {
            return robRange(root->left, false, res) + robRange(root->right, false, res);
        }
        else {
			return max(root->val + robRange(root->left, true, res) + robRange(root->right, true, res), robRange(root->left, false, res) + robRange(root->right, false, res));
        }
    }
};

int main() {

	return 0;
}