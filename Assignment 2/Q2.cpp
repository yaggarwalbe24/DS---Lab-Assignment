#include <iostream>
using namespace std;
int main(){
    int num,i,j,temp;
    cout<<"Please enter how many elements to be entered into the array:    ";
    cin>>num;
    int arr[num];
    cout<<"Please enter the elements in the array:  ";
    for(int i = 0;i<num;i++){
        cin>>arr[i];
    }
    for(i=0;i<num;i++){
        for(j=0;j<num-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<"Sorted array:    ";
    for(int i = 0;i<num;i++){
        cout<<arr[i]<<" ";
    }
}
