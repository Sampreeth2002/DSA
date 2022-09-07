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
    
    TreeNode* fun(string &str,TreeNode* root)
    {
        TreeNode* left;
        TreeNode* right;
        if(root==NULL) 
        {
            
            return NULL;
        }
        str += to_string(root->val);
        // cout
        if(!root->left && !root->right)
        {
            // str +=')';
            return root;
        }
        // str+='(';
        if(root->left)
        {
            str+='(';
            left = fun(str,root->left);
            str+=')';
        }
        else
        {
            str+="()";
        }
        if(root->right)
        {
            str+='(';
            right = fun(str,root->right);
            str+=')';
            // str+=')';
        }
        // str+=')';
        
        return root;
        
    }
    
    string tree2str(TreeNode* root) {
        string str="";
        // str += root->val + '0';
        if(root==NULL) return "";
        TreeNode* ans = fun(str,root);
        return str;
    }
};