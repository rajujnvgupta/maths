/*
    ans = ncr %p 

*/



#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long int 
using namespace std;

int expo(int r){

    int mod = MOD-2;
    int res = 1;
    int a = r;
    while(mod>0){

        if(mod&1){
            res = res*a;
            res %= MOD;
        }
        a = a*a;
        a %= MOD;
        mod /= 2;
    }
    return res;
}

int solve(int n, int r){

    vector<int>fact(n+1, 1);
    for(int i = 2; i <= n; i++){
        fact[i] = fact[i-1]*i;
        fact[i] %= MOD;
    }
    
    ///cout<<fact[n]<<' '<<fact[r]<<' '<<fact[n-r]<<'\n';
    //inverse of r!
    int exp1 = expo(fact[r]);
    //inverse of n-r!
    int exp2 = expo(fact[n-r]);
    ///cout<<exp1<<' '<<exp2<<'\n';
    int ans = 0;
    ans = exp1*exp2;
    ans %= MOD;
    ans *= fact[n];
    ans %= MOD;
    return ans;
}

int32_t main(){

    int n, r;
    cin>>n>>r;
    cout<<solve(n, r)<<endl;
    return 0;
}

