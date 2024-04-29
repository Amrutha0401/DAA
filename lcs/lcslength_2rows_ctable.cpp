#include<iostream>
using namespace std;
#include<limits.h>
#include<vector>
void lcs_length(string x, string y, vector<vector<int> >&c, vector<vector<char> > &b)
{
    int m,n,i,j;
    m = x.length();
    n = y.length();
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[1][j] = c[0][j-1] + 1;
                b[i][j] = 'd';
            }
            else if(c[0][j]>=c[1][j-1])
            {
                c[1][j] = c[0][j];
                b[i][j] = 'u';
            }
            else
            {
                c[1][j] = c[1][j-1];
                b[i][j] = 'd';
            }
        }
        c[0]=c[1];
    }
}

int main()
{
    string x,y;
    int i,j;
    cin>>x>>y;
    vector<vector<int> > c(2,vector<int>(y.length()+1,0));
    vector<vector<char> > b(x.length()+1,vector<char>(y.length()+1,' '));
    lcs_length(x,y,c,b);
    cout<<c[1][y.length()];
}
