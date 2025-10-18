#include <stdio.h>

int main(){
    int n; scanf("%d", &n);
    printf("%d\n", n - 1);
    for(int i = 1; i < n - 2; i++) printf("1 ");
    printf("2");

    return 0;
}