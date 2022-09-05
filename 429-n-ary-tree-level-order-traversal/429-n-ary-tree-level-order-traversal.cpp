/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        if(root==NULL) return v;
        queue<Node*>q;
        q.push(root);
        // v.push_back({root->val});
        
        while(!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            for(int i=0;i<n;i++)
            {
                Node* topNode = q.front();
                q.pop();
                temp.push_back(topNode->val);
                for(auto childernNode : topNode->children)
                {
                    // temp.push_back(childernNode->val);
                    q.push(childernNode);
                }
            }
            v.push_back(temp);
        }
        // v.pop_back();
        return v;
        
        
    }
};