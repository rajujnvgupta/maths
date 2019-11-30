#include <iostream>
#define int long long int
using namespace std;

///extended eucledian method to find moludo multiplicative inverse
///calculating moludo multiplicative inverse 

void _gcd(int a, int b, int &x, int &y){

    if(b == 0){
        x = 1;
        y = 0;
        return;
    }
    _gcd(b, a%b, x, y);
    int temp = x;
    x = y;
    y = (temp - ((a/b)*y));
    ///this is final answer
    //return x;
}

int inverse(int a, int b){
    int x, y;
    _gcd(a, b, x, y);
    ///cout<<((x+b)%b)<<endl;
    ///cout<<x<<'\n';
    return (x+b)%b;
}

int solve(int *n, int *r, int *p, int k, int product){
    int ans = 0;
    ///final value of x in chineese remainder theorem
    for(int i = 0; i < k; i++){
        ans += (r[i]*p[i]*inverse(p[i], n[i]));
        ///ans %= product;
    }
    return ans%product;
}

int32_t main(){
    
    int k;
    cin>>k;
    int n[k];
    int product = 1;
    //storing nums
    for(int i = 0; i < k; i++){
        cin>>n[i];
        product *= n[i];
    }

    int r[k];
    ///storing remainder
    for(int i = 0; i < k; i++){
        cin>>r[i];
    }
    ///storing ppi
    int pp[k];
    for(int i = 0; i < k; i++){
        pp[i] = product/n[i];
    }
    cout<<solve(n, r, pp, k, product)<<'\n';
    return 0;
}
