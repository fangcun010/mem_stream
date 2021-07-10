#include <stdio.h>

#include <mem_stream.h>

mem_stream_t stream;

void test_write() {
    for (uint32_t i = 1; i < 132; i++)
        mem_stream_write_uint32(&stream, i);
}

void test_read() {
    for (uint32_t i = 1; i < 32; i++) {
        uint32_t val = mem_stream_read_uint32(&stream);
        printf("%u\n", val);
    }
}

char buffer[256];

int main() {
    int ret = mem_stream_open(&stream, buffer, 256, 0, MEM_STREAM_INPUT | MEM_STREAM_OUTPUT|MEM_STREAM_COPY_DATA );
    test_write();
    mem_stream_seek(&stream, 0);
    test_read();
    mem_stream_close(&stream);

    return 0;
}