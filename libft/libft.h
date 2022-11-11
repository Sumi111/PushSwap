/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 10:55:38 by sfathima          #+#    #+#             */
/*   Updated: 2022/04/27 13:11:49 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_isdigit(int i);
int		ft_strlen(const char *s);
int		ft_word_count(char const *s, char c);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);

#endif
