#ifndef MATHUTILS_H // if MATHUTILS_H is not defined yet continue below
#define MATHUTILS_H // define MATHUTILS_H, so next time it wont get in the if statement

int sum(int a, int b);

#endif // end if statement, similar to closing bracket }

// this ensures that if this header file
// is included multiple times in the same translation unit,
// the contents of the file will only be included once,
// preventing redefinition errors and other issues 
// that can arise from multiple inclusions.