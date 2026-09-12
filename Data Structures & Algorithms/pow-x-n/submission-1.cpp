class Solution {
public:
    double myPow(double x, int n) {
        long long k=n;
        if(k<0){
            x=1/x;
            k=-k;
        }
        double ans=1;
        while(k>0){
            if(k%2==1){//odd power
            ans=ans*x;
            }

            x=x*x;
            k=k/2;
        }
        return ans;
    }
};
