#include <stdint.h>
#include <stdio.h>
#include <climits>

#include "types.h"
#include <fuzzer/FuzzedDataProvider.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    uint64_t x = provider.ConsumeIntegral<uint64_t>();
    __local_bswap64(x);
    return 0;
}