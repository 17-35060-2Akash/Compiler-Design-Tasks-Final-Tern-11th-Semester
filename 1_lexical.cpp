#include <bits/stdc++.h>
using namespace std;

int esPerline[10],line = 0, charPerline[10];

void counts(string s,int length)
{
    for(int i = 0;i<length;i++){
        if(s[i]=='\t' || s[i] == ' ')
        {
            esPerline[line] +=1;
        }
        else if(s[i]=='\n')
        {
            line++;
        }
        else{
            charPerline[line] +=1;
        }
    }
}

int main()
{
    string s = "if we take input \n the new line doesn't work \n so I am doing it with fixed string";
    //getline(cin,s);
    int length = s.size();
    counts(s,length);
    cout<<"Total number of line : "<<line+1<<endl;
    for(int i = 0;i<=line;i++)
    {
        cout<<"number of White space in line "<<i+1<<"is : "<<esPerline[i]<<endl;
        cout<<"number of Char in line "<<i+1<<"is : " <<charPerline[i]<<endl<<endl;
    }
    return 0;
}
