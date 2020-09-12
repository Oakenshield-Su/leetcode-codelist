/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 题解：本题的本质是宽度优先搜索+边缘探测
 */
class Solution {
public:
    vector<double> averageOfLevels1(TreeNode* root) {
    	queue<TreeNode *> q;
    	vector<double> ans;
    	TreeNode *cur;
    	long levelResults = 0;
    	long levelWidth = 0;
    	TreeNode *levelStart;
    	TreeNode *levelEnd;

    	//根节点入队，开启循环
    	q.push(root);      
    	ans.push_back(root->val);  
    	levelStart = root;
    	levelEnd = root;
    	while(!q.empty()){
    		cur = q.front();       
    		if (cur->left){                                          //左节点入队 
    			q.push(cur->left);
    			levelResults += cur->left->val; 
    			levelWidth++;                 
    		}
    		if (cur->right){                                         //右节点入队
    			q.push(cur->right);
    			levelResults += cur->right->val; 
    			levelWidth++;                
    		}
    		if (levelEnd == levelStart && levelWidth != 0)
    		{
    			ans.push_back(levelResults/(levelWidth*1.0));        //注意类型错误
    			levelResults = 0;                                    //置零
    			levelWidth = 0;
    			levelEnd = q.back();
    		}
    		q.pop();
            levelStart = q.front();                                  //levelStart指向下一个节点
    	}
    	return ans;
    }

    vector<double> averageOfLevels2(TreeNode* root){
    	queue<TreeNode *> q;
    	vector<double> ans;
    	TreeNode *cur;
    	int levelWidth;

    	q.push(root);      
    	while(!q.empty()){
    		levelWidth = q.size();                    //记录每层的宽度
    		double sum = 0.0;
    		for (int i = 0; i < levelWidth; ++i)      //遍历当前节点的下一层
    		{
    			cur = q.front();
    			q.pop();                              //注：front和pop联合在Java中等同于poll
    			sum += cur->val;
    			if (cur->left) q.push(cur->left);
    			if (cur->right) q.push(cur->right);
    		}
    		ans.push_back(sum / levelWidth);          //结果集
    	}
    	return ans;
    }
};