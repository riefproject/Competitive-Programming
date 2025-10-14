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
    // Akan dipanggil:
    // DUA(“BBABAABBAAABBABBAAABBBAAABBABBA”, T)
    // yang mana T adalah sebuah string dengan panjang minimal 3.
    // Dari seluruh kemungkinan nilai string T, berapakah hasil kembalian paling besar dari pemanggilan tersebut?

    string S = "BBABAABBAAABBABBAAABBBAAABBABBA";
    int max_result = 0;
    string best_T;
    for (char c1 = 'A'; c1 <= 'Z'; c1++) {
        for (char c2 = 'A'; c2 <= 'Z'; c2++) {
            for (char c3 = 'A'; c3 <= 'Z'; c3++) {
                string T = {c1, c2, c3};
                int result = DUA(S, T);
                if (result > max_result) {
                    max_result = result;
                    best_T = T;
                }
            }
        }
    }
    cout << "Hasil kembalian paling besar adalah: " << max_result << " dengan T = " << best_T << endl;

    return 0;
}
