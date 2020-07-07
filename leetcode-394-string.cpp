class Solution {
public:
    string decodeString(string s) {
    	int n = s.size();
    	stack<int> numstack;
    	stack<string> strstack;

    	string cur = "";
    	string result = "";
    	int num = 0;
    	for (int i = 0; i < n; ++i)
    	{
    		if (s[i] >= '0' && s[i] <= '9')    //字符串重复次数
    		{
    			num = 10 * num + s[i] - '0'; 
    		}else if(s[i] == '['){
    			strstack.push(cur);
                numstack.push(num);      //上一轮结果
    			num = 0;      //重置
    			cur.clear();
    		}else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
    			cur += s[i];
    		}else if(s[i] == ']'){
    			int k = numstack.top();
    			for (int j = 0; j < k; ++j)
    				strstack.top() += cur;
    			cur = strstack.top();
    			strstack.pop();
    			numstack.pop();
    		}
    	}
    	result = result + cur;
    	return result;
    }
};