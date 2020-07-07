/**
 * C++扩展脚手架
**/

/**
 * 判断元素是否存在
**/
bool contains(vector<T> v, T x)
{
    if (v.empty())
        return false;
    if (find(v.begin(), v.end(), x) != v.end())
        return true;
    else
        return false;
}