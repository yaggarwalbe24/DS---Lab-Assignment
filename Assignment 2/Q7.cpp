#include <iostream>
using namespace std;
int main(){
    int num;
    cout<<"Please enter the number of elements in the array:    ";
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    int countInversions = 0;
    for(int i=0;i<num;i++){
        for(int j=i+1;j<num;j++){
            if(arr[i]>arr[j]){
                countInversions+=1;
            }
        }
    }
    cout<<"Counted Inversions:  "<<countInversions;
}
