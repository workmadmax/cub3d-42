/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:11:55 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/14 14:59:06 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;


typedef struct s_check
{
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
	int		i;
	int		status;
}	t_check;
typedef struct s_data
{
	char	**map;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}	t_data;

typedef struct s_game
{
	t_data	data;
}	t_game;


#endif