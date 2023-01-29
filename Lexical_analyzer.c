#include<iostream>
#include <typeinfo>
using namespace std;



char peek;



int main()
{​​​​
string a="int c=ab+10+21+abc;",word="";
int id=0;
for(int i=0;i<a.length();i++)
{​​​​
char letter=a[i];
if(letter!=' ' && letter!='=' && letter!=';' && letter!='+' && letter!='-' && letter!='*' && letter!='/')
{​​​​
word=word+letter;
}​​​​
else
{​​​​
if(word=="int")
{​​​​
cout<<"<keyword>";
}​​​​
else
{​​​​
bool flag=false;
for(int i=0;i<word.length();i++)
{​​​​
char check=word[i];
if(check>='a' && check<='z')
{​​​​
flag=true;
}​​​​
}​​​​



if(!flag)
{​​​​
cout<<"<"<<word<<">";
}​​​​
else
{​​​​
id=id+1;
cout<<"<id,"<<id<<">";
}​​​​
}​​​​
word="";
if(letter=='=' || letter=='+' || letter=='-' || letter=='*' || letter=='/')
{​​​​
cout<<"<"<<letter<<">";
}​​​​
}​​​​



}​​​​




}​​​​

