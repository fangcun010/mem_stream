mem_stream
==================================
Memory streams written in C

API
******

int mem_stream_open(mem_stream_t* stream, void* buffer, uint32_t buffer_size, uint32_t size, uint32_t usage);

void mem_stream_close(mem_stream_t* stream);

void mem_stream_data(mem_stream_t* stream);

void mem_stream_position(mem_stream_t* stream);

void mem_stream_seek(mem_stream_t* stream, uint32_t position);

uint32_t mem_stream_size(mem_stream_t* stream);

int8_t mem_stream_read_int8(mem_stream_t* stream);

uint8_t mem_stream_read_uint8(mem_stream_t* stream);

int16_t mem_stream_read_int16(mem_stream_t* stream);

uint16_t mem_stream_read_uint16(mem_stream_t* stream);

int32_t mem_stream_read_int32(mem_stream_t* stream);

uint32_t mem_stream_read_uint32(mem_stream_t* stream);

int64_t mem_stream_read_int64(mem_stream_t* stream);

uint64_t mem_stream_read_uint64(mem_stream_t* stream);

float mem_stream_read_float(mem_stream_t* stream);

double mem_stream_read_double(mem_stream_t* stream);

void mem_stream_read(mem_stream_t* stream, void* buffer, uint32_t size);

void mem_stream_write_int8(mem_stream_t* stream, int8_t val);

void mem_stream_write_uint8(mem_stream_t* stream, uint8_t val);

void mem_stream_write_int16(mem_stream_t* stream, int16_t val);

void mem_stream_write_uint16(mem_stream_t* stream, uint16_t val);

void mem_stream_write_int32(mem_stream_t* stream, int32_t val);

void mem_stream_write_uint32(mem_stream_t* stream, uint32_t val);

void mem_stream_write_int64(mem_stream_t* stream, int64_t val);

void mem_stream_write_uint64(mem_stream_t* stream, uint64_t val);

void mem_stream_write_float(mem_stream_t* stream, float val);

void mem_stream_write_double(mem_stream_t* stream, double val);

void mem_stream_write(mem_stream_t* stream, void* buffer, uint32_t size);
