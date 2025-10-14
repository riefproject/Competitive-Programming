#include <stdio.h>

int tiga(int n){
    if (n <= 1) return 1;
    else if (n % 3 == 0) return tiga(n - 1) + tiga(n - 3);
    else if (n % 3 == 1) return tiga(n - 2);
    else return tiga(n - 3);
}

int main(){
    // Soal No. 26
    // Dari nilai n = {2, 6, 14, 18, 25}, berapakah nilai tertinggi dari fungsi tiga(n)?

    int max = -1; int idx = -1;
    int values[] = {2, 6, 14, 18, 25};

    for (int i = 0; i < 5; i++) {
        int result = tiga(values[i]);
        if (result > max) max = result, idx = i;
    }

    printf("Nilai tertinggi dengan n %d adalah %d\n", values[idx], max);
    return 0;
}