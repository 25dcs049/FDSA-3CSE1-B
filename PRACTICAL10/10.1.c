
#include <iostream>
using namespace std;

int main() {
    int table[10];

    for (int i = 0; i < 10; i++)
        table[i] = -1;

    int a[] = {25, 35, 17, 27, 40};

    for (int x : a) {
        int pos = x % 10;

        while (table[pos] != -1)
            pos = (pos + 1) % 10;

        table[pos] = x;
    }

    cout << "Hash Table:\n";

    for (int i = 0; i < 10; i++)
        cout << i << " : " << table[i] << endl;

    return 0;
}
