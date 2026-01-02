class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
          if(costBoth<=(cost1+cost2))
          {
            ans+=min(1LL*need1,1LL*need2)*1LL*costBoth;
             if(1LL*need1<=1LL*need2)
             {
             need2-=1LL*need1;
             need1=0;
             }
             else
             {
                need1-=1LL*need2;
                need2=0;
             }
             ans+=min((1LL*need1*1LL*cost1)+(1LL*need2*1LL*cost2),(1LL*need1+1LL*need2)*1LL*costBoth);

          }
          else
          ans+=(1LL*need1*1LL*cost1)+(1LL*need2*1LL*cost2);
          return ans;
    }
};