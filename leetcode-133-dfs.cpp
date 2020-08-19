/**
 * 题解：克隆图
 * time: 2020/08/12
 * autor: Neo
 * core:dfs
 * problem: how to store visited elem
 * solution:每个节点的值都和它的索引相同。例如，第一个节点值为 1（val = 1），第二个节点值为 2（val = 2），以此类推。
 * 所以使用一个map存储节点值和访问标记
**/
class Solution {
public:
    Node* visited[101] = {nullptr};
    
    Node* cloneGraph(Node* node) {
        if (node == nullptr) 
            return node;
        int size = node->neighbors.size();
        Node *root = new Node(node->val, vector<Node*> {});
        visited[node->val] = root;
        for (int i = 0; i < size; i++) {
            if (!visited[node->neighbors[i]->val])
                root->neighbors.push_back(cloneGraph(node->neighbors[i]));
            else
                root->neighbors.push_back(visited[node->neighbors[i]->val]);    //注：无向图两个相邻节点互相连接
        }
        return root;
    }
};