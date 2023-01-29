#include<iostream>
using namespace std;

int id=1;
string keyWords[7] = {"int","float","double","for","while","if","else"};

int esPerline[10],line = 0, charPerline[10];

void counts(string st,int length)
{
    for(int i = 0;i<length;i++){
        if(st[i]=='\t' || st[i] == ' ')
        {
            esPerline[line] +=1;
        }
        else if(st[i]=='\n'){
            line++;
        }
        else{
            charPerline[line] +=1;
        }
    }
}

bool isKeyWords(string temp)
{
    for(int i=0;i<7;i++)
    {
        if(keyWords[i] == temp)
        {
            return true;
        }
    }
    return false;
}

bool isOperator(char s)
{
    if(s == '=' || s == '+' || s == '-' || s == '*' || s == '/'|| s == '^'|| s == '>'|| s == '<')
    {
        return true;
    }

    return false;
}

bool isVariable(string str){
    bool flag = true;

    if(isdigit(str[0])){
        for(int i = 0;i<str.length();i++){
            if(isdigit(str[i])){
                flag = true;
            }
            else{
                if(flag){
                    flag = false;
                    break;
                }
            }
        }
    }
    return flag;
}

bool isValid(string str, int n)
{
	char temp[100];
	int k = 0;
	if (!((str[0] >= 'a' && str[0] <= 'z')
		|| (str[0] >= 'A' && str[0] <= 'Z')
		|| str[0] == '_')
        )
		return false;

	for (int i = 0; i<n; i++) {
		if(isOperator(str[i])){
            temp[k] = NULL;
            k=0;
            if(!isVariable(temp)){
                return false;
            }
		}
		else{
            if(str[i]!=' '){
                temp[k] = str[i];
                k++;
            }
		}

	}
	return true;
}

void check(string s, int length)
{
    string temp="";
    int j;
    if(isValid(s,length)){
        for(int i=0;i<length;i++)
        {
            temp = "";
            while(s[i] !=' ')
            {
                temp +=s[i];
                i++;
            }
            if(isKeyWords(temp))
            {
                cout<<"< "<<temp<<" >";
            }
        }
    }
    else{

    }
}

int main()
{


    string st = "int c = a + 59 + 20 + abc ;\n int a = bc + 30;";

    int length = st.size();
    counts(st,length);
    cout<<"Total number of lines : "<<line+1<<endl;
    for(int i = 0;i<=line;i++)
    {
        cout<<"number of White space in a line "<<i+1<<" is : "<<esPerline[i]<<endl;
        cout<<"number of Char in a line "<<i+1<<" is : " <<charPerline[i]<<endl<<endl;
    }

    check(st,length);

    int k = 1;
    bool digitStart = true;
    bool variableStart = true;
    if(isValid(st,length)){
        for(int i=0;i<length;i++){
            if(isOperator(st[i])){
                cout<<")"<<"("<<st[i]<<")";
                digitStart = true;
                variableStart = true;
            }
            else if(isdigit(st[i])){
                if(digitStart){
                    cout<<"(";
                    digitStart = false;
                }
                cout<<st[i];
            }
            else{
                if(st[i]!=' ' && st[i]!=';'){
                    if(variableStart){
                        cout<<"(id, "<<k;
                        k++;
                        variableStart = false;
                    }
                }
            }
        }
        cout<<")";
    }
    else{
        cout<<"statement is invalid!!!";
    }
    return 0;
}
