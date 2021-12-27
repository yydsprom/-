#include <iostream>
#include <cstring>
#include <algorithm>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    int x1[4] = {0,1,0,-1};int y1[4] = {1,0,-1,0};
    int a[101][101];
    while(cin>>n,n){
    memset(a,0,sizeof(a));
    int x = 0; int y = 0;
    int mx,ny;
    int d = 0;
    int quan = 1;
    int jishu = 0;
    for(int i = 0;i<n*n;i++)
    {
        mx = x+x1[d];ny = y+y1[d];
        a[x][y] = quan;
        if(a[mx][ny]||mx>=n||mx<0||ny>=n||ny<0)
        {
            jishu++;
            d = (d+1)%4;
            mx = x+x1[d]; ny = y+y1[d];  
            if(!(jishu%4))
                quan++;
        }
        x = mx; y = ny;
    }
   
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < n; j ++)
                cout << a[i][j] << ' ';
            cout << endl;
        }
        cout << endl;
    
    
    }
    return 0;
}