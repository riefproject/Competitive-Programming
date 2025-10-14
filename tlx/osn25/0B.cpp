#include <stdio.h>
using namespace std;

int lcm(int a, int b){
    return (a * b) / __gcd(a, b);
}

int main(){
    int n; scanf("%d", &n);
    long long arr[n];
    int ans = 0;
    
    for(int i = 0; i < n; i++) scanf("%lld", &arr[i]);
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            if((arr[i-1] ^ arr[j]) > lcm(arr[i-1], arr[j])) ans++;
    
    printf("%d\n", ans);
    return 0;
}