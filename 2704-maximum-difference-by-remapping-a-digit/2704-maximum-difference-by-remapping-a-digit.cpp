class Solution {
public:
    int minMaxDifference(int num) {
        vector<int>v;
        int n=num;
      while(n>0){
       int r=n%10;
       v.push_back(r);
       n/=10;
      }
      reverse(v.begin(),v.end());
      vector<int>vc=v;
      int ans=0;
      int k=-1;
      for(int i=0;i<v.size();i++){
        if(v[i]!=9 && (k==-1 || v[i]==k))
        {
            k=v[i];
            v[i]=9;
        }
      }
      k=-1;
      for(int i=0;i<vc.size();i++){
        if(vc[i]!=0 && (k==-1 || vc[i]==k))
        {
            k=vc[i];
            vc[i]=0;
        }
       ans=ans*10+(v[i]-vc[i]);
      }
    return ans;
    }
};