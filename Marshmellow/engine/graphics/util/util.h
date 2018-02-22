#ifndef UTIL
#define UTIL

template<typename T>
struct Rect2D
{
    T width;
    T height;
};

typedef Rect2D<unsigned int> ScreenDimensions;
typedef Rect2D<float> Dimensions2D;

#endif // UTIL

