#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;


/**
 * C++扩展脚手架
**/

/**
 * 判断元素是否存在
**/
template<class T>
bool contains(vector<T> v, T x)
{
    if (v.empty())
        return false;
    if (find(v.begin(), v.end(), x) != v.end())
        return true;
    else
        return false;
}

int main(){

    std::cout<<"hello world"<<endl;
    return 0;
}