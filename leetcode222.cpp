
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
    int getDepth(TreeNode* node){
        if(node == nullptr)
            return 0;
        int i = 0;
        TreeNode* p = node;
        while(p != nullptr){
            p = p->left;
            i++;
        }
        return i;
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int l = getDepth(root->left);
        int r = getDepth(root->right);
        if(l==r)
            return (1<<l)+countNodes(root->right);
        else
            return (1<<r)+countNodes(root->left);
        
    }
};
/*
 * 核心思路：利用完全二叉树的性质，每次递归只走一棵子树，O(log n * log n)
 *
 * 分别计算 root 左、右子树的最左深度 l 和 r：
 *   - l == r → 左子树是满二叉树，节点数 = 2^l - 1，加上根节点，再递归右子树
 *   - l != r → 右子树是满二叉树，节点数 = 2^r - 1，加上根节点，再递归左子树
 *
 * 满二叉树节点数公式：2^h - 1，代码中用位运算 1 << h 表示 2^h
 */