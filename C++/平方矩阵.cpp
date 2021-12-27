#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 100 + 10;
int m[N][N];

int main(){
    int n;
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

    while(cin >> n, n ){
        memset(m, 0, sizeof m);
        int d = 1, x = 0, y = 0;
        int cnt = 0;  // 表示改变方向次数
        int res = 1;  // 回形当前圈数
        for (int i = 0; i < n * n; i ++){
            int a = x + dx[d], b = y + dy[d];
            m[x][y] = res;

            if (a < 0 || a >= n || b < 0 || b >= n || m[a][b]){
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
                cnt ++;
                if (!(cnt % 4)) res ++;
            }
            x = a, y = b;
        }

        for (int i = 0; i < n; i ++){
            for (int j = 0; j < n; j ++)
                cout << m[i][j] << ' ';
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

