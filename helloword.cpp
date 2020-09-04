//求兩個高精度正整數(x,y)相減的，如果x<y就交換位置,最后輸出的時候加-
#include<cstdio>
#include<cstring>
#include<cmath> 
#include<iostream>
using namespace std;
 
const int Max_n=10005;
typedef long long LL;
int a[Max_n],b[Max_n];
string c,d;

bool cmp(){
	if(c.length()!=d.length()) 
		return c.length()>d.length();
	return c>=d;
}

int main(){
    cin>>c>>d;
    int lenc=c.length();
    int lend=d.length();
    if(cmp()){
    	for(int i=0;i<lenc;i++)
    		a[i]=c[lenc-i-1]-'0';
    	for(int i=0;i<lend;i++)
    		b[i]=d[lend-i-1]-'0';
    }else{
    	for(int i=0;i<lend;i++)
    		a[i]=d[lend-i-1]-'0';
    	for(int i=0;i<lenc;i++)
    		b[i]=c[lenc-i-1]-'0';
    	cout<<"-"; 
    }
    int len=max(lenc,lend);
    for(int i=0;i<len;i++){
    	if(a[i]>=b[i]) a[i]-=b[i];
    	else{
    		a[i]=a[i]+10-b[i];
    		a[i+1]--;
    	}
    }
    int index=-1;
    for(int i=len-1;i>0;i--){//可以借助高精度/單精度里面的方法去除前導0(要比這個簡單很多).
    	if(a[i]){
    		index=i;
			break;
    	} 
    }
 	if(index!=-1){
 		for(int i=index;i>=0;i--)
 			cout<<a[i];
 		cout<<endl;
 	}else cout<<"0"<<endl;
    return 0;
}