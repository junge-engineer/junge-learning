/*
 * main.c - STM32 firmware skeleton for Mini Assembly Sample
 * NOTE: Replace HAL init sections with code from your board's CubeMX/IDE.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// --- Hardware abstraction placeholders ---
void SystemClock_Config(void) {}
void MX_GPIO_Init(void) {}
void MX_TIM_PWM_Init(void) {}
void MX_USART_Init(void) {}

// --- Application APIs (to implement) ---
int32_t read_encoder_count(void) { return 0; }
void set_motor_pwm(int32_t duty) {}
void send_status_uart(const char *s) { (void)s; }

// Simple PID state
typedef struct { float kp, ki, kd; float integral, prev_err; } PID_t;
static PID_t motor_pid = { .kp=1.0f, .ki=0.0f, .kd=0.0f };

float pid_update(PID_t *pid, float setpoint, float measurement, float dt) {
    float err = setpoint - measurement;
    pid->integral += err * dt;
    float deriv = (err - pid->prev_err) / dt;
    pid->prev_err = err;
    return pid->kp * err + pid->ki * pid->integral + pid->kd * deriv;
}

int main(void) {
    SystemClock_Config();
    MX_GPIO_Init();
    MX_TIM_PWM_Init();
    MX_USART_Init();

    int32_t encoder = 0;
    float target_rpm = 0.0f;
    const float loop_dt = 0.01f; // 10 ms loop

    while (1) {
        // read sensors
        encoder = read_encoder_count();
        float measured_rpm = (float)encoder; // replace with conversion

        // compute control
        float pwm = pid_update(&motor_pid, target_rpm, measured_rpm, loop_dt);
        set_motor_pwm((int32_t)pwm);

        // simple status report
        char buf[128];
        int n = snprintf(buf, sizeof(buf), "RPM:%.2f,TGT:%.2f\n", measured_rpm, target_rpm);
        if (n>0) send_status_uart(buf);

        // basic delay - replace with timer/systick
        for (volatile int i=0;i<100000;i++);
    }
}
