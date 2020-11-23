/**
 * 763. 划分字母区间
 **/
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.length();
        vector<int> ans;
        if (n == 0) return ans;     
        unordered_map<char, int> max_distance;
        for (int i = 0; i < n; i++)      //从左到右记录每个元素出现的最远位置
            max_distance[S[i]] = i;    
        
        int substr_start = 0;
        int substr_end = 0;  //子串尾
        for (int i = 0; i < n; i++)
        {
            substr_end = max(substr_end, max_distance[S[i]]);    //是否可以更新尾指针
            if (substr_end == i){                    //当前子串无法再扩充
                ans.push_back(substr_end - substr_start + 1);
                substr_start = substr_end + 1;       //下一个子串头
            }
        }
        return ans;
    }

    //优化速度版:<char, int>可以使用int代替map,速度更快
    vector<int> partitionLabels(string S) {
        int n = S.length();
        vector<int> ans;
        if (n == 0) return ans;     
        int max_distance[26];
        for (int i = 0; i < n; i++)      //从左到右记录每个元素出现的最远位置
            max_distance[S[i] - 'a'] = i;    
        
        int substr_start = 0;
        int substr_end = 0;  //子串尾
        for (int i = 0; i < n; i++)
        {
            substr_end = max(substr_end, max_distance[S[i] - 'a']);    //是否可以更新尾指针
            if (substr_end == i){                    //当前子串无法再扩充
                ans.push_back(substr_end - substr_start + 1);
                substr_start = substr_end + 1;       //下一个子串头
            }
        }
        return ans;
    }
};