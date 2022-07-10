// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    
    class node{
        public:
        int key;
        int val;
        node* right;
        node* left;
        node(int _key,int _val)
        {
            key = _key;
            val = _val;
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int cap;
    unordered_map<int,node*> mp;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int capacity)
    {
        // code here
        cap = capacity;
        head->right = tail;
        tail->left = head;
    }
    
    void addNode(node* newNode)
    {
        node* temp = head->right;
        newNode->right = temp;
        newNode->left = head;
        head->right =  newNode;
        temp->left = newNode;
    }
    
    void deleteNode(node* delNode)
    {
        node* prevNode = delNode->left;
        node* nextNode = delNode->right;
        prevNode->right = nextNode;
        nextNode->left = prevNode;
    }
    
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(mp.find(key)!=mp.end())
        {
            node* ans = mp[key];
            int res = ans->val;
            mp.erase(key);
            deleteNode(ans);
            addNode(ans);
            mp[key] = head->right;
            return res;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
         if(mp.find(key)!=mp.end())
         {
             node* existingNode = mp[key];
             mp.erase(key);
             deleteNode(existingNode);
         }
         if(mp.size()==cap)
         {
             mp.erase(tail->left->key);
             deleteNode(tail->left);
         }
         
         addNode(new node(key,value));
         mp[key] = head->right;
         
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends