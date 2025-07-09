#include <stdio.h>

#include "info.h"

Result getDistro() {
    static char buffer[32];
    FILE* fptr = popen("cat /etc/*-release | grep NAME | head -n1 | cut -d '=' -f2 | tr -d '\"'", "r");

    if (fptr == NULL) {
        return err("ERROR: sysinfo/distro.c, popen() failed");
    }

    fgets(buffer, sizeof(buffer), fptr);

    buffer[sizeof(buffer) - 1] = '\0';

    pclose(fptr);
    return ok(buffer);
}
