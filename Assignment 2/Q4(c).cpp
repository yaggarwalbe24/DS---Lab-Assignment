#include <iostream>
#include <string>
using namespace std;
int main(){
    string s1,s2;
    cout<<"Please eneter a string:  ";
    getline(cin,s1);
    for(int i=0;i<s1.length();i++){
        if(s1[i]=='a'||s1[i]=='A'||s1[i]=='e'||s1[i]=='E'||s1[i]=='i'||s1[i]=='I'||s1[i]=='o'||s1[i]=='O'||s1[i]=='u'||s1[i]=='U'){
            continue;
        }
        else{
            s2+=s1[i];
        }
    }
    cout<<s2;
}
