#include <iostream>
using namespace std;

int DUA(string S, string T) {
    int N = S.length();
    int M = T.length();
    int P = 0;
    
    for (int i = 0; i <= N - M; i++) {
        int Q = 1;
        for (int j = 0; j < M; j++) {
            if (S[i + j] != T[M - 1 - j]) {
                Q = 0;
            }
        }
        P += Q;
    }

    return P;
}

int main(){
    // Soal No. 32
    // Jika diketahui bahwa nilai string S = “ACCAAACCA”, maka berapakah banyak kemungkinan string T sedemikian sehingga hasil kembalian dari pemanggilan DUA(S, T) sama dengan 2? Perhatikan bahwa tidak ada syarat mengenai panjang dari string T.

    string S = "ACCAAACCA";
    int count = 0;
    string possible_T[] = {"A", "C", "AA", "AC", "CA", "CC", "AAA", "AAC", "ACA", "ACC", "CAA", "CAC", "CCA", "CCC", "ACCA", "ACAA", "AACC", "CAAC", "CCAA", "CCCA", "ACCAA", "ACCCA", "ACCAAC", "ACCAAA", "ACCAACCA"};
    for (const string& T : possible_T) {
        if (DUA(S, T) == 2) {
            count++;
        }
    }

    cout << "Banyak kemungkinan string T adalah: " << count << endl;

    return 0;
}
