#include <iostream>
using namespace std;

int main() {
    string a, b, c;
    int i = 0, j = 0, k = 0, m = 0, n = 0;
    int flag = 0;

    cout << "Enter a string: ";
    cin >> a;

    cout << "Enter a substring to delete: ";
    cin >> b;

    // Calculate the length of the substring b
    while (b[m] != '\0') {
        m++;
    }

    // Loop through the main string a
    for (i = 0; a[i] != '\0'; i++) {
        k = i;
        // Compare the substring b with the current part of the main string a
        while (a[i] == b[j]) {
            i++;
            j++;
            if (j == m) { // If the substring is fully matched
                flag = 1;
                break;
            }
        }

        j = 0; // Reset j for the next comparison

        if (flag == 0) {
            i = k; // If no match found, reset i to k
            c += a[i]; // Append the current character to the result string c
        } else {
            flag = 0; // Reset flag for the next possible match
        }
    }

    cout << "String after deletion: " << c << endl;

    return 0;
}
