#include<bits/stdc++.h>
#define Mod 1000000007
#define int long
using namespace std;

int extendexdEuclidian(int a, int b, int &x, int &y){

    if(b == 0){
        x = 1;
        y = 0;
        return a; ///where this x is used
    }
    
    extendexdEuclidian(b, a%b, x, y);
    int temp = x;
    x = y;
    y = temp - (a/b)*y;
}

int32_t main() {
    int a;
    cin>>a;
    bool isPossible = isPossibleModuloInverse(a, Mod);
    
    if(isPossible){
        int x = 0, y = 0;
        int ans = extendexdEuclidian(a, Mod, x, y);
        ///this print modulo inverse
        ///for negative value of inverse
        x = (x + Mod)%Mod; /// to make is positive
        cout<<x<<endl;
    }

    return 0;
}

