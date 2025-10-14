#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    
    if(n == 1){
        printf("0\n");
        return 0;
    }
    
    int ans = 0;
    int temp = n - 1;
    while(temp > 0){
        temp >>= 1;
        ans++;
    }
    
    printf("%d\n", ans);
    return 0;
}