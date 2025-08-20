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
    int countUnique = 0;
    for(int i=0;i<num;i++){
        bool unique = true;
        for(int j=0;j<i;j++){
            if(arr[i]==arr[j]){
                unique = false;
                break;
            }
        }
        if(unique == true){
            countUnique += 1;
        }
    }
    cout<<"Number of unique elements:   "<<countUnique;        
}
