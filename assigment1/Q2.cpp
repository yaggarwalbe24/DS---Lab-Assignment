# include <iostream>
using namespace std;
int main(){
    int n,temp;
    cout<<"Please enter the number of elements to be entered into the array:    ";
    cin>>n;
    int arr[n];
    for (int i = 0;i<n;i++){
        cout<<"Please enter element "<<i+1<<":    ";
        cin>>arr[i];
    }
    for(int i =0;i<n;i++){
        for(int j =0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            for(int j = i;j<n-1;j++){
                arr[j] = arr[j+1];
            }
            n--;
            i--;
        }
    }
    cout<<"Array of unique elements:    ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}