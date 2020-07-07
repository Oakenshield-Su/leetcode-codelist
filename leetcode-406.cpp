/**
 * 题解：重建身高队列（贪心）
 *
**/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    	int size = people.size();
    	sort(people.begin(), people.end(), compare);    //排序

    	vector<vector<int>> res;
    	for (int i = 0; i < size; ++i)
    		res.insert(res.begin()+people[i][1], people[i]);
    	return res;
    }

    static bool compare(const vector<int> &a, const vector<int>& b){
    	if (a[0] > b[0])     //身高降序
    		return true;
    	else if(a[0] == b[0] && a[1] < b[1]) //身高相同，索引
    		return true;
    	return false;
    }
};