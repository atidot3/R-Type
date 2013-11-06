#ifndef TIME
#define TIME

const float BLOCKS_PER_SECOND = 1;
const float GAMETIME_PER_BLOCK = 1 / BLOCKS_PER_SECOND;

double                  now();
void                    sleep(int len); // miliGameTime

typedef	double			GameTime;

#endif // TIME
