#ifndef __jpeg_utils_ipp_h__
#define __jpeg_utils_ipp_h__

#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

int jpegipp_compress_8u_gray (const uint8_t * src, int width, 
        int height, int stride, uint8_t * dest, int * destsize, int quality);

int jpegipp_compress_8u_rgb (const uint8_t * src, int width, 
        int height, int stride, uint8_t * dest, int * destsize, int quality);

int jpegipp_compress_8u_bgra (const uint8_t * src, int width, 
        int height, int stride, uint8_t * dest, int * destsize, int quality);

int jpegipp_decompress_8u_rgb (const uint8_t * src, int src_size,
        uint8_t * dest, int width, int height, int stride);

#ifdef __cplusplus
}
#endif

#endif
