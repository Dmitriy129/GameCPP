#ifndef LOGIC_TIMER_HPP
#define LOGIC_TIMER_HPP

#include <thread>

namespace utils
{
class Timer
{
    bool clear = false;

public:
    template <typename Function>
    void setTimeout(Function function, int delay);

    template <typename Function>
    void setInterval(Function function, int interval);

    void stop();
};

} // namespace utils

#endif //LOGIC_TIMER_HPP