#include"fdf.h"

int	ft_pallete1(int color)
{
	if (color == 0)
		return (0x00fc031c);
	else if (color == 1 || color == -1)
		return (0x009c27b0);
	else if (color == 2 || color == -2)
		return (0x1962E1);
	else if (color == 3 || color == -3)
		return (0x003f51b5);
	else if (color == 4 || color == -4)
		return (0xF3722C);
	else if (color == 5 || color == -5)
		return (0x003366);
	else if (color == 6 || color == -6)
		return (0x00009688);
	else if (color == 7 || color == -7)
		return (0x004caf50);
	else if (color == 8 || color == -8)
		return (0x009A00);
	else if (color == 9 || color == -9)
		return (0x00cddc39);
	else if (color == 10 || color == -10)
		return (0xC16100);
	else
		return (0x00ff9800);
}

int	ft_pallete2(int color)
{
	if (color == 12 || color == -12)
		return (0x009e9e9e);
	else if (color == 13 || color == -13)
		return (0x007fffd4);
	else if (color == 14 || color == -14)
		return (0x00ea927a);
	else if (color == 15 || color == -15)
		return (0x00a2af70);
	else if (color == 16 || color == -16)
		return (0x0089556e);
	else if (color == 17 || color == -17)
		return (0x945700);
	else if (color == 18 || color == -18)
		return (0x693502);
	else if (color == 19 || color == -19)
		return (0x00990020);
	else if (color > 19 || color < -19)
		return (0x00004c4c);
	else if (color >= 50 || color <= -50)
		return (0xFFB266);
	else if (color >= 70 || color <= -70)
		return (0x00bca352);
	else
		return (0x00990020);
}

int	get_color(int color)
{
	if (color >= -11 && color <= 11)
		return (ft_pallete1(color));
	else if (color >= 12 && color <= -12)
		return (ft_pallete2(color));
	else
	{
		if (color <= 190)
			return (0x00004c4c);
		else
			return (0x00004c4c);
	}
}
