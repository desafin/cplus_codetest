#include <bits/stdc++.h>
using namespace std;
int a;
int main() {
  cin >> a;
  scanf("%d", &a);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
string a, b;
int main(){
cin >> a >> b;
cout << a << "\n";
cout << b << "\n";
return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a;
double b;
char c;
int main(){
scanf("%d %lf %c", &a, &b, &c);
printf("%d\n", a);
printf("%lf\n", b);
printf("%c\n", c);
return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main(){
    double a;
    double b;
    cin>> a>>b;
    cout.precision(10);
    cout<<a/b<<endl;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    int b;
    cin >> a >> b;
    if (a>b)
    {
        cout<<">"<<endl;
    }
    else if(a<b)
    {
        cout<<"<"<<endl;
    }
    else
    {
        cout<<"=="<<endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    string star = "*";
    cin >> a;
    for (int i=0;i<a;i++)
    {
        cout<<star<<endl;
        star+= "*";
    }
}


#include <bits/stdc++.h>
using namespace std;

int main(){
    int count;
    cin >> count;
    for(int i=1;i<10;i++)
    {
        cout<<count<<" * "<<i<<" = "<<count*i<<endl;
    }

}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    int b;
    cin >> a>>b;
    cout<<a+b<<"\n"<<a-b<<"\n"<<a*b<<"\n"<<a/b<<"\n"<<a%b<<endl;

}


#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    int count;
    cin >> count;
    string num;
    cin >> num;
    int sum=0;
    for(int i=0;i<count;i++)
    {
        sum+=num[i]-'0';
    }
    cout<<sum<<endl;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int max=-1;
    int maxIndex=0;
    int num;
    for(int i=0;i<9;i++)
    {
        cin>>num;
        if(max<num)
        {
            max=num;
            maxIndex=i+1;
        }

    }
    cout<<max<<"\n"<<maxIndex<<endl;

}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int count;
    int a;
    int b;
    cin>>count;
    for (int i =0;i<count;i++)
    {
        cin>> a >>b;
        cout<<a+b<<endl;

    }
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int count;
    int max=-1000000;
    int min=1000000;
    int num;
    cin>>count;
    for (int i =0;i<count;i++)
    {
        cin>>num;
        if(max<num)
        {
            max=num;
        }
        if(min>num)
        {
            min=num;
        }
    }
    cout<<min<<" "<<max<<endl;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    int b;
    while (true) 
    {
        cin>>a>>b;
        cout<<a+b<<endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    int b;
    while (true) 
    {
        cin>>a>>b;
        if(a==0&&b==0)
        {
            break;
        }
        cout<<a+b<<endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    cout<<"         ,r\'\"7"<<endl;
    cout<<"r`-_   ,'  ,/"<<endl;
    cout<<" \\. \". L_r\'"<<endl;
    cout<<"   `~\\/"<<endl;
    cout<<"      |"<<endl;
    cout<<"      |"<<endl;

}


#include <bits/stdc++.h>
using namespace std;

int main(){
    int testnum;
    string str;
    int num ;
    cin >>testnum;
    for(int k=0;k<testnum;k++)
    {
    cin >> num;
    cin >> str;
    for(int j=0;j<str.length();j++)
    {
        for(int i =0;i<num;i++)
        {
            cout<<str[j];
        }
    }
    cout<<"\n";
}
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    long a;
    long b;
    long c;
    while (true) 
    {
        cin>>a>>b>>c;
        if(a>b) swap(a,b);
        if(b>c) swap(b,c);
        cout<<a<<" "<< b<<" "<<c<<endl;

        if(a==0&&b==0&&c==0)
        {
            return 0;
        }
        if(a*a+b*b==c*c)
        {
            cout<<"right"<<"\n";
        }
        else {
            cout<<"wrong"<<"\n";
        }
    }
    
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    long a;
    long b;
    long c;
    while (true) 
    {
        cin>>a>>b>>c;
        if(a>b) swap(a,b);
        if(b>c) swap(b,c);
        cout<<a<<" "<< b<<" "<<c<<endl;

        if(a==0&&b==0&&c==0)
        {
            return 0;
        }
        if(a*a+b*b==c*c)
        {
            cout<<"right"<<"\n";
        }
        else {
            cout<<"wrong"<<"\n";
        }
    }
    
}


#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
  int caseCount;
  cin >> caseCount;
  int num;
  int count = 0;

  for (int i = 0; i < caseCount; i++) {
    bool isprime = true;
    cin >> num;
    if (num == 1) {
      continue;
    }
    for (int j = 2; j * j <= num; j++) {
      if ((num % j) == 0) {
        isprime = false;
        break;
      }
    }
    if (isprime == true) {
      count++;
    }
  }
  cout << count << endl;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
  int caseCount;
  cin >> caseCount;
  int num;
  int count = 0;

  for (int i = 0; i < caseCount; i++) {
    bool isprime = true;
    cin >> num;
    if (num == 1) {
      continue;
    }
    for (int j = 2; j * j <= num; j++) {
      if ((num % j) == 0) {
        isprime = false;
        break;
      }
    }
    if (isprime == true) {
      count++;
    }
  }
  cout << count << endl;
}


#include <bits/stdc++.h>
using namespace std;

int main() {
    int cardCount;
    int targetNumber;
    int sum=0;
    cin>>cardCount>>targetNumber;
    vector<int> cardList;
    for(int i=0;i<cardCount;i++)
    {
        int cardNum;
        cin>>cardNum;
        cardList.push_back(cardNum);
    }
    for(int i=0;i<cardList.size();i++)
    {
        for(int j=i+1;j<cardList.size();j++)
        {
            for(int k=j+1;k<cardList.size();k++)
            {
                //찾은경우
                int result =cardList[i]+cardList[j]+cardList[k];
                if(targetNumber==result)
                {
                    // cout<<cardList[i]<<" "<<cardList[j]<<" "<<cardList[k]<<endl;
                    // cout<<"find number"<<endl;
                    cout<<targetNumber;
                    return 0;
                }
                else if ((targetNumber>result)&&(sum<result)) 
                {
                    sum=result;
                }

            }
        }
        
    }
    cout<<sum;
}


#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  while (true) {
    bool result = true;
    cin >> str;
    if (str == "0") {
      break;
    }
    for (int i = 0; i < str.length() / 2; i++) {
      if (str[i] != str[str.length() - 1 - i]) {
        result = false;
        break;
      }
    }
    if (result) {
      cout << "yes" << endl;

    } else {
      cout << "no" << endl;
    }
  }
}


