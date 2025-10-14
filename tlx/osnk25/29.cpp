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

    // untuk menjawab soal nomor 29
    for (auto b : B) cout << b << " ";
    return 0;
    // sampai sini

    int out = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            out = max(out, gsi(B, i, j));

    return out;
}

int main(){
    // Soal No. 29
    // Apabila vector A berisi {1, 2, 3, 4, 5} maka manakah isi dari vector B?
    vector<int> A = {1, 2, 3, 4, 5};

    cout << "Isi dari vector B adalah: ";
    fun(A);

}