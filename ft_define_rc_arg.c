#include "cube.h"

void	ft_define_rc_arg()
{
	y = posY;
	x = posX;
	//trouver la longueur du rayon
	angle = or - (fov / 2.0) + (fov * ((float)Ex / width));
	rayDirX = cos(angle);
	rayDirY = sin(angle);
	hit = 0;

	int mapX = (int)posX;
	int mapY = (int)posY;


	float deltaDistX = sqrt(1.0 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
	float deltaDistY = sqrt(1.0 + (rayDirX * rayDirX) / (rayDirY * rayDirY));


	//calcule des rayon
	if (rayDirX < 0)
	{
		stepX = -1;
		sideDistX = (posX - mapX) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (mapX + 1.0 - posX) * deltaDistX;
	}
	if (rayDirY < 0)
	{
		stepY = -1;
		sideDistY = (posY - mapY) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (mapY + 1.0 - posY) * deltaDistY;
	}
}
