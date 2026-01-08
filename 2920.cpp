#include <bits/stdc++.h>
using namespace std;

int main() {
  // 코드 작성
  vector<int> v;
  for(int i=0;i<8;i++)
  {
	int num;
	cin>>num;
  v.push_back(num);
  }

  int min =1;
  for(int i=0;i<8;i++)
  {
    if(v[i]==min)
    {
      min++;
      if(min==8)
      {
        cout<<"ascending"<<endl;
        return 0;
      }
      else
      {
        continue;

      }
    }
    else
    {
      break;
    }
  }
  int max =8;
  for(int i=0;i<8;i++)
  {
    if(v[i]==max)
    {
      max--;
      if(max==1)
      {
        cout<<"descending"<<endl;
        return 0;
      }
      else
      {
        continue;

      }
    }
    else
    {
      break;
    }
  }
  cout<<"mixed"<<endl;
  return 0;
}