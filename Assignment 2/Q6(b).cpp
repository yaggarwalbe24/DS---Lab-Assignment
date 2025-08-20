#include <iostream>
using namespace std;
int main() {
    int row, col, arr1[100][100], arr2[100][100];
    int s1[100][3], s2[100][3], add[200][3];
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> col;
    cout << "Enter elements of Matrix 1:\n";
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> arr1[i][j];
    cout << "Enter elements of Matrix 2:\n";
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> arr2[i][j];
    int k = 1, z = 1;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) {
            if (arr1[i][j] != 0) {
                s1[k][0] = i;
                s1[k][1] = j;
                s1[k][2] = arr1[i][j];
                k++;
            }
            if (arr2[i][j] != 0) {
                s2[z][0] = i;
                s2[z][1] = j;
                s2[z][2] = arr2[i][j];
                z++;
            }
        }
    s1[0][0] = s2[0][0] = row;
    s1[0][1] = s2[0][1] = col;
    s1[0][2] = k - 1;
    s2[0][2] = z - 1;
    cout << "\nSparse Matrix 1 (Row Col Value):\n";
    for (int i = 0; i < k; i++)
        cout << s1[i][0] << " " << s1[i][1] << " " << s1[i][2] << "\n";
    cout << "\nSparse Matrix 2 (Row Col Value):\n";
    for (int i = 0; i < z; i++)
        cout << s2[i][0] << " " << s2[i][1] << " " << s2[i][2] << "\n";

    int m = 1, i = 1, j = 1;
    add[0][0] = row;
    add[0][1] = col;
    while (i < k && j < z) {
        if (s1[i][0] < s2[j][0] || (s1[i][0] == s2[j][0] && s1[i][1] < s2[j][1])) {
            for (int p = 0; p < 3; p++)
                add[m][p] = s1[i][p];
            i++;
            m++;
        } else if (s2[j][0] < s1[i][0] || (s1[i][0] == s2[j][0] && s2[j][1] < s1[i][1])) {
            for (int p = 0; p < 3; p++)
                add[m][p] = s2[j][p];
            j++;
            m++;
        } else {
            int sum = s1[i][2] + s2[j][2];
            if (sum != 0) {
                add[m][0] = s1[i][0];
                add[m][1] = s1[i][1];
                add[m][2] = sum;
                m++;
            }
            i++;
            j++;
        }
    }
    while (i < k) {
        for (int p = 0; p < 3; p++)
            add[m][p] = s1[i][p];
        i++;
        m++;
    }
    while (j < z) {
        for (int p = 0; p < 3; p++)
            add[m][p] = s2[j][p];
        j++;
        m++;
    }
    add[0][2] = m - 1;
    cout << "\nAddition Result (Sparse Matrix Form):\n";
    for (int idx = 0; idx < m; idx++)
        cout << add[idx][0] << " " << add[idx][1] << " " << add[idx][2] << "\n";
}