#include <bits/stdc++.h>
using namespace std;

int main() {
    // cout<<"start"<<endl;
    int answerShert=0;
    int answerPen=0;
    int manCount;
    cin>>manCount;
    vector<int> shertList;
    for(int i =0;i<6;i++)
    {
        int shert;
        cin>> shert;
        shertList.push_back(shert);
    }
    // cout<<"start unit"<<endl;
    int shertUnit;
    int penUnit;
    cin>>shertUnit>>penUnit;

    for(int i=0;i<6;i++)
    {
        answerShert+=shertList[i]/shertUnit;
        if(shertList[i]%shertUnit!=0)
        {
            answerShert++;
        }
        // cout<<answerShert<<" "<<shertList[i]<<" "<<shertUnit;

    }
    answerPen+=manCount/penUnit;

    cout<<answerShert<<endl;
    cout<<answerPen<<" " <<manCount%penUnit<<endl;    
}


#include <bits/stdc++.h>
using namespace std;

int compare(const pair<int,string> &a, const pair<int,string> &b) {
    return a.first < b.first;
}

int main(){
    int CaseNum;
    cin>>CaseNum;
    vector<pair<int, string>> mapList;
    for (int i=0;i<CaseNum;i++)
    {
        int num;
        string name;
        cin>>num>>name;
        mapList.push_back({num,name});

    }
    stable_sort(mapList.begin(),mapList.end(),compare);
    for(int i=0;i<mapList.size();i++)
    {
        cout<<mapList[i].first<<" "<<mapList[i].second<<"\n";
    }
    
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int nCaseNum;
    cin>>nCaseNum;
    queue<int> q;
    for (int i=1;i<=nCaseNum;i++)
    {
        q.push(i);

    }
    for (int i=0;i<nCaseNum-1;i++)
    {
        q.pop();
        int temp; 
        temp=q.front();
        q.pop();
        q.push(temp);
    }
    cout<<q.front()<<endl;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int nCaseNum;
    cin>>nCaseNum;
    stack<int> s;
    for (int i=1;i<=nCaseNum;i++)
    {
        int answer;
        string cmd;
        int num;
        cin>>cmd;
        if(cmd=="push")
        {
            cin>>num;
            s.push(num);
        }
        else if(cmd=="pop")
        {
            if(s.empty())
            {
                answer=-1;
                cout<<answer<<"\n";
            }
            else 
            {
            answer = s.top();
            s.pop();
            cout<<answer<<"\n";
            }
        }
        else if(cmd=="size")
        {
            answer=s.size();
            cout<<answer<<"\n";
        }
        else if(cmd=="empty")
        {
            answer=s.empty();
            cout<<answer<<"\n";

        }
        else if (cmd=="top") {
            if(s.empty())
            {
                answer=-1;
                cout<<answer<<"\n";
            }
            else 
            {
                answer= s.top();
                cout<<answer<<"\n";
            }
            
        }
        

    }
}
