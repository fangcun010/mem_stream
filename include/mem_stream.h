/*MIT License

Copyright (c) 2021 fangcun

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

#ifndef MEM_STREAM_H_
#define MEM_STREAM_H_

#include <stdint.h>

#ifdef __cplusplus
#define MEM_STREAM_API  extern "C"
#else
#define MEM_STREAM_API
#endif

#define     MEM_STREAM_OK                       0
#define     MEM_STREAM_ERROR                    1

#define     MEM_STREAM_INPUT                    0x01
#define     MEM_STREAM_OUTPUT                   0x02
#define     MEM_STREAM_COPY_DATA                0x04

typedef struct {
    uint32_t usage;
    void* buffer;
    uint32_t buffer_size;
    uint32_t size;
    uint32_t position;
} mem_stream_t;

MEM_STREAM_API int mem_stream_open(mem_stream_t* stream, void* buffer, uint32_t buffer_size, uint32_t size, uint32_t usage);
MEM_STREAM_API void mem_stream_close(mem_stream_t* stream);
MEM_STREAM_API void* mem_stream_data(mem_stream_t* stream);
MEM_STREAM_API uint32_t mem_stream_position(mem_stream_t* stream);
MEM_STREAM_API void mem_stream_skip(mem_stream_t* stream, uint32_t skip);
MEM_STREAM_API void mem_stream_seek(mem_stream_t* stream, uint32_t position);
MEM_STREAM_API uint32_t mem_stream_size(mem_stream_t* stream);
MEM_STREAM_API int8_t mem_stream_read_int8(mem_stream_t* stream);
MEM_STREAM_API uint8_t mem_stream_read_uint8(mem_stream_t* stream);
MEM_STREAM_API int16_t mem_stream_read_int16(mem_stream_t* stream);
MEM_STREAM_API uint16_t mem_stream_read_uint16(mem_stream_t* stream);
MEM_STREAM_API int32_t mem_stream_read_int32(mem_stream_t* stream);
MEM_STREAM_API uint32_t mem_stream_read_uint32(mem_stream_t* stream);
MEM_STREAM_API int64_t mem_stream_read_int64(mem_stream_t* stream);
MEM_STREAM_API uint64_t mem_stream_read_uint64(mem_stream_t* stream);
MEM_STREAM_API float mem_stream_read_float(mem_stream_t* stream);
MEM_STREAM_API double mem_stream_read_double(mem_stream_t* stream);
MEM_STREAM_API void mem_stream_read(mem_stream_t* stream, void* buffer, uint32_t size);
MEM_STREAM_API void mem_stream_write_int8(mem_stream_t* stream, int8_t val);
MEM_STREAM_API void mem_stream_write_uint8(mem_stream_t* stream, uint8_t val);
MEM_STREAM_API void mem_stream_write_int16(mem_stream_t* stream, int16_t val);
MEM_STREAM_API void mem_stream_write_uint16(mem_stream_t* stream, uint16_t val);
MEM_STREAM_API void mem_stream_write_int32(mem_stream_t* stream, int32_t val);
MEM_STREAM_API void mem_stream_write_uint32(mem_stream_t* stream, uint32_t val);
MEM_STREAM_API void mem_stream_write_int64(mem_stream_t* stream, int64_t val);
MEM_STREAM_API void mem_stream_write_uint64(mem_stream_t* stream, uint64_t val);
MEM_STREAM_API void mem_stream_write_float(mem_stream_t* stream, float val);
MEM_STREAM_API void mem_stream_write_double(mem_stream_t* stream, double val);
MEM_STREAM_API void mem_stream_write(mem_stream_t* stream, void* buffer, uint32_t size);

#endif