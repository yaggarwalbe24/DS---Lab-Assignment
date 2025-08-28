#include <iostream>
#include <string>
using namespace std;
int main(){
    string s1;
    cout<<"Please enter a string:   ";
    getline(cin,s1);
    int length = s1.length();
    char stack[length];
    int top = 0;
    for(int i=0;i<length;i++){
        stack[top] = s1[i];
        top ++;
    }
    top-=1;
    cout<<"The reversed string is:  \n";
    while(top>=0){
        cout<<stack[top];
        top--;
    }
}