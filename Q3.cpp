#include <iostream>
using namespace std;
int main(){
    int arr[4] = {2,3,5,6};
    for(int i =0;i<4;i++){
        if(arr[i+1] != arr[i]+1){
            cout<<"The missing number is:   "<<arr[i]+1;
            break;
        }
    }
}
