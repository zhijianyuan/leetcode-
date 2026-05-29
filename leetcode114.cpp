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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            // 有左子树才需要处理
            if (curr->left) {
                // 1. 找左子树的"最右下角"节点
                TreeNode*p = curr->left;
                while(p->right != nullptr)
                    p = p->right; 
                // 2. 把原右子树接到这个节点的右边
                p->right = curr->right;
                // 3. 左子树移到右边
                curr->right = curr->left;
                // 4. 左指针置空
                curr->left = nullptr;
            }
            // 继续下一个
            curr = curr->right;
        }
    }
};
