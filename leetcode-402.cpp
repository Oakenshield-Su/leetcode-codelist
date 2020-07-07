/**
 * 题解：移掉K位数（贪心）
 * 目标：构造单增栈
**/
class Solution {
public:
    string removeKdigits(string num, int k) {
    	stack<char> c;
    	string res;

    	for (int i = 0; i < num.size(); ++i)       //构造单增栈
    	{
    		while(!c.empty() && k > 0 && c.top() > num[i]){  //出栈条件
    			k--;
    			c.pop();
    		}
    		c.push(num[i]);      
    	}

    	//情况1：构造完单增栈后k>0
    	for (int i = k; i > 0; --i)
    		c.pop();

    	//情况2：去除前导0
    	while(!c.empty()){      //构造结果串（倒序）
    		res += c.top();
    		c.pop();
    	}
    	while(!res.empty() && res[res.size()-1] == '0'){
    		res.pop_back();
    	}
    	reverse(res.begin(), res.end());
    	return res.size() == 0 ? "0" : res;
    }
};