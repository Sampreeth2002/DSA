/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* leftNode = root;
        while(leftNode!=NULL && leftNode->left!=NULL)
        {
            populate(leftNode);
            leftNode = leftNode->left;
        }
        
        return root;
    }
    
    void populate(Node* startNode)
    {
        Node* itr = startNode;
        while(itr!=NULL)
        {
            itr->left->next = itr->right;
            if(itr->next!=NULL)
            {
                itr->right->next = itr->next->left;
            }
            itr = itr->next;
        }
    }
    
    
    
};