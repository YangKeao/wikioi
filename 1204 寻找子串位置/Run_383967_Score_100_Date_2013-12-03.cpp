#include <iostream>
#include <string.h>
using namespace std;
char a[100], b[100];
int main() {
    cin >> a >> b;
    char *cursor = strstr(a, b);
    cout << cursor - a + 1 << endl;
    return 0;
}
