/**
 * 全排列
**/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> visited(nums.size(), false); 
        permuteDFS(result, nums, path, visited);
        return result;
    }

    void permuteDFS(vector<vector<int>> &paths, vector<int> &nums, vector<int> &path, vector<bool> &visited){
    	if(!contains(visited, false)){    //判断是否存在为访问节点
    		paths.push_back(path);
    		return;
    	}
    	else{
    		for (int i = 0; i < nums.size(); ++i)      //深度优先遍历未访问节点
    		{
    			if(!visited[i]){         
    				visited[i] = true;
    				path.push_back(nums[i]);        
    				permuteDFS(paths, nums, path, visited);
    				path.pop_back();               //返回原本状态，确保其他分支仍可正常使用
    				visited[i] = false;
    			}
    		}
    	}
    }

    bool contains(vector<bool> v, bool x)
	{
      if (v.empty())
           return false;
      if (find(v.begin(), v.end(), x) != v.end())
           return true;
      else
           return false;
	}
};