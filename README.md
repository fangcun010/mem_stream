mem_stream
==================================
Memory streams written in C

API
******

MEM_STREAM_API int mem_stream_open(mem_stream_t* stream, void* buffer, uint32_t buffer_size, uint32_t size, uint32_t usage);
MEM_STREAM_API void mem_stream_close(mem_stream_t* stream);
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