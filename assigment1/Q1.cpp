# include <iostream>
using namespace std;
int main(){
    int arr[20];
    int num = 0;
    while (true){
        int option;        
        cout<<"Please enter an option"<<"\n";
        cout<<"1. Create"<<"\n";
        cout<<"2. Display"<<"\n";
        cout<<"3. Insert"<<"\n";
        cout<<"4. Delete"<<"\n";
        cout<<"5. Linear Search"<<"\n";
        cout<<"6. Exit"<<"\n";
        cin>>option;
        if (option == 1){
            int num_of_entries;
            cout<<"Please enter the number of elements to be enetered into the array:   ";
            cin>>num_of_entries;
            for(int i=0;i<num_of_entries;i++){
                cout<<"Please enter element "<<i<<"\t";
                cin>>arr[i];
            }
            num = num_of_entries;
        }
        else if (option == 2){
            if (num == 0){
                cout<<"The array is empty";
            }
            else{
                for (int i = 0;i<num;i++){
                    cout<<arr[i]<<"\t";
                }
            }
            cout<<"\n";
        }
        else if (option == 3){
            int ele,pos;
            cout<<"Please enter the element to be inserted: ";
            cin>>ele;
            cout<<"Please enter the position of the element:    ";
            cin>>pos;
            for (int i = num-1;i>=pos-1;i--){
                arr[i+1] = arr[i];
            }
            num+=1;
            arr[pos-1] = ele;
            for (int i = 0;i<num;i++){
                cout<<arr[i]<<"\t";
            }
            cout<<"\n";    
        }
        else if (option == 4){
            int ele,pos;
            cout<<"Please enter the element to be deleted:  ";
            cin>>ele;
            for(int i=0;i<num;i++){
                if (arr[i] == ele){
                    pos = i;
                    break;
                }
            }
            for(int i=pos+1;i<num;i++){
                arr[i-1] = arr[i];
            }
            num-=1;
            for (int i = 0;i<num;i++){
                cout<<arr[i]<<"\t";
            }
            cout<<"\n";
        }
        else if (option == 5){
            int ele;
            bool found = false;
            cout<<"Please enter an element to search for:   ";
            cin>>ele;
            for(int i=0;i<num;i++){
                if (arr[i] == ele){
                    cout<<"The element is at "<<i<<" index\n";
                    found = true;
                    break;
                }
            }
            if (found == false){
                cout<<"The element is not present in the array\n";
            }
        }
        else if (option == 6){
            break;
        }
        else{
            cout<<"Invalid input";
        }
    }
}