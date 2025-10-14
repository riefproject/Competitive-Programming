#include <bits/stdc++.h>
using namespace std;

int N;
int board[55][55];
bool steril[55][55];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int calc(int r, int c, int g[55][55]) {
    int val = g[r][c];
    bool v[55][55] = {};
    queue<pair<int,int>> q;
    q.push({r, c});
    v[r][c] = true;
    int cnt = 1;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && 
                !v[nx][ny] && g[nx][ny] == val) {
                v[nx][ny] = true;
                q.push({nx, ny});
                cnt++;
            }
        }
    }
    return cnt;
}

void query(int n) {
    cout << "QUERY" << endl;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (steril[i][j]) {
                board[i][j] = 0;
            } else {
                if (n == 1) {
                    board[i][j] = ((i + j) % 3) + 1;
                } else if (n == 2) {
                    board[i][j] = ((i * 2 + j) % 3) + 1;
                } else {
                    board[i][j] = ((i + j * 2) % 3) + 1;
                }
            }
        }
    }
    
    // Then output the board
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << board[i][j];
            if (j < N) cout << " ";
        }
        cout << endl;
    }
    cout << flush;
    
    int S, M;
    cin >> S >> M;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!steril[i][j]) {
                if (board[i][j] != S || calc(i, j, board) != M) {
                    steril[i][j] = true;
                }
            }
        }
    }
}

int main() {
    N = 50; 
    cout << N << endl;
    cout << flush;
    
    memset(steril, false, sizeof(steril));
    
    for (int q = 1; q <= 3; q++) query(q);
    
    int r = -1, c = -1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!steril[i][j]) {
                r = i;
                c = j;
                break;
            }
        }
        if (r != -1) break;
    }
    
    cout << "ANSWER" << endl;
    cout << r << " " << c << endl;
    cout << flush;
    
    return 0;
}