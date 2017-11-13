/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoltar <Zoltar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 01:21:59 by Zoltar            #+#    #+#             */
/*   Updated: 2017/11/12 11:23:51 by Zoltar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

// DELETE ME B4 GRADING
#include <stdio.h>
// DELETE ME B4 GRADING

#include <unistd.h>
#include <fcntl.h>


#define BUF 1

int		get_pieces(char *file);
int		is_valid(int fd);
int		istrino(char *piece, int s, int c);

#endif