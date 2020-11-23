/**
 * 1111. 有效括号的嵌套深度
 **/
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        vector<int> ans;

        //为了使深度最小将深度等分给A，B即奇数深度给A，偶数深度给B(同时方便记录0和1)
        int deepth = 0;
        for(char &c : seq){  //使用引用使内存减少
            if(c == '('){
                deepth++;    //模拟左括号入栈，深度加1
                ans.push_back(deepth & 1);
            }else{          
                ans.push_back(deepth & 1);
                deepth--;   //模拟左括号出栈，深度减1
            }
        }
        return ans;
    }
};