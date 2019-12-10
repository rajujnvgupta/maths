/*
  fibosum spoj problem
  10/dec/2019
  @rajujnvgupta
  
 intput 
  3
  0 3
  3 5
  10 19
 output
  4
  10
  10857
*/


#include <iostream>
#define int long long int
using namespace std;
const int mod = 1e9+7;
class Mat{
    public:
    int **mat = new int*[2];  ///row defining
    Mat(){
        mat[0] = new int[2];    //col defining corresponding to every row
        mat[1] = new int[2];
    }
    Mat operator*(Mat const &a){
        Mat r;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    r.mat[i][j] += (mat[i][k]*(a.mat[k][j]))%mod;
                    r.mat[i][j] %= mod;
                }
            }
        }
        return r;
    }
};

int expo(int n, Mat a){
    Mat r;
    r.mat[0][0] = 1;
    r.mat[0][1] = 0;
    r.mat[1][0] = 0;
    r.mat[1][1] = 1;
    while(n > 0){
        if(n & 1){
            r = r * a;
        }
        a = a * a ;
        n /= 2;
    }
/*
     cout<<endl;
     for(int i = 0; i< 2; i++){
        for(int j = 0; j < 2;j++){
            cout<<r.mat[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
*/
    return r.mat[1][1];
}
int fibo(int n, int m, Mat a){
    int low = 0;
    int hi = 0;
    
    low = expo(n, a);
    hi = expo(m+1, a);
    hi = hi - low;
    while(hi < 0){
        hi = hi+mod;
    }
    return hi;
}

int32_t main() {
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        if(n > m){
            swap(n, m);
        }
        Mat a;
        a.mat[0][0] = 0;
        a.mat[0][1] = 1;
        a.mat[1][0] = 1;
        a.mat[1][1] = 1;
        cout<<fibo(n, m, a)<<'\n';
    }
    return 0;
}
