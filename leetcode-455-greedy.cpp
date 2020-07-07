class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
    	int g_size = g.size();
    	int s_size = s.size();
    	if (s_size == 0 || g_size == 0)
    		return 0;

    	sort(g.begin(), g.end());
    	sort(s.begin(), s.end());
    	int children = 0;
    	int cookie = 0;

    	while(children < g_size && cookie < s_size){      // 如果s[cookie]不能满足g[children]则不能满足g[children..g_size-1]
    		if (g[children] <= s[cookie])    //可以被满足
    		{
    			children++;
    		}
    		cookie++;       //每一个饼干尝试一次，如不满足则不再尝试
    	}
    	return children;
    }
};