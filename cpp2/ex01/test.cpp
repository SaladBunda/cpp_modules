#include <iostream>

const int scale = 8;
using namespace std;

int floattofixed(float f)
{
    int integer = f * (1 << scale);
    cout << integer << endl;
    return integer;
}

float fixedToFloat(int fixed)
{
    float fl = (float) fixed / (1 << scale);
    cout << fl << endl;
    return fl;
}

int main()
{
    int f = floattofixed(68.323);
    int f2 = floattofixed(68.324);
    int result = f + f2;
    float fl = fixedToFloat(f);
    float fl2 = fixedToFloat(f2);
    std::cout << fl +fl2 <<endl;
    float float_result = fixedToFloat(result);
}