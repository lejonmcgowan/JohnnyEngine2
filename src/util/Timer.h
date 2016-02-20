//
// Created by lejonmcgowan on 2/14/16.
//

#ifndef OGLSIMPLEENGINE_TIMER_H
#define OGLSIMPLEENGINE_TIMER_H


#include <chrono>

class Timer
{
private:
    std::chrono::steady_clock::time_point timestart, timecurrent;

    inline std::chrono::steady_clock::duration getCurrentTime();
public:
    /*
     * sets up and initializes timer
     * @param start: whether or not the timer automatically starts at runtime
     */
    Timer(bool start = false);

    //starts timer
    void start();

    //resets timer to 0 by setting new offset to timestart
    void reset();

    //gets time in nanoseconds
    float getElapsedNano();

    //gets time in microseconds
    float getElapsedMicro();

    //gets time in milliseconds;
    float getElapsedMills();

    //gets time in seconds
    float getElapsedSeconds();
};


#endif //OGLSIMPLEENGINE_TIMER_H
