class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root.left,root.right);
    }
    bool isMirror(a, b):{
        if (a==null && b==null) → true        // 都空，对称
        if (a==null || b==null) → false       // 一个空一个不空，不对称
        return a.val == b.val                 // 根值相等
            && isMirror(a.left, b.right)      // 交错比较
            && isMirror(a.right, b.left)
    }
};