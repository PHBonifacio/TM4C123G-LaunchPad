#ifndef __TIMER_H__
#define __TIMER_H__
#include <TM4C123GH6PM.h>
#include <stdint.h>

typedef enum
{
    FREQ_1HZ,
    FREQ_2HZ,
    FREQ_5HZ,
    FREQ_10HZ,
    FREQ_20HZ,
    FREQ_50HZ,
    FREQ_100HZ
} freq_t;

#endif
