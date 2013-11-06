#include "math/time.hpp"
#include <windows.h>

LARGE_INTEGER GetFrequency()
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return freq;
}

GameTime  now()
{


  LARGE_INTEGER tick, freq;
  GameTime res;

  freq = GetFrequency();
  QueryPerformanceCounter(&tick);
  res = (GameTime)tick.QuadPart / (GameTime)freq.QuadPart;
  return res;
}

void    sleep(int len)
{
    Sleep(len);
}
