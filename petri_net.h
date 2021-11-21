#ifndef PETRINET
#define PETRINET

// Library
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Place {
private:
    int nTokens;
    string name;

public:
    Place(string, int);
    void addToken(int);
    void minusToken(int);
    int getToken();
    ~Place(){};

    friend class Net;
};

class Transition {
private:
    string name;
    vector<Place*> in;
    vector<Place*> out;

public:
    Transition(string n) : name(n){};
    void addArcOut(Place*);
    void addArcIn(Place*);
    bool isEnabled();
    void firing();

    friend class Net;
};

class Net {
private:
    vector<Place*> p;
    vector<Transition*> t;

    Place* getPlace(string);
    Transition* getTrans(string);
    void addArcOut(string, string);
    void addArcIn(string, string);

public:
    Net() {}
    void addPlace(string, int);
    void addTransition(string name);
    void addArc(string sou, string des);
    bool changStage();
    string toString();
};

#endif