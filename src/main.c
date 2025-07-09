#include <stdio.h>

#include "info/info.h"

int main(int argc, char *argv[]) {
    Result distro = getDistro();

    printf("Distro: %s", (char*) distro.data);
}
