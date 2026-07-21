#include "global.h"
#include "decompress_error_handler.h"

extern uintptr_t gDecompressCallerLR;
uintptr_t gDecompressErrorLR; // latched only on real errors, for debugging
u32 gDecompressErrorSrc;

void DecompressionError(const u32 *src, enum CompressionError error)
{
    gDecompressErrorLR = gDecompressCallerLR;
    gDecompressErrorSrc = (u32)src;
    errorf("Decompression failed.\nAddress: 0x%p\nError: 0x%x\nCaller: 0x%x\n", src, error, (u32)gDecompressCallerLR);
}

void DoDecompressionError(void)
{
    DecompressionError((u32 *)0x12345678, HEADER_ERROR);
}
