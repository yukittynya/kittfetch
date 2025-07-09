#include <stdio.h>

#include "info.h"
#include "../utils/result.h"

Result getDistro() {
    char buffer[64];
    FILE* fptr = popen("cat /etc/*-release | grep NAME | head -n1 | cut -d '=' -f2 | tr -d '\"'", "r");

    if (fptr == NULL) {
        return err("ERROR: sysinfo/distro.c, popen() failed");
    }

    fgets(buffer, sizeof(buffer), fptr);

    pclose(fptr);
    return ok(buffer);
}
