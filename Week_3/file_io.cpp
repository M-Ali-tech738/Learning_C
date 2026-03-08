#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("c_cp_properties.json");
    string line;
    
    if (!file) {
        cout << "Error: File not found!" << endl;
        return 1;
    }
    
    cout << "Contents of c_cpp_properties.json:\n\n";

    while (getline(file, line)) {
        cout << line << endl;
    }
    cout<<endl;
    file.close();
    return 0;
}

