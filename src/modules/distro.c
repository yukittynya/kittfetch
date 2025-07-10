#include <stdio.h>
#include <string.h>

#include "modules.h"

Result getDistro() {
    static char buffer[32];
    const char* releaseFiles[] = {
        "/etc/os-release",
        "/etc/lsb-release",
        "/etc/arch-release",
        "/etc/debian-release",
        "/etc/redhat--release",
        NULL
    };

    for (int i = 0; releaseFiles[i] != NULL; i++) {
        FILE* fptr = fopen(releaseFiles[i], "r");

        if (fptr) {
            char line[128];

            while (fgets(line, sizeof(line), fptr)) {
                if (strncmp(line, "NAME", 5)) {
                    char* value = line + 6;
                    value[strlen(value) - 2] = '\0';

                    strncpy(buffer, value, sizeof(buffer) - 1);
                    buffer[sizeof(buffer) - 1] = '\0';
                    fclose(fptr);

                    return ok(buffer);
                }
            }
        }
    } 

    return err("Could not get distro");
}
