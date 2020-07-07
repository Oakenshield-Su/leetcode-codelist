/**
 * 题解：判断子序列（贪心+双指针）
**/
class Solution {
public:
    bool isSubsequence(string s, string t) {
    	int s_size = s.size();
		int t_size = t.size();
		if (t_size < s_size)       //s长度大于t则必定不为子串
			return false;
		if (s_size == 0)
			return true;
		if (t_size == 0)
			return false;

		int index = 0;
		for (int i = 0; i < t_size; ++i)
		{
			if (t[i] == s[index])
				index++;
		}

		return index == s_size;
    }
};
