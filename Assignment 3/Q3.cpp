#include <iostream>
#include <string>
using namespace std;
bool balanced(string exp,int length){
    int count = 0;
    char stack[length];
    for(int i = 0;i<length;i++){
        if(exp[i] == '(' || exp[i]=='{' || exp[i]=='['){
            stack[count] = exp[i];
            count += 1;
        }
        else if(exp[i] == ')'){
            if(count == 0){
                return false;
            }
            else{
                if(stack[count-1]=='('){
                    count -=1;
                }
                else{
                    return false;
                }
            }
        }
        else if(exp[i] == '}'){
            if(count == 0){
                return false;
            }
            else{
                if(stack[count-1]=='{'){
                    count -=1;
                }
                else{
                    return false;
                }
            }
        }
        else if(exp[i] == ']'){
            if(count == 0){
                return false;
            }
            else{
                if(stack[count-1]=='['){
                    count -=1;
                }
                else{
                    return false;
                }
            }
        }
    }
    if(count == 0){
        return true;
    }
    return false;
}
int main(){
    string exp;
    cout<<"Please enter the expression: ";
    getline(cin,exp);
    int length = exp.length();
    if(balanced(exp,length)){
        cout<<"The expression is balanced";
    }
    else{
        cout<<"The expression is not balanced";
    }    
}