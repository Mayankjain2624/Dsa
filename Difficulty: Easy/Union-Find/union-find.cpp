// User function Template for C++

class Solution {
  public:
    // Function to merge two nodes a and b.
    int find(int x,int par[]){
        if(par[x]==x)
        return x;
        else
        return par[x]=find(par[x],par);
    }
    void union_(int a, int b, int par[], int rank1[]) {
        // code here
        int upa=find(a,par);
        int upb=find(b,par);
        
        if(rank1[upa]<rank1[upb])
        par[upa]=upb;
        else
        par[upb]=par[upa];
    }

    // Function to check whether 2 nodes are connected or not.
    bool isConnected(int x, int y, int par[], int rank1[]) {
        if(find(x,par)==find(y,par))
        return true;
        return false;
        // code here
    }
};