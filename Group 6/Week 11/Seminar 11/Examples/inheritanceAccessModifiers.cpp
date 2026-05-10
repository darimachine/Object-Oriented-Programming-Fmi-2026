class Base {
public:
    int x = 0;
protected:
    int y = 0;
private:
    int z = 0;
};

class A : public Base {
    // x is public
    // y is protected
    // no acces to z ( z is private in Base)
};

class B : protected Base {
    // x is protected
    // y is protected
    // no access to z :(
};

class C : private Base {
    // x is private
    // y is private
    // no access to z :(
};

class D : Base {
    // if we don't specify explicitly, the inheritance is private by default!!!
    // same as C:
    // x is private
    // y is private
    // no access to z :(

    // this is different from structs, where the inheritance by default is public...
};
