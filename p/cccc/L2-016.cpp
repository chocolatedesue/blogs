#include<bits/stdc++.h>

const int N =  1e6+10;
using namespace std;
int sx[N];
map<int,int>fa,ma;



int check (int a,int b,int step){
//	cout << a<<" "<<b<<"--"<<step<<endl;
	if (step>5) {
		return 1;
	}
	
	if (a==-1 || b==-1 || a==0 || b==0)
	return 1;
	if (a==b) return 0;
	return check (fa[a],fa[b],step+1) &&
	 check (fa[a],ma[b],step+1) && 
	 check (ma[a],ma[b],step+1) && 
	 check(ma[a],fa[b],step+1);
	
}

int n,k;

int main(){
// 	freopen("in.txt","r",stdin);
	cin >> n;
	for (int i = 1;i<=n;++i){
		int a,c,d;
		char s;
		cin >>a>>s>>c>>d;
		s=='M'?sx[a]=1:sx[a]=2;
		fa[a] = c, ma[a] =d; 
        if (c!=-1) sx[c] = 1;
        if (d!=-1) sx[d] = 2;
				
	}
	
	cin >> k;
	int a,b;
	while (k--){
		cin >> a>>b;
		if (sx[a]==sx[b]){
			cout <<"Never Mind"<<endl; 
		}
		else 
		if (check(a,b,1)){
			cout << "Yes"<<endl;
//				break;
		}
		else{
			cout << "No"<<endl;
//			break;
		}
		
	}
	
	return 0;
}