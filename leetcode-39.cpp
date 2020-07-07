class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        std::sort(candidates.begin(), candidates.end());   // candidates排序便于剪枝
        combinationSumDFS(res, path, candidates, target, 0);
        return res;
    }

    void combinationSumDFS(vector<vector<int>>& res, vector<int>& path, vector<int>& candidates, int target, int begin){
    	if (target < 0)
    		return;
    	if (target == 0)
    	{
    		res.push_back(path);
    		return;
    	}

    	else{
    		for (int i = begin; i < candidates.size() && target >= candidates[i]; ++i)
    		{
    			path.push_back(candidates[i]);
    			combinationSumDFS(res, path, candidates, target - candidates[i], i); //i:避免倒序回溯即3->2
    			path.pop_back();
    		}
    	}

    }
};