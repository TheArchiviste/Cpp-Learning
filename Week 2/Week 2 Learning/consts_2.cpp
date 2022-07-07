#include<iostream>

using namespace std;

#if 0
int main() {
    int const VAT = 20;
    // Way to break the the const rule!!!
    int * a = (int *) & VAT;

    *a = 40;

    cout << *a << endl;
    // Always safe guard the code!!!

    return 0;
}
#endif

// Guards the content!!!
#if 0
int main() {
    int var1 = 10;
    int var2 = 40;

    int const *a = &var1;   // What is the pointer pointing to

    cout << *a << endl;

    a = &var2;              // The actual content of the variable !!!

    cout << *a << endl;

    return 0;
}
#endif

// Guards the pointer !!!
#if 0
int main() {
    int var1 = 10;
    int var2 = 40;

    int * const a = &var1;   // a is a constant pointer to a memory
                             // protects the pointer from being swap to where in memory is pointing!!!!
    cout << *a << endl;

    *a = 36;

    cout << *a << endl;

    return 0;
}
#endif

// Guards both !!!
#if 1
int main() {
    int var1 = 10;
    int var2 = 40;

    int const * const a = &var1;

    cout << *a << endl;

    return 0;
}
#endif

/* The East const West const Rule

    East const -> What is left on the const is constant!!!
    
    int const c = 1;  SAME  const int c = 1;

    int const& cr = i;  SAME  const int& cr = i;

    int const * c = &i;  SAME  const int * c = &i;

    int * const c = &i;  SAME  int const * c = &i;
    int const * const c = &i;  SAME  const int * const c = &i;
 */