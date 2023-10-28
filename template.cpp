
#include <vector>
#include <map>

#include <iostream>

using namespace  std;

int main(int argc, char* argv[]) {

    if (argc != 2) {
        cout << "usage: " << argv[0] << " n" << endl;
        return 1;
    }

    int n = stoi(argv[1]);
    cout << "n: " << n << endl;

    return 0;
}
