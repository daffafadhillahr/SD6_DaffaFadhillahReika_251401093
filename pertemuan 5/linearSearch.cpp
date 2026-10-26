#include <iostream>
using namespace std;

int main() {
    system("cls"); 
    int arr[10] = {22, 9, 10, 27, 38, 75, 54, 90, 88, 41};
    int flag = 0, cari, i;

    cout << "Masukkan nilai yang ingin dicari:"; 
    cin >> cari; 

    for (i = 0; i <  (sizeof(arr)/sizeof(arr[0])); i++) {
        if (arr[i] == cari) {
            flag = 1; 
            break; 
        }
    }

    if (flag == 1) {
        cout << "Data ditemukan di index: " << i << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}