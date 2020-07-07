/**
 * 题解：编辑距离
**/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1_len = word1.size();
        int word2_len = word2.size();

        vector<vector<int>> dp(word1_len+1, vector<int>(word2_len+1));

        //初始化dp数组 
        for (int i = 0; i <= word1_len; ++i) //word2空串到word1最小编辑距离
        	dp[i][0] = i;

        for (int j = 0; j <= word2_len; ++j) //word1空串到word2最小编辑距离
        	dp[0][j] = j;
        
        for (int i = 1; i <= word1_len; ++i){
        	for (int j = 1; j <= word2_len; ++j){
        		if (word1[i-1] == word2[j-1]){         //注意：word1[i-1]对应dp[i],因为dp[i]考虑空串问题
        			dp[i][j] = dp[i-1][j-1];
        		}else{
        			dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
        		}
        	}
        }
        return dp[word1_len][word2_len];
    }
};