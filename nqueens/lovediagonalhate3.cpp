#include <iostream>
#include <vector>
#include <set>
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

vector<string> print_LCS(vector<vector<int> > &c, string x,string y, int i, int j)
{
    
    if (i == 0 || j == 0)
    {
        return {""};
    }

    if (x[i - 1] == y[j - 1])
    {
       
        vector<string> lcs = print_LCS(c,x,y,i-1,j-1);
        for(string &str: lcs){
            str.push_back(x[i-1]);
    }
    return lcs;
    }
    else if(c[i-1][j]==c[i][j-1]){
        vector<string>top=print_LCS(c,x,y,i-1,j);
        vector<string>left=print_LCS(c,x,y,i,j-1);
        top.insert(top.end(),left.begin(),left.end());
        return top;
        
    }
    else if(c[i-1][j]>c[i][j-1]){
        return print_LCS(c,x,y,i-1,j);
    }
    else{
        return print_LCS(c,x,y,i,j-1);
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
    vector<string> lcs=print_LCS(c, x,y, m, n);
    int l=lcs.size();
    set<string> lcs1(lcs.begin(), lcs.end());
    for (string str: lcs1) {
		cout << str << endl;
	}
    return 0;
}
