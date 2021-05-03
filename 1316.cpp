#include <iostream>
#include <cstring>
using namespace std;
char word[101];
int n, len, ans, flag;
int main() {
    cin >> n;
    ans = n;
    for (int i = 0; i < n; i++) {
        flag = 0;
        cin >> word;
        len = strlen(word);
        for (int j = 0; word[j] != NULL; j++) {
            if (word[j] != word[j + 1]) {
                for (int k = j + 2; k <= len - 1; k++) {
                    if (word[j] == word[k]) {
                        ans--;
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 1) break;
        }
    }
    cout << ans;
}