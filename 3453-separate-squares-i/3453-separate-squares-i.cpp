class Solution {
public:
    const double EPS = 1e-5;
    double separateSquares(vector<vector<int>>& squares) 
    {
        int n = squares.size();

        int mn = squares[0][1], mx = squares[0][1];

        for(vector<int> &v: squares)
        {
            mn = min(mn,v[1]);
            mx = max(mx,v[1] + v[2]);

        }

        double low = (double)mn, high = (double)mx;

        while(high - low > EPS)
        {
            double mid = (double)(low + high)/2.0;

            double ans = 0.0;

            for(vector<int> &v: squares) 
            {
                double a = (double)v[0];
                double b = (double)v[1];
                double c = (double)v[2];

                if(mid <= b)
                {
                    ans = ans + (double)c*c;
                }
                else if(mid <= b + c)
                {
                    double l1 = mid - b;
                    double l2 = b + c - mid;

                    ans = ans + c * l2 - c * l1;

                }
                else  
                    ans = ans - (double)c*c;

            }

          
            if (ans < 0 || ans < EPS)
                high = mid;
            else 
                low = mid;

        }

        return low;
        
    }
};