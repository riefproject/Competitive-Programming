#include <stdio.h>

int tiga(int n){
    if (n <= 1) return 1;
    else if (n % 3 == 0) return tiga(n - 1) + tiga(n - 3);
    else if (n % 3 == 1) return tiga(n - 2);
    else return tiga(n - 3);
}

int main(){
    // Soal No. 27
    // berapa banyak dari 2025 pemanggilan yang menghasilkan nilai 1?

    int count = 0;
    for (int i = 1; i <= 2025; i++) if (tiga(i) == 1) count++;
    printf("Jumlah pemanggilan yang menghasilkan 1: %d\n", count);
    
    return 0;
}