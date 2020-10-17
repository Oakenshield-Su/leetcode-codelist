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

 * 思路：广度优先遍历
**/
class Solution {
public:
    Node* connect(Node* root) {
    	if (root == nullptr) return root;
        queue<int> queue;
        queue.push(root->val);
        
        while(!queue.empty()){
        	Node* pre = nullptr;
        	int n = queue.size();
        	for (int i = 1; i <= n; ++i)
        	{
        		Node* cur = queue.front();
        		queue.pop();
        		if (cur->left)
        			queue.push(cur->left);
        		if (cur->right)
        			queue.push(cur->right);
        		if (pre != nullptr)
        			pre->next = cur;
        		pre = cur;
        	}
        	pre->next = nullptr;
        }
        return root;
    }
};