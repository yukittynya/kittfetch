#include <stdio.h>
#include <string.h>

#include "info.h"

Result getKernel() {
    char buffer[32];
    FILE* fptr = popen("uname -r", "r");

    if (fptr == NULL) {
         return err("ERROR: info/kernel.c popen()");
    }

    fgets(buffer, sizeof(buffer), fptr);

    buffer[sizeof(buffer) - 1] = '\0';

    fclose(fptr);
    return ok(buffer);
}

Result getKernelVersion() {
    static char buffer[8];
    FILE* fptr = popen("uname -r | rev | cut -d '-' -f1 | rev | sed 's/.*/\\u&/'", "r");

    if (fptr == NULL) {
         return err("ERROR: info/kernel.c popen()");
    }

    fgets(buffer, sizeof(buffer), fptr);

    buffer[sizeof(buffer) - 1] = '\0';

    pclose(fptr);
    return ok(buffer);
}

Result getKernelVersionNumber() {
    static char buffer[8];
    FILE* fptr = popen("uname -r | cut -d '-' -f1", "r");

    if (fptr == NULL) {
         return err("ERROR: info/kernel.c popen()");
    }

    fgets(buffer, sizeof(buffer), fptr);

    buffer[sizeof(buffer) - 1] = '\0';

    pclose(fptr);
    return ok(buffer);
}

Result getKernelPretty() {
    static char buffer[16] = "";

    Result versionNumber = getKernelVersionNumber();
    memmove(buffer + strlen(buffer), versionNumber.data, strlen(versionNumber.data) - 1);

    strcat(buffer, " "); 

    Result version = getKernelVersion();
    memmove(buffer + strlen(buffer), version.data, strlen(version.data) - 1);

    buffer[sizeof(buffer) - 1] = '\0';

    return ok(buffer);
}
