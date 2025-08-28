#include <iostream>
using namespace std;
int main(){
    int num;
    cout<<"Please enter the size of the matrix:  ";
    cin>>num;
    int arr[num];
    cout<<"Please enter the diagonal elements:  ";
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    cout<<"The 2D matrix is:    "<<"\n";
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(i==j){
                cout<<arr[i]<<" ";
            }
            else{
                cout<<"0"<<" ";
            }
        }
        cout<<"\n";
    }
}
