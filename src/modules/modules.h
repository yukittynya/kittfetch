#ifndef INFO_H 
#define INFO_H 

#include "../utils/result.h"

Result getDistro();
Result getKernel();
Result getKernelVersion();
Result getKernelVersionRelease();
Result getKernelPretty();

#endif // !INFO_H
