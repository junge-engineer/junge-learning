/* comms.c - simple uart/modbus comms skeleton */
#include <stdio.h>
#include <stdint.h>

// Implement these with your HAL/driver
void uart_send_bytes(const uint8_t *data, int len) { (void)data; (void)len; }
int uart_read_bytes(uint8_t *buf, int maxlen) { (void)buf; (void)maxlen; return 0; }

// Very small JSON-like status formatter (no dynamic allocation)
void send_status_uart(const char *s) {
    const uint8_t *p = (const uint8_t*)s;
    while (*p) { uart_send_bytes(p,1); p++; }
}

// Example simple command parser (blocking; replace with ring buffer in real app)
void process_incoming(void) {
    uint8_t buf[128];
    int n = uart_read_bytes(buf, sizeof(buf));
    if (n<=0) return;
    // parse simple ASCII commands like: SETRPM:120
    if (n>6 && buf[0]=='S' && buf[1]=='E' && buf[2]=='T') {
        // naive parse
    }
}
