#include "petri_net.cpp"
#include "petri_net.h"
using namespace std;

int main() {
    Net n;
    n.addPlace("pFree", 1);
    n.addPlace("pBusy");
    n.addPlace("pDocu");

    n.addTransition("tStart");
    n.addTransition("tChange");
    n.addTransition("tEnd");

    n.addArc("pFree", "tStart");
    n.addArc("tStart", "pBusy");
    n.addArc("pBusy", "tChange");
    n.addArc("tChange", "pDocu");
    n.addArc("pDocu", "tEnd");
    n.addArc("tEnd", "pFree");

    int c = 0;
    while (true) {
        if (c == 3) break;
        cout << n.toString() << endl;
        bool changed = n.changStage();
        c++;

    }
}