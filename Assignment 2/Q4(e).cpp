#include <iostream>
#include <string>
using namespace std;
int main(){
    string s1;
    cout<<"Please enter a string:   ";
    getline(cin,s1);
    for(int i=0;i<s1.length();i++){
        if(65<=s1[i]&& s1[i]<=90){
            s1[i] += 32;
        }
    }
    cout<<s1;
}
