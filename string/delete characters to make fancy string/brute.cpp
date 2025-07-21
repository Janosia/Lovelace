class Solution {
public:
    string makeFancyString(string s) {
        string out = "";
        int i =0, j = 1, len = s.size();
        while(j<len){
            if(s[i] != s[j]){
                out+=s[i];
                i++;
                j++;
            } else {
                while(s[i] ==  s[j]) j++;
                
                while(j-i >= 3) i++;
                
                while(i != j)  out +=s[i++];
                
                j++;
            }
        }
        if(i < len) out += s[i];
        return out;
    }
};