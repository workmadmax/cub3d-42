/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:42:19 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/14 17:52:47 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_check_double_flag(t_check *data)
{
	data->no = 0;
	data->so = 0;
	data->we = 0;
	data->ea = 0;
	data->f = 0;
	data->c = 0;
	data->i = -1;
	data->status = 0;
}

void	count_flag(t_check *data)
{
	if (data->status == NO)
		data->no++;
	if (data->status == SO)
		data->so++;
	if (data->status == WE)
		data->we++;
	if (data->status == EA)
		data->ea++;
	if (data->status == F)
		data->f++;
	if (data->status == C)
		data->c++;
}

int	check_count_flag(t_check *data)
{
	if (data->no != 1)
		return (error_msg("error double flags", ERROR_COUNT_FLAG));
	if (data->so != 1)
		return (error_msg("error double flags", ERROR_COUNT_FLAG));
	if (data->we != 1)
		return (error_msg("error double flags", ERROR_COUNT_FLAG));
	if (data->ea != 1)
		return (error_msg("error double flags", ERROR_COUNT_FLAG));
	if (data->f != 1)
		return (error_msg("error double flags", ERROR_COUNT_FLAG));
	if (data->c != 1)
		return (error_msg("error double flags", ERROR_COUNT_FLAG));
	return (SUCCESS);
}

int	check_double_flag(char **text)
{
	int		res;
	t_check	*data;

	data = malloc(sizeof(t_check));
	if (!data)
		return (error_msg("Error\nMalloc error\n", ERROR_MALLOC));
	init_check_double_flag(data);
	while (text[++data->i])
	{
		data->status = get_line_code(text[data->i]);
		count_flag(data);
	}
	res = check_count_flag(data);
	free(data);
	return (res);
}
