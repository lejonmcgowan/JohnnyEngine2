//
// Created by lejonmcgowan on 2/14/16.
//

#include "Timer.h"

#define SECONDS_FROM_NANOSECONDS 1000000000
#define SECONDS_FROM_MICROSECONDS 1000000
#define SECONDS_FROM_MILLISECONDS 1000
using namespace std::chrono;

Timer::Timer(bool start)
{
    if (start)
        this->start();
}

void Timer::start()
{
    timestart = steady_clock::now();
}

void Timer::reset()
{
    timestart = steady_clock::now();
}

float Timer::getElapsedNano()
{
    return duration_cast<nanoseconds>(getCurrentTime()).count();
}

float Timer::getElapsedMicro()
{
    return duration_cast<microseconds>(getCurrentTime()).count();
}

float Timer::getElapsedMills()
{
    return duration_cast<milliseconds>(getCurrentTime()).count();
}

float Timer::getElapsedSeconds()
{
    return duration_cast<seconds>(getCurrentTime()).count();
}

steady_clock::duration Timer::getCurrentTime()
{
    timecurrent = steady_clock::now();
    return timecurrent - timestart;
}
