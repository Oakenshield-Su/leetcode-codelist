/**
 * 题解：柠檬水找零
 * 描述：在柠檬水摊上，每一杯柠檬水的售价为 5 美元。
         顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
         每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。
         你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
         注意，一开始你手头没有任何零钱。如果你能给每位顾客正确找零，返回 true ，否则返回 false 。

 * 思想：1. 5美元时无需找零收入5美元一张,
         2. 10美元时找零5元收入10美元1张
         3. 20美元时找零15美元收入20美元一张
 *       综上所述：20美元并不参与找零,但是情况3有两种情况1.找零一张10元一张5元; 2.找零三张5元
 * 贪心策略： 针对情况3的两种情况优先使用情况1因为10元仅在情况3中有用
**/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
    	int five = 0;
    	int ten = 0;
    	int size = bills.size();

    	for (int i = 0; i < size; ++i)
    	{
    		switch(bills[i]){
    			case 5:{
    				five++;
    				break;
    			}
    			case 10:{
    				if (five == 0) 
    					return false;
    				ten++;
    				five--;
    				break;
    			}
    			case 20:{
    				if (ten > 0 && five > 0)
    				{
    					ten--;
    					five--;
    				}else if(five >= 3){
    					five -= 3;
    				}else{
    					return false;
    				}
    				break;
    			}
    		}
    	}

    	return true;
    }
};