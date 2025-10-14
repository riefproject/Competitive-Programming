#include <stdio.h>

int tiga(int n){
    if (n <= 1) return 1;
    else if (n % 3 == 0) return tiga(n - 1) + tiga(n - 3);
    else if (n % 3 == 1) return tiga(n - 2);
    else return tiga(n - 3);
}

int main(){
    // Soal No. 28
    // Berapakah hasil dari penjumlahan tiga(1) + tiga(2) + ... + tiga(100)?

    int sum = 0;
    for (int i = 1; i <= 100; i++) sum += tiga(i);

    printf("Hasil penjumlahan tiga(1) + tiga(2) + ... + tiga(100) adalah %d\n", sum);
    return 0;
}
