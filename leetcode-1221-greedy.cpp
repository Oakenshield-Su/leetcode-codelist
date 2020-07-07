class Solution {
public:
    int balancedStringSplit(string s) {
    	int n = s.size();
    	int res = 0;

    	int balance = 0;
    	for (int i = 0; i < n; ++i)
    	{
    		if (s[i] == 'R')
    			balance++;
    		if (s[i] == 'L')
    			balance--;
    		if (balance == 0)
    			res++;
    	}
    	return res;
    }
};