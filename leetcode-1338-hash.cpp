/**
 * 1337 数组大小减半
 * 思路：哈希表
 * 难点：哈希表Value有序化
 * 解决办法：将Value存入Vector，对Vector进行降序排列
**/
class Solution {
public:
    int minSetSize(vector<int>& arr) {
    	int n = arr.size();
    	map<int, int, greater<int>> map;

    	/*构造词频哈希表*/
    	for (int i = 0; i < n; ++i)     
    		map[arr[i]]++;

    	/*哈希表有序化*/
        vector<int> counts;
        for(auto &count : map){
            counts.push_back(count.second);
        }
        sort(counts.begin(), counts.end(), greater<int>());

        /*主逻辑*/
    	int target = n/2;
    	int ans = 0;
    	for (int i = 0; i < counts.size(); i++)
    	{
    		if (target > 0){
    			ans++;
    			target -= counts[i];
    		}	
    		else{
    			break;
    		}
    	}

    	return ans;

    }
};