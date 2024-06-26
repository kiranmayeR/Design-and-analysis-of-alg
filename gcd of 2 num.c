#include<stdio.h>
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    int a,b;
    a=9;
    b=6;
    int ans=gcd(b,a);
    printf("%d",ans);
}