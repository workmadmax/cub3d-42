/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:38:27 by mdouglas          #+#    #+#             */
/*   Updated: 2023/08/07 19:06:14 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Return a copy of given string, without
 * the characters specified in set.
 * 
 * @param string_one The string to be processed.
 * @param set The set of characters to be removed
 * from the beginning and end of string.
 * @return char* A copy of string without the char
 * specified in set at the beginning and end,
 * or NULL if string or set are NULL.
 */
char	*ft_strtrim(char const *string_one, char const *set)
{
	size_t	length;

	if (!string_one || !set)
		return (0);
	while (*string_one && ft_strchr(set, *string_one))
		string_one++;
	length = ft_strlen(string_one);
	while (length && ft_strchr(set, string_one[length]))
		length--;
	return (ft_substr(string_one, 0, length + 1));
}
