    #include <iostream>
    using namespace std;
    int main(){
        int N,M,i,j;
        cout<<"Please enter the number of rows and coloumns of the matrix: ";
        cin>>N>>M;
        int matrix1[N][M];
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                cout<<"Please enter element"<<i<<j<<"\t";
                cin>>matrix1[i][j];
            }
        }
        int transpose[M][N];
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                transpose[j][i] = matrix1[i][j];
            }
        }
        for(i=0;i<M;i++){
            for(j=0;j<N;j++){
                cout<<transpose[i][j]<<"\t";
            }
            cout<<"\n";
        }
    }