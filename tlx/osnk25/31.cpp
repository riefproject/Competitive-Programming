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

    int out = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            out = max(out, gsi(B, i, j));

    return out;
}

int main(){
    // Soal No. 31
    // Berapakah hasil kembalian dari pemanggilan FUN({3, -2, 4, -3, 1, -4, 2, -1, 4, 3, -2, 3, -2, 2, -2, 3})?

    cout << "Hasil kembalian dari FUN adalah: ";
    cout << fun({3, -2, 4, -3, 1, -4, 2, -1, 4, 3, -2, 3, -2, 2, -2, 3}) << endl;
}