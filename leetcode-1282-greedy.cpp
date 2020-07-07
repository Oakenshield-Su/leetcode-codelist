class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    	// 构建groupSizes与索引i之间的映射
    	int n = groupSizes.size();
    	vector<vector<int>> res;
    	unordered_map<int, vector<int>> groups;
    	for (int i = 0; i < n; ++i)
    			groups[groupSizes[i]].push_back(i);
    	

    	for (auto it = groups.begin(); it != groups.end(); ++it)
    	{
    		int groupSize = it->first;
    		vector<int> users = it->second;
    		for (auto i = users.begin(); i != users.end(); i += groupSize)
    		{
    			vector<int> ans(i, i+groupSize);
    			res.push_back(ans);
    		}
    	}
    	return res;
    }
};