/**
 * 题解：单调递增序列
**/
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
    	string s = to_string(N);
    	int size = s.size();
        int index = size;
    	for (int i = size-1; i >= 1; --i)
    	{
    		if (s[i] < s[i-1])     //整数N从左到右递减
    		{
    			index = i;
    			s[i-1] -= 1;
    		}
    	}
        for (int i = index; i <= size-1; ++i)
            s[i] = '9';

    	return atoi(s.c_str());
    }
};