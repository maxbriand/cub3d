/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freddy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:20:18 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/22 17:31:34 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


// void ft_print_freddy(t_player *p)
// {
//     // Calcul de la distance entre le joueur et Freddy
//     float dist_x = p->f->posx - p->posx;
//     float dist_y = p->f->posy - p->posy;
//     float distance = sqrt(dist_x * dist_x + dist_y * dist_y);

//     // Calcul de l'angle vers Freddy et l'orientation du joueur
//     float angle_to_freddy = atan2(dist_y, dist_x);
//     float player_angle = normalize_angle(p->or);

//     // Normalisation des angles pour être entre 0 et 2*PI
//     angle_to_freddy = normalize_angle(angle_to_freddy);

//     // Calcul de la différence d'angle entre le joueur et Freddy
//     float angle_diff = normalize_angle(angle_to_freddy - player_angle);

//     // Vérification si Freddy est dans le champ de vision
//     if (fabs(angle_diff) < p->fov / 2 && distance > 0)
//     {
//         p->f->visible = true;

//         // Calcul de la position de Freddy à dessiner
//         int sprite_screen_x = (int)((p->game->width / 2) * (1 + tan(angle_diff))); // Position relative à l'angle
//         int sprite_height = abs((int)(p->game->height / (distance * 1.5)));  // Taille de Freddy (dépendant de la distance)

//         // Redimensionner et afficher l'image de Freddy
//         if (p->f->fl) // Vérifier que l'image est valide
//             mlx_delete_image(p->game->mlx, p->f->fl); // Supprimer l'ancienne image
//         p->f->fl = mlx_texture_to_image(p->game->mlx, p->f->freddy_left);
// 		// Redimensionner l'image de Freddy
// 		mlx_resize_image(p->f->fl, sprite_height, sprite_height); // Taille ajustée selon la distance

// 		// Dessiner Freddy à la position calculée
// 		mlx_image_to_window(p->game->mlx, p->f->fl, sprite_screen_x, (p->game->height / 2) - (sprite_height / 2));
//     }
//     else
//     {
// 		mlx_delete_image(p->game->mlx, p->f->fl);
//         p->f->visible = false; // Ne pas dessiner si Freddy n'est pas visible
//     }
// }



void ft_print_freddy(t_player *p)
{
    // Calcul de la distance entre le joueur et Freddy
    float dist_x = p->f->posx - p->posx;
    float dist_y = p->f->posy - p->posy;
    float distance = sqrt(dist_x * dist_x + dist_y * dist_y);

    // Calcul de l'angle vers Freddy et l'orientation du joueur
    float angle_to_freddy = atan2(dist_y, dist_x);
    float player_angle = normalize_angle(p->or);

    // Normalisation des angles pour être entre -π et π
    float angle_diff = normalize_angle_diff(angle_to_freddy - player_angle);

    // Calcul de la projection de Freddy sur l'écran si dans le champ de vision
    if (fabs(angle_diff) < p->fov / 2 && distance > 0)
    {
        // Projection de Freddy sur l'écran
        int sprite_screen_x = (int)((p->game->width / 2) * (1 + (angle_diff / (p->fov / 2))));

        // Recherche de la distance au mur pour le rayon correspondant à Freddy
        int ray_index = sprite_screen_x;
        if (ray_index >= 0 && ray_index < p->game->width)
        {
            float wall_distance = p->rc[ray_index].perp_wall_dist;  // Distance au mur pour ce rayon

            // Si Freddy est plus proche que le mur, le dessiner
            if (distance < wall_distance)
            {
                // Calcul de la taille du sprite (Freddy) en fonction de la distance
                int sprite_height = abs((int)(p->game->height / (distance * 2.0)));  // Ajustement du facteur de distance
                int sprite_y_offset = (int)(p->game->mid_sy * p->p_look_angle);

                // Supprimer l'image précédente de Freddy
                mlx_delete_image(p->game->mlx, p->f->fl);  // Supprimer l'ancienne image
                p->f->fl = mlx_texture_to_image(p->game->mlx, p->f->freddy_left);
                mlx_resize_image(p->f->fl, sprite_height, sprite_height);  // Taille ajustée selon la distance

                // Dessiner Freddy à la position calculée avec l'ajustement de l'angle vertical
                mlx_image_to_window(p->game->mlx, p->f->fl, sprite_screen_x, (p->game->height / 2) - (sprite_height / 2) + sprite_y_offset);
            }
        }
    }
    else
    {
        p->f->visible = false; // Ne pas dessiner si Freddy n'est pas visible
    }
}
