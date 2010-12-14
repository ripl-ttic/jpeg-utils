#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jpeglib.h>
#include <jerror.h>

#include "jpeg-utils.h"
#include "jpeg-utils-ijg.h"

#ifdef USE_IPP
#include <ipp.h>
#include <ippcore.h>
#include "ipp/jpeg-utils-ipp.h"
static int ipp_initialized = 0;

static inline void initIpp() {
    if (!ipp_initialized) {
        ippStaticInit();
        ipp_initialized = 1;
    }
}
#endif

int
jpeg_decompress_8u_rgb (const uint8_t * src, int src_size,
        uint8_t * dest, int width, int height, int stride)
{
#ifdef USE_IPP
    initIpp();
    return jpegipp_decompress_8u_rgb (src, src_size, dest, width, height, stride);
#else
    return jpegijg_decompress_8u_rgb (src, src_size, dest, width, height, stride);
#endif
}

int
jpeg_decompress_8u_gray (const uint8_t * src, int src_size,
        uint8_t * dest, int width, int height, int stride)
{
#ifdef USE_IPP
    initIpp();
    return jpegipp_decompress_8u_gray (src, src_size, dest, width, height, stride);
#else
    return jpegijg_decompress_8u_gray (src, src_size, dest, width, height, stride);
#endif
}

int
jpeg_compress_8u_gray (const uint8_t * src, int width, int height, int stride,
        uint8_t * dest, int * destsize, int quality)
{
#ifdef USE_IPP
    initIpp();
    return jpegipp_compress_8u_gray (src, width, height, stride, dest, destsize, quality);
#else
    return jpegijg_compress_8u_gray (src, width, height, stride, dest, destsize, quality);
#endif
}

int
jpeg_compress_8u_rgb (const uint8_t * src, int width, int height, int stride,
        uint8_t * dest, int * destsize, int quality)
{
#ifdef USE_IPP
    initIpp();
    return jpegipp_compress_8u_rgb(src, width, height, stride, dest, destsize, quality);
#else
    return jpegijg_compress_8u_rgb(src, width, height, stride, dest, destsize, quality);
#endif
}

const char* 
jpeg_get_backend_name(void)
{
#ifdef USE_IPP
    return "IPP";
#else
    return "libjpeg";
#endif
}
