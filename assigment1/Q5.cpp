#include <iostream>
using namespace std;
int main(){
    int N,M,i,j;
    cout<<"Please enter the number of rows and coloumns of the matrix: ";
    cin>>N>>M;
    int matrix1[N][M];
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            cout<<"Please enter element "<<i<<j<<"\t";
            cin>>matrix1[i][j];
        }
    }
    for(i=0;i<N;i++){
        int summation = 0;
        for(j=0;j<M;j++){
            summation += matrix1[i][j];
        }
        cout<<"Sum of row "<<i<<" is: "<<summation<<"\n";
    }
    for(i=0;i<N;i++){
        int summation = 0;
        for(j=0;j<M;j++){
            summation += matrix1[j][i];
        }
        cout<<"Sum of coloumn "<<i<<" is: "<<summation<<"\n";
    }
}
