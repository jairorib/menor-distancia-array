#include <iostream>
#include <map>

using namespace std;

int diferenca(int a, int b) {

  if (a < 0) {
    return -a + b;
  }
  if (b < 0) {
    return -b + a;
  }

  if (a < b) {
    return b - a;
  }
  return a - b;
}

int main() {
    map<int, int> obj;
    vector<int> array1;
    vector<int> array2;

    int m = 0;
    int n = 0;
    int numero;

    int i = 0;

    while (i < 20) {
       cout << "Qual o número para o " << m +1 << "° elemento do array " << n + 1 << endl;
       cin >> numero;
       cin.ignore(INT_MAX, '\n');
       if (obj.find(numero) == obj.end()) {
         if (array1.size() < 10){
           array1.emplace_back(numero);
         } else {
           array2.emplace_back(numero);
         }
         obj[numero] = numero;
         if (i > 8 && n != 1) {
           m = -1;
           n = 1;
         }
         i++;
         m++;
       } else {
         cout << "O número já existe! Digite um número diferente." << endl;
       }
    }

    cout << "\nArray 1 -> [";
    for (const auto& pair : array1) {
       cout << pair << ",";
    }
    cout << "]\nArray 2 -> [";
    for (const auto& pair : array2) {
       cout << pair << ",";
    }

    cout << "]" << endl;
    int index1 = 0;
    int index2 = 0;
    for (int i = 0;i < array1.size();i++) {
       for (int j = 0;j < array2.size();j++) {
          if (diferenca(array1[i], array2[j]) < diferenca(array1[index1], array2[index2])) {
             index1 = i;
             index2 = j;
          }
       }
    }

    cout << "\nA menor distância está na combinação do número " << array1[index1] << " do array 1 com o número " << array2[index2] << " do array 2, que é " << diferenca(array1[index1], array2[index2]) << " de distância" << endl;

    return 0;
}


