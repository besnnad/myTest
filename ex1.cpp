#include <memory>
#include <iostream>
using namespace std;

class EP {
public:
    EP(int id) : id_(id) {}

    int id_;
};

typedef EP* PEP;

int main() {
    void *rawMemory = operator new[](10 * sizeof(EP));
    PEP bestPieces = static_cast<PEP>(rawMemory);

    for (int i = 0; i < 10 ; ++i) {
        new (&bestPieces[i]) EP(i);
        cout << bestPieces[i].id_ << endl;
    }

    for (int i = 9; i >= 0; --i) {
        bestPieces[i].~EP();
    }

    operator delete[](rawMemory);

    return 0;
}