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
 * 341.扁平化迭代器
**/
class NestedIterator {
private:
    vector<int> res;
    vector<int>::iterator cur;

    //const成员函数内不允许修改成员变量  例如：res.push_back(xx)编译失败
    void dfs(const vector<NestedInteger> &nestedList){
        for(const auto &nestedInteger : nestedList){
            if(nestedInteger.isInteger()){
                res.push_back(nestedInteger.getInteger());
            }else{
                dfs(nestedInteger.getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        cur = res.begin();
    }
    
    //*cur++中*是取值标志（解引用）,cur++迭代器后移
    int next() {
        return *cur++;
    }
    
    bool hasNext() {
        return cur != res.end();
    }
};