class Solution {
public:
#define ll long long int
const ll mod=1e9+7;
    ll myPow(ll a, ll b) {
        ll res = 1;
        a %= mod;

        while (b > 0) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        ll x=(n+1)/2;
        ll y=n/2;
        ll ans=(myPow(5,x)%mod*myPow(4,y)%mod)%mod;
        return ans;
    }
};