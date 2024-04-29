#include <iostream>
#include <vector>
using namespace std;
struct pairs{
    int a;
    int b;
};
int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int i,j,len,len1;
    len=s1.length();
    len1=0;
    struct pairs* p;
    p=(struct pairs*)malloc((len/2)*sizeof(struct pairs));
    vector<char> s3;
    for(i=0;i<len;i++){
        s3.push_back(s2[i]);
    }
    int count=0;
    for(i=0;i<len;i++){
        if(count==len)
        {
            break;
        }
        if(s1[i]==s3[i]){
            count+=1;
        }
        else{
            for(j=i+1;j<len;j++){
                if((s1[i]==s3[j]) && (s1[j]==s3[i])){
                    p[len1].a=i+1;
                    p[len1].b=j+1;
                    char t=s3[i];
                    s3[i]=s3[j];
                    s3[j]=t;
                    len1+=1;
                    count+=2;
                }
            }
        }
    }
    if(count!=len){
        cout<<"Not possible";
    }
    else{
        for(i=0;i<len1;i++){
            cout<<p[i].a<<" "<<p[i].b<<endl;
        
    }
    }
    
}
