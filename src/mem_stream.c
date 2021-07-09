#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <mem_stream.h>

static int mem_stream_check_buffer_size(mem_stream_t* stream, uint32_t need_size) {
    if (stream->buffer_size >= need_size)
        return MEM_STREAM_OK;

    if (!(stream->usage & MEM_STREAM_COPY_DATA)) {
        return MEM_STREAM_ERROR;
    }
    
    uint32_t buffer_size = stream->buffer_size * 2 >= need_size ? stream->buffer_size * 2 : need_size;
    void* buffer = malloc(buffer_size);

    if (!buffer)
        return MEM_STREAM_ERROR;

    memcpy(buffer, stream->buffer, stream->size);
    free(stream->buffer);
    stream->buffer = buffer;
    stream->buffer_size = buffer_size;
    
    return MEM_STREAM_OK;
}

MEM_STREAM_API int mem_stream_open(mem_stream_t *stream,void* buffer,uint32_t buffer_size, uint32_t size,uint32_t usage) {
    stream->usage = usage;
    
    if (usage & MEM_STREAM_COPY_DATA) {
        stream->buffer = malloc(buffer_size);
        if (!stream->buffer)
            return MEM_STREAM_ERROR;
        memcpy(stream->buffer, buffer, size);
    }
    else {
        stream->buffer = buffer;
    }

    stream->buffer_size = buffer_size;
    stream->size = size;
    stream->position = 0;
    
    return MEM_STREAM_OK;
}

MEM_STREAM_API void mem_stream_close(mem_stream_t* stream) {
    if (stream->usage & MEM_STREAM_COPY_DATA)
        free(stream->buffer);
}

MEM_STREAM_API void mem_stream_seek(mem_stream_t* stream, uint32_t position) {
    stream->position = position;
}

MEM_STREAM_API uint32_t mem_stream_size(mem_stream_t* stream) {
    return stream->size;
}

MEM_STREAM_API int8_t mem_stream_read_int8(mem_stream_t* stream) {
    assert(stream->usage & MEM_STREAM_INPUT &&
        stream->position<stream->size);

    int8_t val = *(int8_t*)((uint8_t*)stream->buffer + stream->position);
    stream->position += sizeof(val);

    return val;
}

MEM_STREAM_API uint8_t mem_stream_read_uint8(mem_stream_t* stream) {
    assert(stream->usage & MEM_STREAM_INPUT &&
        stream->position < stream->size);

    uint8_t val = *(uint8_t*)((uint8_t*)stream->buffer + stream->position);
    stream->position += sizeof(val);

    return val;
}

MEM_STREAM_API int16_t mem_stream_read_int16(mem_stream_t* stream) {
    assert(stream->usage & MEM_STREAM_INPUT &&
        stream->position < stream->size);

    int16_t val = *(int16_t*)((uint8_t*)stream->buffer + stream->position);
    stream->position += sizeof(val);

    return val;
}

MEM_STREAM_API uint16_t mem_stream_read_uint16(mem_stream_t* stream) {
    assert(stream->usage & MEM_STREAM_INPUT &&
        stream->position < stream->size);

    uint16_t val = *(uint16_t*)((uint8_t*)stream->buffer + stream->position);
    stream->position += sizeof(val);

    return val;
}

MEM_STREAM_API int32_t mem_stream_read_int32(mem_stream_t* stream) {
    assert(stream->usage & MEM_STREAM_INPUT &&
        stream->position < stream->size);

    int32_t val = *(int32_t*)((uint8_t*)stream->buffer + stream->position);
    stream->position += sizeof(val);

    return val;
}

MEM_STREAM_API uint32_t mem_stream_read_uint32(mem_stream_t* stream) {
    assert(stream->usage & MEM_STREAM_INPUT &&
        stream->position < stream->size);

    uint32_t val = *(uint32_t*)((uint8_t*)stream->buffer + stream->position);
    stream->position += sizeof(val);

    return val;
}

MEM_STREAM_API int64_t mem_stream_read_int64(mem_stream_t* stream) {
    assert(stream->usage & MEM_STREAM_INPUT &&
        stream->position < stream->size);

    int64_t val = *(uint64_t*)((uint8_t*)stream->buffer + stream->position);
    stream->position += sizeof(val);

    return val;
}

MEM_STREAM_API uint64_t mem_stream_read_uint64(mem_stream_t* stream) {
    assert(stream->usage & MEM_STREAM_INPUT &&
        stream->position < stream->size);

    uint64_t val = *(uint64_t*)((uint8_t*)stream->buffer + stream->position);
    stream->position += sizeof(val);

    return val;
}

MEM_STREAM_API float mem_stream_read_float(mem_stream_t* stream) {
    assert(stream->usage & MEM_STREAM_INPUT &&
        stream->position < stream->size);

    float val = *(float*)((uint8_t*)stream->buffer + stream->position);
    stream->position += sizeof(val);

    return val;
}

MEM_STREAM_API double mem_stream_read_double(mem_stream_t* stream) {
    assert(stream->usage & MEM_STREAM_INPUT &&
        stream->position < stream->size);

    double val = *(double*)((uint8_t*)stream->buffer + stream->position);
    stream->position += sizeof(val);

    return val;
}

MEM_STREAM_API void mem_stream_read(mem_stream_t* stream, void* buffer, uint32_t size) {
    assert(stream->usage & MEM_STREAM_INPUT &&
        stream->position<stream->size);

    memcpy(buffer, (uint8_t*)stream->buffer + stream->position, size);
    stream->position += size;
}

