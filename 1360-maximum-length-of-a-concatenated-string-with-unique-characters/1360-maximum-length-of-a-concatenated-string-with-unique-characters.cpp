class Solution {
public:
bool hasDuplicate(string &s1,string &s2){
    vector<int>arr(26,0);
    for(char c:s1){
        if(arr[c-'a'])
        return true;
        arr[c-'a']++;
    }
    for(char c:s2){
        if(arr[c-'a']!=0)
        return true;
        arr[c-'a']++;
    }
    return false;
}
    int solve(string &prev,vector<string>& arr,int i){
          if(i==arr.size()){
            return 0;
          }
          int ex=0,sk=0,tk=0;
          if(hasDuplicate(prev,arr[i])){
              ex=solve(prev,arr,i+1);
          }
          else{
            string s=prev+arr[i];
            tk=arr[i].length()+solve(s,arr,i+1);
            sk=solve(prev,arr,i+1);
          }
          return max({sk,tk,ex});
    }
    int maxLength(vector<string>& arr) {
        string s="";
        int ans=solve(s,arr,0);
        return ans;
    }
};