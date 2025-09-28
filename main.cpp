#include <bits/stdc++.h>
using namespace std;

bool compare(string a,string b){
    if(a.length()==b.length())
    {
    return a<b;
    }
    else {
    return a.length()<b.length();
    }

}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int nCaseNum;
    cin>>nCaseNum;
    vector<string> v;
    for (int i=1;i<=nCaseNum;i++)
    {
        string str;
        cin>>str;
        v.push_back(str);
    }
    stable_sort(v.begin(),v.end(),compare);
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<"\n";
    }
}
