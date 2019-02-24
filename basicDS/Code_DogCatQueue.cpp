#include <iostream> 
#include <stdio.h>

using namespace std;  

class pet {
protected: 
    string type;

public:
    pet(string category) {
        this->type = category;
    }
    string getPetType() {
        return this->type;
    }
};

class dog: public pet {
public:
    dog(): pet("dog") {}
};

class cat: public pet {
public:
    cat(): pet("cat") {}
};

class dog

