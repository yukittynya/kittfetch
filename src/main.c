#include <stdio.h>

#include "modules/modules.h"

int main(int argc, char *argv[]) {
    Result distro = getDistro();
    Result kernel = getKernelPretty();

    printf("distro: %s\n", (char*) distro.data);
    printf("kernel: %s", (char*) kernel.data);
}
