#include <fstream>

using namespace std;

// Example of how to write on files using cpp.
void writeHello() {
    ofstream writer("writer_test.txt");
    writer << "Hello disk" << endl;
}

int main() {
    writeHello();

    return 0;
}