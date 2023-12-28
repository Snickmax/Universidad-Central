/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

void combinarVector(vector<int> &v, vector<int> &izq, vector<int> &der) {
    int i = 0;
    int j = 0;
    for (int k = 0; k < v.size(); k++) {
        if (i >= izq.size()) {
            v[k] = der[j];
            j++;
            continue;
        }
        if (j >= der.size()) {
            v[k] = izq[i];
            i++;
            continue;
        }
        if (izq[i] < der[j]) {
            v[k] = izq[i];
            i++;
        } else {
            v[k] = der[j];
            j++;
        }
    }
}

void ordenacionMergeSort(vector<int> &vec) {
    if (vec.size() <= 1)
        return;
    int mitad = vec.size() / 2;
    vector<int> izq(vec.begin(), vec.begin() + mitad);
    vector<int> der(vec.begin() + mitad, vec.end());
    ordenacionMergeSort(izq);
    ordenacionMergeSort(der);
    combinarVector(vec, izq, der);
}

void imprimirVector(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> vec = {2, 4, 5, 7, 1, 2, 3, 6};
    cout << "Vector original" << endl;
    imprimirVector(vec);
    cout << "\nVector ordenado" << endl;
    ordenacionMergeSort(vec);
    imprimirVector(vec);
    return 0;
}