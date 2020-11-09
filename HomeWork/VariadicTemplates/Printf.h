#pragma once

template <typename T>
void Printf(T& value)
{
    value.Printf();
}

template <typename T, typename... Args>
void Printf(T& value, Args&... args)
{
    Printf(value);
    Printf(args...);
}

class Printable
{
public:
    virtual void Printf() = 0;
};