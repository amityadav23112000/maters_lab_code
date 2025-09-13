#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;


int main(){
  int x= fork();
  if(x==0)
  cout<<"child"<<endl;
  else cout<<" parent"<<endl;
  return 0;
}

