#include <iostream>
#include <string>
using namespace std;

int main() {
    int numCategories;
    cout << "Enter number of book categories: ";
    cin >> numCategories;

    // Array to store category names
    string* categoryNames = new string[numCategories];

    // Jagged array for book IDs
    int** bookIDs = new int*[numCategories];
    int* booksPerCategory = new int[numCategories]; // To store number of books per category

    // Input for each category
    for (int i = 0; i < numCategories; i++) {
        cout << "Enter name for category #" << i + 1 << ": ";
        cin.ignore();  
        getline(cin, categoryNames[i]);

        cout << "Enter number of books in " << categoryNames[i] << ": ";
        cin >> booksPerCategory[i];

        bookIDs[i] = new int[booksPerCategory[i]];

        cout << "Enter " << booksPerCategory[i] << " book IDs:\n";
        for (int j = 0; j < booksPerCategory[i]; j++) {
            cout << "  Book ID " << j + 1 << ": ";
            cin >> bookIDs[i][j];
        }
    }

    // Book Search
    int searchID;
    cout << "\nEnter Book ID to search: ";
    cin >> searchID;

    bool found = false;
    for (int i = 0; i < numCategories; i++) {
        for (int j = 0; j < booksPerCategory[i]; j++) {
            if (bookIDs[i][j] == searchID) {
                cout << " Book ID " << searchID << " is available in category: " << categoryNames[i] << endl;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        cout << "Book ID " << searchID << " not found in any category.\n";
    }

    
    for (int i = 0; i < numCategories; i++) {
        delete[] bookIDs[i];
    }
    delete[] bookIDs;
    delete[] booksPerCategory;
    delete[] categoryNames;

    return 0;
}
