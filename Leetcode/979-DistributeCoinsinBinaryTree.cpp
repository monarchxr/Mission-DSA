/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        moves = 0;
        dfs(root);
        return moves;
    }

private:
    int moves;
    int dfs(TreeNode* curr){
        if(curr == NULL) return 0;

        int leftc = dfs(curr->left);
        int rightc = dfs(curr->right);

        moves += abs(leftc) + abs(rightc);

        return(curr->val)+leftc+rightc-1;
    }
};