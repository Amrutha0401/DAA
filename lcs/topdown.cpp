ODE:
#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    return b;
}

int lcs_length(string x, string y, vector<vector<int> > &c,  int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (x[m - 1] == y[n - 1])
    {
       
        return c[m][n] = 1 + lcs_length(x, y, c, m - 1, n - 1);
    }

    if (c[m][n] != 0)
    {
        return c[m][n];
    }
    else
    {
        int a1 = lcs_length(x, y, c,  m - 1, n);
        int b1 = lcs_length(x, y, c,  m, n - 1);
        if (a1 > b1)
        {
           
        }
        else
        {
           
        }
        return c[m][n] = max(a1, b1);
    }
}

void print_LCS(vector<vector<int> > &c, string x,string y, int i, int j)
{
    
    if (i == 0 || j == 0)
    {
        return ;
    }

    if (x[i - 1] == y[j - 1])
    {
       
        print_LCS(c,x,y,i-1,j-1);
        cout<<x[i-1];
    }
    else if(c[i-1][j]>=c[i][j-1]){
        print_LCS(c,x,y,i-1,j);
    }
    else{
        print_LCS(c,x,y,i,j-1);
    }

}

int main()
{
    string x, y;
    cin >> x;
    cin >> y;
    int m = x.length();
    int n = y.length();
    vector<vector<int> > c(m + 1, vector<int>(n + 1, 0));
    int lcs_len = lcs_length(x,y,c,m,n);
    cout << lcs_len << endl;
    print_LCS(c, x,y, m, n);

    return 0;
}
