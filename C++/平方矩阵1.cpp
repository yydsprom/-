#include<iostream>
using namespace std;
int main()
{
    int n;
    int i,j;
    while(cin>>n,n)
    {
        for(i=0;i<n;i++)
         {
            for(j=0;j<n;j++)
            {
                if(n%2)
                {
                    cout<<(n+1)/2-max(abs(n/2-i),abs(n/2-j))<<" ";

                }
                else
                {
                    cout<<(n+1)/2.0-max(abs(n-1)/2.0,abs(n-1)/2.0)<<" ";

                }


                
            }

            cout<<endl;
         }

        cout<<endl;
    }

}