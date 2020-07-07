/**
 * 题解：完全平方数（贪心算法）
**/
class Solution {
public:
    int numSquares(int n) {
    	vector<int> square_nums;
        for (int i = 1; i*i <= n; ++i)
            square_nums.push_back(i*i);

        set<int> queue;
        queue.insert(n);

        int level = 0;
        while(queue.size()>0){
            level++;
            set<int> new_queue;

            for(auto remainder : queue){
                for(auto squareNum : square_nums){
                    if (remainder == squareNum)
                        return level;
                    else if (remainder < squareNum)
                        break;
                    else
                        new_queue.insert(remainder-squareNum);
                }
            }
            queue = new_queue;     //指向下一层
        }
        return level;
    }
};