#include<stdio.h>
#include<math.h>
void isarmstrong(int n){
    int rem;
    int sum=0;
    int temp=n;
    int len=0;
    while (temp != 0) {
        len++;
        temp = temp / 10;
    }
    temp=n;
    while(temp!=0){
        rem=temp%10;
        sum+=pow(rem,len);
        temp=temp/10;
    }
    if(sum==n){
        printf("is armstrong");
    }
    else{
        printf("not armstrong");
    }
}
int main(){
    int n=153;
    isarmstrong(n);
}