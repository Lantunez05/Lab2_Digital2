#include"Map_adc.h"
int map (int val, int min_in, int max_in, int min_out, int max_out)
{
    int vo;
    vo = (long)(val-min_in)*(max_out-min_out)/(max_in-min_in)+ min_out; 
    return vo;
}
