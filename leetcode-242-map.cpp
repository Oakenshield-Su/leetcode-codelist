class Solution {
public:
    //map版本
    bool isAnagram(string s, string t) {
        unordered_map<char, int> word_count;

        for(int i = 0; i < s.length(); i++)
            word_count[s[i]]++;

        for(int i = 0; i < t.length(); i++)
            word_count[t[i]]--;

        for(auto it = word_count.begin(); it != word_count.end(); it++){
            if(it->second != 0)
                return false;
        }
        return true;
    }

    //map改进版
    bool isAnagram(string s, string t)
        int num[26]={0}; 
        if(s.length()!=t.length())
            return false;
        for(int i=0;s[i]!='\0';i++){
            num[s[i]-'a']++;
            num[t[i]-'a']--;
           
        }
        for(int i=0;i<26;i++)
            if(num[i]!=0)
                return false;
        return true;
    }
};