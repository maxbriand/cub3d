#include "MLX42/MLX42_Int.h"
#include "MLX42/MLX42.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define screen_width 640
#define screen_height 480
#define mapWidth 10
#define mapHeight 6
#define texWidth 64
#define texHeight 64

#define BPP sizeof(int32_t)

double posX = 22, posY = 12;  // Position initiale du joueur
double dirX = -1, dirY = 0;   // Direction initiale du joueur
double planeX = 0, planeY = 0.66; // Plan de la caméra

double moveSpeed = 0.1;
double rotSpeed = 0.1;

char map[mapHeight][mapWidth] = {
    "1111111111",
    "1000000001",
    "1000000001",
    "1000020001",
    "1000000001",
    "1111111111"
};

void render(mlx_image_t *img)
{
    int x = 0;
    while (x < screen_width) {
        // Calcul de la position et de la direction du rayon
        double cameraX = 2 * x / (double)screen_width - 1;
        double rayDirX = dirX + planeX * cameraX;
        double rayDirY = dirY + planeY * cameraX;

        // Quelle case de la carte le rayon touche-t-il ?
        int mapX = (int)posX;
        int mapY = (int)posY;

        // Longueur du rayon du point de départ au premier côté x ou y
        double sideDistX;
        double sideDistY;

        // Longueur du rayon d'un côté x ou y à l'autre côté x ou y
        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
        double perpWallDist;

        // Direction de pas et distance initiale à partir de la position initiale à la première frontière de grille
        int stepX;
        int stepY;

        // Calcul de stepX et sideDistX
        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (posX - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - posX) * deltaDistX;
        }
        // Calcul de stepY et sideDistY
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (posY - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - posY) * deltaDistY;
        }

        // Boucle de DDA (Digital Differential Analyzer)
        int hit = 0; // A wall was hit
        int side; // Was a NS or a EW wall hit?
        while (hit == 0) {
            // Jump to next map square, OR in x-direction, OR in y-direction
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            // Check if ray has hit a wall
            if (map[mapY][mapX] > '0') hit = 1;
        }

        // Calcul de la distance projetée correcte du joueur au mur
        if (side == 0) perpWallDist = (sideDistX - deltaDistX);
        else           perpWallDist = (sideDistY - deltaDistY);

        // Calcul de la hauteur de la ligne à dessiner sur l'écran
        int lineHeight = (int)(screen_height / perpWallDist);

        // Calcul des limites de dessin (haut et bas)
        int drawStart = -lineHeight / 2 + screen_height / 2;
        if(drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + screen_height / 2;
        if(drawEnd >= screen_height) drawEnd = screen_height - 1;

        // Choix de la couleur du mur
        int color;
        switch(map[mapY][mapX]) {
            case '1': color = 0xFF0000FF; break; // Red
            case '2': color = 0x00FF00FF; break; // Green
            default: color = 0xFFFF00FF; break; // Yellow
        }

        // Dégradé de couleur si un côté nord-sud est touché
        if (side == 1) { color = color / 2; }

        // Dessin de la ligne de pixels
        int y = drawStart;
        while (y < drawEnd) {
            // Put pixel on screen buffer at (x, y) with the calculated color
            ((int*)img->pixels)[y * screen_width + x] = color;
            y++;
        }
        x++;
    }
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window((mlx_t*)param);
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS) {
        posX += dirX * moveSpeed;
        posY += dirY * moveSpeed;
    }
    if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS) {
        posX -= dirX * moveSpeed;
        posY -= dirY * moveSpeed;
    }
    if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS) {
        double oldDirX = dirX;
        dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
        dirY = oldDirX * sin(-rotSpeed) + dirX * cos(-rotSpeed);
        double oldPlaneX = planeX;
        planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
        planeY = oldPlaneX * sin(-rotSpeed) + planeX * cos(-rotSpeed);
    }
    if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS) {
        double oldDirX = dirX;
        dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
        dirY = oldDirX * sin(rotSpeed) + dirX * cos(rotSpeed);
        double oldPlaneX = planeX;
        planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
        planeY = oldPlaneX * sin(rotSpeed) + planeX * cos(rotSpeed);
    }
    render((mlx_image_t*)param);
}

int main(void)
{
    mlx_t* mlx = mlx_init(screen_width, screen_height, "Cube3D", false);
    if (!mlx)
        return EXIT_FAILURE;

    mlx_image_t* img = mlx_new_image(mlx, screen_width, screen_height);
    if (!img)
        return EXIT_FAILURE;

    mlx_key_hook(mlx, my_keyhook, mlx);
    mlx_image_to_window(mlx, img, 0, 0);
    render(img);

    mlx_loop(mlx);
    mlx_delete_image(mlx, img);
    mlx_terminate(mlx);
    return EXIT_SUCCESS;
}