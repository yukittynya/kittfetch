#ifndef INFO_H 
#define INFO_H 

#include "../utils/result.h"

Result getDistro();
Result getKernel();
Result getKernelVersion();
Result getKernelVersionNumber();
Result getKernelPretty();

#endif // !INFO_H
