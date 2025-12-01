#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {

    // defining an fixed array of characters.
    char text[200];

    cout << "Enter a statement to write to file.txt: ";
    cin.getline(text, 200);         
    

    // Get the lenght of the text entered from the user.
    int length = strlen(text);      

    // Write using ofstream with the mode write 
    ofstream myOutputText("file.txt", ios::out);

    if (!myOutputText) {
        cout << "Error opening text file for writing.\n";
    } else {
        myOutputText << text; // insertion operator
        myOutputText.close();
        cout << "Done, writing to the file!" << endl;
        cout << "stream close!" << endl;
    }


    ifstream inputText("file.txt", ios::in);

    if (!inputText) {
        cout << "Error opening text file for reading.\n";
    } else {
        char readText[200];
        inputText.getline(readText, 200);
        // myInputText >> readText; // extraction opertator
        inputText.close();

        cout << "Reading from file.txt: " << readText << endl;
    }

    // Output from ofstream with write mode exclusive or out and binary
    ofstream OutputBinary("file.bat", ios::out | ios::binary);

    if (!OutputBinary) {
        cout << "Error opening binary file for writing" <<endl;
    
    } else {
        OutputBinary.write(text, length);   // write the char array
        OutputBinary.close();
        cout << "Done writing in file.bat" <<endl;
        cout << "closing the stream" <<endl;
    }

    // input from ifstream with write mode exclusive or out and binary
    ifstream InputBinary("file.bat", ios::in | ios::binary);

    if (!InputBinary) {
        cout << "cannot open binary file for reading" <<endl;
    } else {
        char readBinary[200];
        InputBinary.read(readBinary, length);
        readBinary[length] = '\0';    // add null terminator

        InputBinary.close();

        cout << "Read from Binary file: " << readBinary << endl;
        cout << "Closing the stream!" << endl;
    }

    return 0;
}
