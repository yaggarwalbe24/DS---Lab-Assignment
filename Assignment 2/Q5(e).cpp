#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter the size of the matrix:    ";
    cin>>num;
    int size=(num*(num+1))/2;
    int arr[size];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"The 2D matrix is:    \n";
    int b[num][num];
    int k=0;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(i<=j){
                b[i][j]=arr[k];
                k++;
            }
        }
    }
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(i>j){
                b[i][j]=b[j][i];
            }
        }
    }
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<"\n";
    }
}
