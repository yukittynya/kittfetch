#include <stdio.h>
#include <sys/utsname.h>

#include "info.h"

Result getKernel() {
    static char buffer[32];
    struct utsname info;

    if (uname(&info) != 0) {
        return err("ERROR - kernel.c in getKernel() ");
    }

    snprintf(buffer, sizeof(buffer), "%s", info.release);
    return ok(buffer);
}

Result getKernelVersion() {
    static char buffer[16];
    struct utsname info;
    
    if (uname(&info) != 0) {
        return err("ERROR - kernel.c in getKernelVersion() ");
    }

    for (int i = strlen(info.release); i > 0; i--) {
        if (info.release[i] == '-') {
            char* line = info.release + i + 1;

            if (line[0] > 90) {
                line[0] -= 32;
            }
            
            snprintf(buffer, sizeof(buffer), "%s", line);
            return ok(buffer);
        }
    }

    return err("Not found");
    
}

Result getKernelVersionRelease() {
    static char buffer[16];
    struct utsname info;
    
    if (uname(&info) != 0) {
        return err("ERROR - kernel.c in getKernelVersionRelease() ");
    }
    
    char* dash = strchr(info.release, '-');

    if (dash) {
        size_t len = dash - info.release;

        if (len < sizeof(buffer)) {
            strncpy(buffer, info.release, len);
            buffer[len] = '\0';
        }
    } else {
        snprintf(buffer, sizeof(buffer), "%s", info.release);
    }
    
    return ok(buffer);
}

Result getKernelPretty() {
    static char buffer[64];
    
    Result release = getKernelVersionRelease();
    if (IS_ERR(release)) return release;
    
    Result version = getKernelVersion();
    if (IS_ERR(version)) return version;

    snprintf(buffer, sizeof(buffer), "%s %s", (char*)release.data, (char*)version.data);
    
    return ok(buffer);
}
