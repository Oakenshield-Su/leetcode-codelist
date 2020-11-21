/**
 * 1402.做菜顺序
 * 喜爱系数= time[i]*satisfaction[i]， 即由做菜顺序和喜爱程度有关
 * 目标：最大化喜爱系数
 * 证明：先选择一个最喜欢的菜s0，如果s0<0，则不做菜
 *       如果s0>0，再考虑次喜欢的菜s1，这是如果想要喜爱系数增大则s1 + 2*s0 > s0从而 s1 + s0 >0依次类推故循环条件确定
 * 前缀和计算喜爱系数(倒序累加)，每加一次前面的菜的time增大1
 **/
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());  //倒序排序
        int res = 0;

        int presum = 0;
        for (int i = 0; i < n && (presum + satisfaction[i])> 0; i++)
        {
            presum += satisfaction[i];
            res += presum;
        }
        return res;
    }
};