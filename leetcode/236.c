#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int contain(TreeNode *root, TreeNode *item)
{
    if(root == NULL)
        return 0;
    if(root->val == item->val)
    {
        root -> left = NULL;
        root -> right = NULL;
        return 1;
    }
    else
        return contain(root->left, item) || contain(root->right, item);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(contain(p, q))
        return p;
    if(contain(q, p))
        return q;

    TreeNode* t = root;
    while(t != NULL)
    {
        if((contain(t->left, p) && contain(t->right, q)) || (contain(t->left, q) && contain(t->right, p)))
            break;

        if(contain(t->left, p) || contain(t->left, q)){
            t = t->left;
            continue;
        }

        if(contain(t->right, p) || contain(t->right, q)){
            t = t->right;
            continue;
        }

    }
    return t;
}
