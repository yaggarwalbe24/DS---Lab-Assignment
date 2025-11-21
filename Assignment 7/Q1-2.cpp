#include <iostream>
using namespace std;
void selectionSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        if(min!=i){
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
}
void optimisedSelectionSort(int a[],int n){
    int start = 0,end = n-1;
    while(start<end){
        int minIndex = start;
        int maxIndex = end;
        for(int i=start;i<=end;i++){
            if(a[i]<a[minIndex]){
                minIndex = i;
            }
            if(a[i]>a[maxIndex]){
                maxIndex = i;
            }
        }
        if(minIndex != start){
            int temp = a[minIndex];
            a[minIndex] = a[start];
            a[start] = temp;
        }
        if(maxIndex == start){
            maxIndex = minIndex;
        }
        if(maxIndex != end){
            int temp = a[maxIndex];
            a[maxIndex] = a[end];
            a[end] = temp;
        }
        start ++;
        end--;
    }

}
void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int temp = a[i];
        int j = i-1;
        while(j>=0 && a[j]>temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}
void bubbleSort(int a[], int n){
    for(int i = 0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
void merge(int arr[],int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int left[n1], right[n2];
    for(int i=0;i<n1;i++){
        left[i] = arr[l+i];
    }
    for(int j=0;j<n2;j++){
        right[j] = arr[m+1+j];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }
    }
    while(i<n1){
        arr[k++] = left[i++];
    }
    while(j<n2){
        arr[k++] = right[j++];
    }
}
void mergeSort(int a[],int l, int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }

}
int partition(int a[],int low, int high){
    int pivot = a[high];
    int i =low-1;
    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i+1];
    a[i+1] = a[high];
    a[high] = temp;
    return i+1;
}
void quickSort(int a[],int low, int high){
    if(low<high){
        int pi = partition(a,low,high);
        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
}
int main(){
    int arr[] = {3,43,23,55,24,95,53,75};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"1. Selection sort\n";
    cout<<"2. Insertion sort\n";
    cout<<"3. Bubble sort\n";
    cout<<"4. Merge sort\n";
    cout<<"5. Quick sort\n";
    cout<<"6. Optimised Selection sort\n";
    cout<<"Please select the sorting algorithm to implement\n";
    int op;
    cin>>op;
    if(op == 1){
        selectionSort(arr,length);
    }
    if(op == 2){
        insertionSort(arr,length);
    }
    if(op == 3){
        bubbleSort(arr,length);
    }
    if(op == 4){
        mergeSort(arr,0,length-1);
    }
    if(op == 5){
        quickSort(arr,0,length-1);
    }
    if(op == 6){
        optimisedSelectionSort(arr,length);
    }
    cout<<"Sorted array\n";
    for(int i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
}