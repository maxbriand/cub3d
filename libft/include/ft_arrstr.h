/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:54:19 by mbriand           #+#    #+#             */
/*   Updated: 2024/06/03 19:01:49 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRSTR_H
# define FT_ARRSTR_H

void	ft_arrfree(char **str_array);
int		ft_arrlen(char **str);
char	**ft_arrcat(char **array, char *str);
void	ft_arrprintf(char **arr_of_str);
char	**ft_arrjoin(char **fst_array, char **snd_array);
char	**ft_arrcpy(char **dest, char **src);
char	**ft_arrncpy(char **dest, char **src, int n);
int		ft_arrfind(char **arr, char *ref);

#endif