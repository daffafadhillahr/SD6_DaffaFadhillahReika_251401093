// Interpolation Search
#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int data[7] = {10, 13, 17, 34, 58, 67, 99};

  int cari, posisi;
  float posisi1;
  int N = 7, flag = 0, low = 0, high = N - 1;

  cout << "Masukkan data yang ingin dicari = ";
  cin >> cari;

  do {
    posisi1 = float(cari - data[low]) / (data[high] - data[low]) * (high - low) + low;
    posisi = (floor(posisi1));
    // cout << data[posisi] << endl;
    if (data[posisi] == cari) {
      flag = 1;
      break;
    }

    if (data[posisi] > cari)
      high = posisi - 1;
    else if (data[posisi] < cari)
      low = posisi + 1;

  } while (low <= high && cari >= data[low] && cari <= data[high]);

  if (flag == 1)
    cout << "Data ditemukan!\n\n";
  else
    cout << "Data tidak ditemukan!\n\n";
}