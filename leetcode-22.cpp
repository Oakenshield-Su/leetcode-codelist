/**
 * 括号生成（回溯法）
**/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> parenthesis;
    	generateParenthesisDFS(n, n, "", parenthesis);
    	return parenthesis;
    }

    void generateParenthesisDFS(int left, int right, string path, vector<string> &paths){     //注意vector &引用
    	if (left > right)         // 约束条件：左括号数量小于等于右括号
    		return;
    	if (left == 0 && right == 0)     // 回溯结束条件
    		paths.push_back(path);
    	else{
    		if (left > 0)
    			generateParenthesisDFS(left-1, right, path+'(', paths);     //左递归
    		if (right > 0)
    			generateParenthesisDFS(left, right-1, path+')', paths);     //右递归
    	}
    }

};