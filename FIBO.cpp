#include <bits/stdc++.h>
#define maxn 100007
using namespace std;

int n, k , a[100007], res;
long long s[100007];
bool f2[100007];
long long f1[100007];

void fibo(){
    f1[1]=1;
    f2[1]=true;
    f2[2]=true;
    f1[2]=1;
    for (int i = 3; i <= 30; i++){
        f1[i]=f1[i-1]+f1[i-2];
        f2[f1[i]]=true;
    }
}


int main(){
    freopen("FIBO.inp", "r", stdin);
    freopen("FIBO.out", "w", stdout);
    fibo();
    cin >> n >> k;
    for (int i = 1; i<=n ; i++){
        cin >> a[i];
    }
    for (int i = 1; i<= n ; i++){
        s[i]=s[i-1]+a[i];
    }
    for (int i = k; i<= n ; i++){
//        cout << s[i]-s[i-k] << '\n';
        if (f2[s[i]-s[i-k]])
            res++;
    }
    if (!res)
        cout << "-1";
    else
        cout << res;
    return 0;
}
