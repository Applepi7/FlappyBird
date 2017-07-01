#include <Windows.h>

inline int Random(int min, int max) 
{
	return rand() % (max - min + 1) + min;
}