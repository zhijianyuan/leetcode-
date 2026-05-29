/**
 * 426. 将二叉搜索树转化为排序的双向链表
 *
 * 将一个二叉搜索树（BST）原地转化为一个已排序的循环双向链表。
 * 转换规则：
 *   - 节点的 left 指针指向前驱节点
 *   - 节点的 right 指针指向后继节点
 *   - 链表必须按中序遍历的顺序排序
 *   - 链表是循环的：最小节点的 left 指向最大节点，最大节点的 right 指向最小节点
 *
 * 返回：链表的最小值节点（即 BST 的最左叶子节点）
 *
 * 约束：不能创建新节点，只能修改节点的 left/right 指针
 */

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return root;
        inorder(root);
        head->left = prev;
        prev->right = head;
        return head;
    }

private:
    void inorder(Node* cur) {
        if(cur){
            inorder(cur->left);
            if(prev == nullptr)
                head = cur;
            else
                prev->right = cur;
            cur->left = prev;   
            prev = cur;
            inorder(cur->right);
        }
    }
    Node* head = nullptr;  // 链表头（最小值节点）
    Node* prev = nullptr;  // 中序遍历的前驱节点
};
