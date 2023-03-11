// #include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef long long ll;
typedef pair<int,int>PII;
#define endl '\n'
#define io ios::sync_with_stdio(false),cin.tie(0)
const int INF = 0x3f3f3f3f;
// map<int,int>mp;
int n,m,k,T;
// int idx
const int N = 1e3;
int d[N],num[N];
int res[N][N];
vector<int>v;

int sum ;

void solve(){
//     freopen("i","r",stdin);
    cin >> n;
    for (int i = 1;i<=n;++i){
        cin >> num[i];
        // st.insert (num[i]);
        v.push_back(num[i]);
        sum+=num[i];
    }
    sort (v.begin(),v.end());
    int mx = *v.rbegin();
    int idx = 0;
    // int d = n;
    for (int i = 1;i<=mx;++i){
        while (i>v[idx]) ++idx;
        d[i] = max(n-idx,2);
    }
    for (int i =mx+1;i<=5e2;++i){
        d[i] = 2;
    }

    int pre = 0;
    int g_id = 0;
    for (int i = 1;i<=mx;++i){
        int cur = pre + 1 + d[i-1]*9;
        int fg = false;
        // for (int k = 1;k<=n;++k){
        //     if (num[k]>=i) fg++;
        // }
        // if (fg==1){
        //     cur++;
        // }
        for (int j = 1;j<=n;++j){
        

            if (num[j]>=i){
                if (!fg){
                    fg = true;
                    if (g_id == j){
                        cur++;
                    }
                }
                pre = cur;
                res[j][i] = cur++;
                g_id = j;
                // cur+=d/[i];
            }
        }
    }



    for (int i = 1;i<=n;++i){
        cout << "#"<<i<<endl;
        for (int j = 1;j<=num[i];++j){
            int s = res[i][j];
            for (int k=1;k<=10;++k){
                if (k!=1) cout <<" ";
                cout << s;
                s+=d[j];
            }
            cout << endl;

        }

    }

    

}

signed main(){
    
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    io;

    solve();
    return 0;
}