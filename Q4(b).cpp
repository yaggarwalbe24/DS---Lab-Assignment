#include <iostream>
#include <string>
using namespace std;
int main(){
    string s1,s2;
    cout<<"Please enter a string:   ";
    getline(cin,s1);
    for(int i=s1.length()-1;i>=0;i--){
        s2 += s1[i];
    }
    cout<<s2;
}
