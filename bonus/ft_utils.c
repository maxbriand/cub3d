/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:21:31 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/22 17:30:48 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

float	ft_abs(float nb)
{
	if (nb < 0.0)
		nb = nb * -1.0;
	return (nb);
}

float normalize_angle(float angle)
{
    while (angle < 0)
		angle += 2 * M_PI;
    while (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
    return angle;
}

float normalize_angle_diff(float angle)
{
    while (angle > M_PI)
        angle -= 2 * M_PI;
    while (angle < -M_PI)
        angle += 2 * M_PI;
    return angle;
}