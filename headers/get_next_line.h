/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 16:54:02 by po-conno          #+#    #+#             */
/*   Updated: 2013/12/21 13:42:48 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024

int		get_next_line(int const fd, char **line);
int		fill_line(char *str, char **line);
int		end_line(char *str, char **line, int i);
int		find_lf(char const *str, int c);

#endif
