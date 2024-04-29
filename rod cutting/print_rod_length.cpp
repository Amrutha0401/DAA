#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>
struct lengths{
    int a;
    int b;
};
int maximum(int a, int b)
{    
    if(a>b)
        return a;
    return b;
}
int bottom_up_cut_rod(vector<int> &p, int length,struct lengths l[]){    
    vector<int> r(100,0);
    int i,q,j;
    r[0] = 0;
    for (j=1;j<=length;j++)
    {
        q = INT_MIN;
        int q1;
        for(i=1;i<=j;i++)
        {   q1=q;
            q = maximum(q,p[i-1]+r[j-i]);
            if(q!=q1){
                l[j-1].a=i;;
                l[j-1].b=j-i;
            }
            
        }
        r[j] = q;
    }
    
    
    return r[length];
}

int main()
{
    vector<int> p;
    int i,n,price,max_profit;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>price;
        p.push_back(price);
    }
    struct lengths l[n];
    max_profit = bottom_up_cut_rod(p,n,l);
    int new_len=n;
    int p1;
    while(new_len!=0){
        p1=l[new_len-1].a;
        cout<<p1<<" ";
        new_len=l[new_len-1].b;
    }
    cout<<max_profit;
}
