/**
 * 题解：单词拆分
 * 不足：string函数不熟悉，一味追求暴力
**/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    	int s_size = s.size();
    	vector<bool> dp(s_size+1, false);
    	set<string> word_dict;
    	for (int i = 0; i < wordDict.size(); ++i)
    		word_dict.insert(wordDict[i]);

    	dp[0] = true;       //长度为0子串默认为true
    	for (int r = 1; r <= s_size; r++){        //子串长度从1依次递增
    		for (int l = 0; l < r; l++){          //子串从0到r-1探测
    			if (dp[l] && word_dict.count(s.substr(l, r-l)) == 1)
    			{
    				dp[r] = true;
    				break;
    			}
    		}
    	}

    	return dp[s_size];
    }
};	