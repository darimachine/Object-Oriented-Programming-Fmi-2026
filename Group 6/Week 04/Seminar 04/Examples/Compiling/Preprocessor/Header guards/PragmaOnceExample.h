#pragma once  
/*  
    #pragma once ensures this file is included only once during compilation
    does the same as the header guards, and is the more modern approach in C++
*/

// This is the content of the header file
class PragmaOnceExample {
public:
    PragmaOnceExample();
    void sayHello();
    // ...
};
