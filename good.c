#include "MLX42/MLX42_Int.h"
#include "MLX42/MLX42.h"
#include <math.h>
#include "libft/libft.h"

#define TILE_SIZE 100
#define MAX_DIST 400

typedef struct {
    float x;
    float y;
    float angle;
    float fov;
} Player;

typedef struct {
    int width;
    int height;
    char *map;
} Map;

typedef struct {
    int width;
    int height;
    mlx_t *mlx;
    mlx_image_t *image;
    Player player;
    Map map;
} Game;

void drawWallSlice(mlx_image_t *image, int x, int wallHeight, int sliceWidth, int screenHeight) {
    int j = 0;
    while (j < wallHeight) {
        int yPosition = (screenHeight / 2) - (wallHeight / 2) + j;
        if (yPosition >= 0 && yPosition < screenHeight) {
            int k = 0;
            while (k < sliceWidth) {
                mlx_put_pixel(image, x + k, yPosition, 0xB400B4); // Couleur violette
                k++;
            }
        }
        j++;
    }
}

void castRay(Game *game, float rayAngle, int *distance, int *wallHeight) {
    float x = game->player.x;
    float y = game->player.y;
    float dx = cos(rayAngle);
    float dy = sin(rayAngle);

    int i = 0;
    while (game->map.map[(int)floor(y / TILE_SIZE) * game->map.width + (int)floor(x / TILE_SIZE)] == '0') {
        x += dx * 0.1;
        y += dy * 0.1;
        i++;
        if (i > MAX_DIST) break;  // Éviter les boucles infinies
    }

    *distance = sqrt((x - game->player.x) * (x - game->player.x) + (y - game->player.y) * (y - game->player.y));
    *wallHeight = (int)(300 / *distance);
}

void raycast(Game *game) {
    int rays = game->width;
    float angleStep = game->player.fov / rays;
    int i = 0;
    while (i < rays) {
        float rayAngle = game->player.angle - (game->player.fov / 2) + i * angleStep;
        int distance;
        int wallHeight;
        castRay(game, rayAngle, &distance, &wallHeight);
        drawWallSlice(game->image, i, wallHeight, 1, game->height);
        i++;
    }
}

int main(int argc, char **argv) {
    Game game;
    game.width = 1920;
    game.height = 1080;
    game.player.x = 250;
    game.player.y = 450;
    game.player.angle = 0;
    game.player.fov = 0.6;
    game.map.width = 10;
    game.map.height = 6;
    game.map.map = "1111111111"
                   "1000000001"
                   "1011000001"
                   "1000000001"
                   "1000000001"
                   "1121111111";

    game.mlx = mlx_init(game.width, game.height, "Raycasting", true);
    if (!game.mlx) return -1;

    game.image = mlx_new_image(game.mlx, game.width, game.height);
    if (!game.image) {
        mlx_terminate(game.mlx);
        return -1;
    }

    raycast(&game);

    mlx_image_to_window(game.mlx, game.image, 0, 0);
    mlx_loop(game.mlx);

    mlx_delete_image(game.mlx, game.image);
    mlx_terminate(game.mlx);

    return 0;
}
