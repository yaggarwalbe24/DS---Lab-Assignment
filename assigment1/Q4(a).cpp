#include <iostream>
using namespace std;
int main(){
    int num,i,j,temp,mid;
    cout<<"Please enter the number of elements to be entered into the array:    ";
    cin>>num;
    int arr[num];
    for (int i = 0;i<num;i++){
        cout<<"Please enter element "<<i+1<<":    ";
        cin>>arr[i];
    }
    cout<<"Original aaray:  ";
    for (i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n Reversed array:   ";
    if (num%2 == 0){
        mid = (num/2)-1;
        for (i=0,j=num-1;i<=mid&&j>mid;i++,j--){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    else{
        mid = (num-1)/2;
        for (i=0,j=num-1;i<mid&&j>mid;i++,j--){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    for (i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
}