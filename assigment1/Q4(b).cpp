#include <iostream>
using namespace std;
int main(){
    int N1,M1,N2,M2,i,j,k;
    cout<<"Please enter the number of rows and coloumns of matrix 1: ";
    cin>>N1>>M1;
    int matrix1[N1][M1];
    for(i = 0;i<N1;i++){
        for(j = 0;j<M1;j++){
            cout<<"Please enter element "<<i<<j<<"\t";
            cin>>matrix1[i][j];
        }
    }
    cout<<"Please enter the number of rows and coloumns of matrix 2: ";
    cin>>N2>>M2;
    int matrix2[N2][M2];
    for(i = 0;i<N2;i++){
        for(j = 0;j<M2;j++){
            cout<<"Please enter element "<<i<<j<<"\t";
            cin>>matrix2[i][j];
        }
    }
    if(M1 != N2){
        cout<<"Matrix multiplication not possible";
    }
    else{
        int matrix3[N1][M2];
        for(i=0;i<N1;i++){
            for(j=0;j<M2;j++){
                matrix3[i][j] = 0;
            }
        }
        for(i=0;i<N1;i++){
            for(j=0;j<M2;j++){
                for(k=0;k<M1;k++){
                    matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        for(i=0;i<N1;i++){
            for(j=0;j<M2;j++){
                cout<<matrix3[i][j]<<"\t";
            }
            cout<<"\n";
        }
    }   
}