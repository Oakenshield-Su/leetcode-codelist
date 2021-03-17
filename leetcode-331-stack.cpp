#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * 331.验证二叉树的前序序列化
**/
class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<char> stack;
        int n = preorder.length();
        int m = 0;

        for(int i = 0; i < n; i++){
            if(preorder[i] == ',')
                continue;
            
            //数字可能有多位
            while(isdigit(preorder[i])){
                i++;
            }
            if(i-1 >= 0 && isdigit(preorder[i-1]))
                i--;
            
            stack.push_back(preorder[i]);
            m = stack.size();
            while(m >= 3 && stack[m-1] == '#' && stack[m-2] == '#' && stack[m-3] != '#'){
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.push_back('#');
                m = stack.size();
            }
        }

        return stack[0] == '#' && stack.size() == 1;
    }
};