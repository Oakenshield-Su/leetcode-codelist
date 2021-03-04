class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        int total_money = 0;

        for(const vector<int> &account : accounts){
            for(const int &bank :account)
                total_money += bank;
            ans = max(ans, total_money);
            total_money = 0;
        }

        return ans;
    }
};