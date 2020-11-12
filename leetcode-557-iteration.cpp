class Solution {
public:
    string reverseWords(string s) {
        auto section_start = s.begin();
        
        for(auto section_end = s.begin(); section_end != s.end(); section_end++){
            if(*section_end == ' '){
                reverse(section_start, section_end); //不可使用section_end - 1， 因为迭代器指向目标值的下一个值
                section_start = section_end +1;
            }
        }
        reverse(section_start, s.end());
        return s;
    }
};