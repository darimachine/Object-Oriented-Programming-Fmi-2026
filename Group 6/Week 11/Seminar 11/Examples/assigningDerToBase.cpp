class Base {
    // ...
};

class Der : public Base {
    // ...
};

void receiveBaseCopy(Base b) {
    // ...
}

void receiveBaseRef(const Base& ref) {
    // ...
}

void receiveBasePtr(Base* ptr) {
    // ...
}

void receiveDerCopy(Der d) {
    // ...
}

void receiveDerRef(const Der& ref) {
    // ...
}

void receiveDerPtr(Der* ptr) {
    // ...
}

int main() {
    Base base;
    Der der;

    Base* ptr = &der; // ok
    Base& ref = der; // ok
    Der* derPtr = &base; // error
    Der& derRef = base; // error
    
    receiveBaseCopy(der); // ok
    receiveBaseRef(der); // ok
    receiveBasePtr(&der); // ok
    receiveDerCopy(der); // ok
    receiveDerRef(der); // ok
    receiveDerPtr(&der); // ok
    
    receiveBaseCopy(base); // ok
    receiveBaseRef(base); // ok
    receiveBasePtr(&base); // ok
    receiveDerCopy(base); // compilation error
    receiveDerRef(base); // compilation error
    receiveDerPtr(&base); // compilation error

    // the base pointer points towards Base part and does not know about the Der part of the object,
    // therefore the functions that receive Der can't be called with Base ! ! !
    // the other way round works ( passing Der to functions that receive Base )
}
