class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>V1(256,-1);
        vector<int>V2(256, -1);
        int len = s.length();
        if(len != t.length()){
            return false;
        }
        for(int i = 0; i <len; i++){
            if(V1[s[i]] != V2[t[i]]){
                return false;
            }
             V1[s[i]]=i + 1;
            V2[t[i]]=i + 1;
            
        }

      
     return true; 
    }
};