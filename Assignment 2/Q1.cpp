#include <iostream>
using namespace std;
int main(){
    int num,ele,low,mid,high;
    cout<<"Please enter how many elements to be enetered into the array:    ";
    cin>>num;
    int arr[num];
    cout<<"Please enter the elements in a sorted manner\n";
    for(int i = 0;i<num;i++){
        cin>>arr[i];
    }
    low = 0;
    high = num-1;
    bool found = false;
    cout<<"Please eneter the element to be found:   ";
    cin>>ele;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==ele){
            cout<<"The element was found at "<<mid+1<<" position";
            found = true;
            break;
        }
        else if(arr[mid]>ele){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    if(found == false){
        cout<<"Element not present in the array";
    }

}
