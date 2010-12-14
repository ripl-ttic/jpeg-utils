#ifndef _jpeg_utils_h_
#define _jpeg_utils_h_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @defgroup JpegUtils JPEG Utilities
 * @brief Convenience functions for JPEG compression / decompression.
 *
 * Uses IPP if available (detected at library compile time), and falls back
 * to libjpeg if not.
 */

/**
 * Decompress JPEG data into an 8-bit RGB buffer.
 */
int jpeg_decompress_8u_rgb (const uint8_t * src, int src_size,
        uint8_t * dest, int width, int height, int stride);

/**
 * Decompress JPEG data into an 8-bit grayscale buffer.  If the original JPEG image
 * contained color data, the color values are discarded and only the Y channel
 * is decompressed.  This is faster than decompressing to RGB and converting to
 * grayscale.
 */
int jpeg_decompress_8u_gray (const uint8_t * src, int src_size,
        uint8_t * dest, int width, int height, int stride);

/**
 * JPEG compress 8-bit grayscale data.
 */
int jpeg_compress_8u_gray (const uint8_t * src, int width, int height, int stride,
        uint8_t * dest, int * destsize, int quality);

/**
 * JPEG compress 8-bit grayscale data.
 */
int jpeg_compress_8u_rgb (const uint8_t * src, int width, int height, int stride,
        uint8_t * dest, int * destsize, int quality);

/**
 * Returns one of "libjpeg", "IPP"
 */
const char* jpeg_get_backend_name(void);

#ifdef __cplusplus
}
#endif

#endif
