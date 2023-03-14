#include<bits/stdc++.h>

using namespace std;

int n,m,k;
const int N = 1e3+30;
// 模拟题 盒子-》stack , 松针 vector ， 按照题目顺序来搞就行
int main (){
    
    cin >> n>>m>>k;
    stack<int>stk;
    vector<int>q[N];
    int idx = 0;
    int t ;
    int mark = 0;
    for (int i = 1;i<=n;++i){
    	if (!mark)
         cin >> t;
         else mark = 0;
        if (q[idx].size()==k)idx++;
        while (stk.size() && 
               (q[idx].empty() ||
                stk.top()<=q[idx].back())){
            q[idx].push_back(stk.top());stk.pop();
            if (q[idx].size()==k){
                idx++;
            }
        }
        
        if (q[idx].empty() || q[idx].back()>=t){
            q[idx].push_back(t);
//             if (q[idx].size()
        }
        else if (stk.size()<m){
            stk.push(t);
        }
        else 
        {
        	i--;
        	mark = 1;
            idx++;
        }
    }
    
    while (stk.size()){
        if (q[idx].size()<k &&( q[idx].empty() || q[idx].back()>=stk.top())){
             q[idx].push_back(stk.top());stk.pop();
          
        }
        
        else idx ++ ;
        
    }
    
    for (int i = 0;i<=idx;++i){
        for (int j = 0;j<q[i].size();++j){
            if (j) cout <<" ";
            cout << q[i][j];
        }
        cout << endl;
    }
    
    
    return 0;
}