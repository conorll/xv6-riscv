#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int main() {
    printf("%d\n", getreadcount());
    return 0;
}