#include "math/time.hpp"
#include <windows.h>

LARGE_INTEGER GetFrequency()
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return freq;
}

Seconds  now()
{


  LARGE_INTEGER tick, freq;
  Seconds res;

  freq = GetFrequency();
  QueryPerformanceCounter(&tick);
  res = (Seconds)tick.QuadPart / (Seconds)freq.QuadPart;
  return res;
}

void    sleep(int len)
{
    Sleep(len);
}
