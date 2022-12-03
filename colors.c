#include"fdf.h"

int get_color(int color, t_map_data *data)
{
    if (color == 0) 
		data->color = 0x00fc031c;
	else if (color == 1 || color == -1) 
		data->color = 0x009c27b0;
    else if (color == 2 || color == -2) 
		data->color = 0x00e81e63;
    else if (color == 3 || color == -3) 
		data->color = 0x003f51b5;
    else if (color == 4 || color == -4) 
		data->color = 0x002196f3;
    else if (color == 5 || color == -5) 
		data->color = 0x0000bcd4;
    else if (color == 6 || color == -6) 
		data->color = 0x00009688;
    else if (color == 7 || color == -7) 
		data->color = 0x004caf50;
    else if (color == 8 || color == -8) 
		data->color = 0x008bc34a;
    else if (color == 9 || color == -9) 
		data->color = 0x00cddc39;
    else if (color == 10 || color == -10) 
		data->color = 0x00BBFAFF;
    else if (color == 11 || color == -11) 
		data->color = 0x00ff9800;
    else if (color == 12 || color == -12) 
		data->color = 0x009e9e9e;
    else if (color == 13 || color == -13) 
		data->color = 0x00545b45;
    else if (color == 14 || color == -14) 
		data->color = 0x00ea927a;
    else if (color == 15 || color == -15) 
		data->color = 0x00a2af70;
    else if (color == 16 || color == -16) 
		data->color = 0x0089556e;
    else if (color == 17 || color == -17) 
		data->color = 0x00ffeb3b;
    else if (color == 18 || color == -18) 
		data->color = 0x00331100;
    else if (color == 19 || color == -19) 
		data->color = 0x00990020;
	else if (color > 19 || color < -19) 
		data->color = 0x00004c4c;
	else if (color >= 50 || color <= -50) 
		data->color = 0x007fffd4;
	else if (color >= 70 || color <= -70) 
		data->color = 0x00bca352;
    else
		data->color = 0x00899e7e;
    return (data->color);
}
