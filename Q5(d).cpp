#include <iostream>
using namespace std;
int main(){
    int num;
    cout<<"Please enter the size of the matrix: ";
    cin>>num;;
    int size = ((num*(num+1))/2);
    int arr[size];
    cout<<"Please enter the elements in the array:   ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"The 2D matrix is:    \n";
    int k=0;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(i<=j){
                cout<<arr[k]<<" ";
                k++;
            }
            else{
                cout<<"0"<<" ";
            }
        }
        cout<<"\n";
    }    
}
