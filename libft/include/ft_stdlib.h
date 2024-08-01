/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:06:17 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/02 18:07:56 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

int		ft_atoi(const char *nptr);
long	ft_atol(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);

#endif