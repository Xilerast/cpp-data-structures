#include <stdlib.h>
#include "Stack.hpp"

int main(int argc, char **argv) {
    Stack<int> s1 = Stack<int>{5}, s2;
    for (int i = 1; i <= 5; i++) {
        s1.Push(i);
    }
    s2 = s1;

    exit(EXIT_SUCCESS);
}