MEM_STREAM_API void mem_stream_write_int8(mem_stream_t* stream,int8_t val) {
    assert(stream->usage & MEM_STREAM_OUTPUT);
    assert(mem_stream_check_buffer_size(stream, stream->position + sizeof(val)) == 
        MEM_STREAM_OK);

    *(int8_t*)((uint8_t*)stream->buffer + stream->position) = val;
    stream->position += sizeof(val);

    if (stream->position > stream->size)
        stream->size = stream->position;
}

MEM_STREAM_API void mem_stream_write_uint8(mem_stream_t* stream,uint8_t val) {
    assert(stream->usage & MEM_STREAM_OUTPUT);
    assert(mem_stream_check_buffer_size(stream, stream->position + sizeof(val)) ==
        MEM_STREAM_OK);

    *(uint8_t*)((uint8_t*)stream->buffer + stream->position) = val;
    stream->position += sizeof(val);

    if (stream->position > stream->size)
        stream->size = stream->position;
}

MEM_STREAM_API void mem_stream_write_int16(mem_stream_t* stream,int16_t val) {
    assert(stream->usage & MEM_STREAM_OUTPUT);
    assert(mem_stream_check_buffer_size(stream, stream->position + sizeof(val)) ==
        MEM_STREAM_OK);

    *(int16_t*)((uint8_t*)stream->buffer + stream->position)=val;
    stream->position += sizeof(val);

    if (stream->position > stream->size)
        stream->size = stream->position;
}

MEM_STREAM_API void mem_stream_write_uint16(mem_stream_t* stream,uint16_t val) {
    assert(stream->usage & MEM_STREAM_OUTPUT);
    assert(mem_stream_check_buffer_size(stream, stream->position + sizeof(val)) ==
        MEM_STREAM_OK);

    *(uint16_t*)((uint8_t*)stream->buffer + stream->position) = val;
    stream->position += sizeof(val);

    if (stream->position > stream->size)
        stream->size = stream->position;
}

MEM_STREAM_API void mem_stream_write_int32(mem_stream_t* stream,int32_t val) {
    assert(stream->usage & MEM_STREAM_OUTPUT);
    assert(mem_stream_check_buffer_size(stream, stream->position + sizeof(val)) ==
        MEM_STREAM_OK);

    *(uint32_t*)((uint8_t*)stream->buffer + stream->position) = val;
    stream->position += sizeof(val);

    if (stream->position > stream->size)
        stream->size = stream->position;
}

MEM_STREAM_API void mem_stream_write_uint32(mem_stream_t* stream,uint32_t val) {
    assert(stream->usage & MEM_STREAM_OUTPUT);
    assert(mem_stream_check_buffer_size(stream, stream->position + sizeof(val)) ==
        MEM_STREAM_OK);

    *(uint32_t*)((uint8_t*)stream->buffer + stream->position) = val;
    stream->position += sizeof(val);

    if (stream->position > stream->size)
        stream->size = stream->position;
}

MEM_STREAM_API void mem_stream_write_int64(mem_stream_t* stream,int64_t val) {
    assert(stream->usage & MEM_STREAM_OUTPUT);
    assert(mem_stream_check_buffer_size(stream, stream->position + sizeof(val)) ==
        MEM_STREAM_OK);

    *(uint64_t*)((uint8_t*)stream->buffer + stream->position) = val;
    stream->position += sizeof(val);
    if (stream->position > stream->size)
        stream->size = stream->position;
}

MEM_STREAM_API void mem_stream_write_uint64(mem_stream_t* stream,uint64_t val) {
    assert(stream->usage & MEM_STREAM_OUTPUT);
    assert(mem_stream_check_buffer_size(stream, stream->position + sizeof(val)) ==
        MEM_STREAM_OK);

    *(uint64_t*)((uint8_t*)stream->buffer + stream->position) = val;
    stream->position += sizeof(val);
    if (stream->position > stream->size)
        stream->size = stream->position;
}

MEM_STREAM_API void mem_stream_write_float(mem_stream_t* stream,float val) {
    assert(stream->usage & MEM_STREAM_OUTPUT);
    assert(mem_stream_check_buffer_size(stream, stream->position + sizeof(val)) ==
        MEM_STREAM_OK);

    *(float*)((uint8_t*)stream->buffer + stream->position) = val;
    stream->position += sizeof(val);

    if (stream->position > stream->size)
        stream->size = stream->position;
}

MEM_STREAM_API void mem_stream_write_double(mem_stream_t* stream,double val) {
    assert(stream->usage & MEM_STREAM_OUTPUT);
    assert(mem_stream_check_buffer_size(stream, stream->position + sizeof(val)) ==
        MEM_STREAM_OK);

    *(double*)((uint8_t*)stream->buffer + stream->position) = val;
    stream->position += sizeof(val);

    if (stream->position > stream->size)
        stream->size = stream->position;
}

MEM_STREAM_API void mem_stream_write(mem_stream_t* stream, void* buffer, uint32_t size) {
    assert(stream->usage & MEM_STREAM_OUTPUT);
    assert(mem_stream_check_buffer_size(stream, stream->position + size) ==
        MEM_STREAM_OK);

    memcpy((uint8_t*)stream->buffer + stream->position,buffer, size);
    stream->position += size;

    if (stream->position > stream->size)
        stream->size = stream->position;
}
