
#include <iostream>
using namespace std;

int main() {
    int table[10][5];
    int count[10] = {0};

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 5; j++)
            table[i][j] = -1;

    int a[] = {25, 35, 17, 27, 40};

    for (int x : a) {
        int pos = x % 10;
        table[pos][count[pos]] = x;
        count[pos]++;
    }

    cout << "Hash Table:\n";

    for (int i = 0; i < 10; i++) {
        cout << i << " : ";

        for (int j = 0; j < count[i]; j++)
            cout << table[i][j] << " ";

        cout << endl;
    }

    return 0;
}
