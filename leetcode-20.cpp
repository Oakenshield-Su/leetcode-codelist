/**
 * 题解：有效括号
 * 
**/

class Solution {
public:
    bool isValid(string s) {
       stack<char> stack;
       for(int i = 0; i < s.size(); i++){
            switch(s[i]){
                case '(' :
                    stack.push(')');
                    break;
                case '[' :
                    stack.push(']');
                    break;
                case '{' :
                    stack.push('}');
                    break;
                default:
                    if(stack.size() == 0 || s[i] != stack.top())
                        return false;
                    stack.pop();
            }
        }
        return stack.size() == 0;
    }
};
