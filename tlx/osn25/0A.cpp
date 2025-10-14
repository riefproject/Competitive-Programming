#include <stdio.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    long long arr[n];

    for(int i = 0; i < n; i++) scanf("%lld", &arr[i]);
    for(int i = n - 1; i >= 0; i--) printf("%lld\n", arr[i]);

    return 0;
}