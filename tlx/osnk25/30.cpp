#include <iostream>
#include <vector>
using namespace std;

int gsi(vector<int> B, int x, int y){
    return B[y] - B[x - 1];
}

int fun(vector<int> A){
    int n = A.size();
    
    vector<int> B;
    B.push_back(0);
    for (int i = 0; i < n; i++) B.push_back(B[i] + A[i]);

    // untuk menjawab soal nomor 30
    vector<int> gsi_values = {
        gsi(B, 1, 4),
        gsi(B, 2, 4),
        gsi(B, 4, 5),
        gsi(B, 5, 5),
        gsi(B, 3, 4)
    };
    for (auto val : gsi_values) cout << val << " ";
    cout << endl;
    // sampai sini

    int out = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            out = max(out, gsi(B, i, j));

    return out;
}

int main(){
    // Soal No. 30
    // Apabila vector A berisi {1, 2, 3, 4, 5} maka manakah kembalian GSI terbesar?
    // A. GSI(B, 1, 4)
    // B. GSI(B, 2, 4)
    // C. GSI(B, 4, 5)
    // D. GSI(B, 5, 5)
    // E. GSI(B, 3, 4)

    vector<int> A = {1, 2, 3, 4, 5};

    cout << "Isi dari vector B adalah: ";
    fun(A);

}