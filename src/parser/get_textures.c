/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:17:03 by apigeon           #+#    #+#             */
/*   Updated: 2022/12/29 19:17:04 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	is_wall_texture(t_token_type type)
{
	if (type == TOKEN_NORTH || type == TOKEN_SOUTH)
		return (true);
	if (type == TOKEN_WEST || type == TOKEN_EAST)
		return (true);
	return (false);
}

static t_texture	*create_texture(char *file)
{
	t_texture	*texture;

	texture = malloc(sizeof(*texture));
	if (!texture)
		return (DEBUG(MSG_MALLOC_ERROR), NULL);
	texture->img = NULL;
	texture->file = ft_strdup(file);
	if (!texture->file)
		return (DEBUG(MSG_MALLOC_ERROR), free(texture), NULL);
	return (texture);
}

static int	fill_wall_textures(t_list *tokens, t_textures *textures)
{
	t_token		*token;
	t_texture	*texture;

	while (tokens)
	{
		token = tokens->content;
		if (is_wall_texture(token->type))
		{
			texture = create_texture(token->value);
			if (!texture)
				return (-1);
			if (token->type == TOKEN_NORTH)
				textures->wall_north = texture;
			else if (token->type == TOKEN_SOUTH)
				textures->wall_south = texture;
			else if (token->type == TOKEN_WEST)
				textures->wall_west = texture;
			else if (token->type == TOKEN_EAST)
				textures->wall_east = texture;
		}
		tokens = tokens->next;
	}
	return (1);
}

static int	parse_color(char *color)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	r = ft_atoi(color);
	while (color[i] && color[i] != ',')
		i++;
	g = ft_atoi(color + ++i);
	while (color[i] && color[i] != ',')
		i++;
	b = ft_atoi(color + ++i);
	if (r > 255 || g > 255 || b > 255)
		return (DEBUG(MSG_INVALID_COLOR), -1);
	if (r < 0 || g < 0 || b < 0)
		return (DEBUG(MSG_INVALID_COLOR), -1);
	return (r << 16 | g << 8 | b);
}

static int	fill_floor_ceiling(t_list *tokens, t_textures *textures)
{
	int		color;
	t_token	*token;

	while (tokens)
	{
		token = tokens->content;
		if (token->type == TOKEN_FLOOR || token->type == TOKEN_CEILING)
		{
			color = parse_color(token->value);
			if (color == -1)
				return (-1);
			if (token->type == TOKEN_FLOOR)
				textures->floor = color;
			else
				textures->ceiling = color;
		}
		tokens = tokens->next;
	}
	return (1);
}

static t_textures	*init_textures(void)
{
	t_textures	*textures;

	textures = malloc(sizeof(*textures));
	if (!textures)
		return (DEBUG("malloc error"), NULL);
	textures->ceiling = 0;
	textures->floor = 0;
	textures->wall_north = NULL;
	textures->wall_south = NULL;
	textures->wall_west = NULL;
	textures->wall_east = NULL;
	return (textures);
}

t_textures	*get_textures(t_list *tokens)
{
	t_textures	*textures;

	textures = init_textures();
	if (!textures)
		return (NULL);
	if (fill_wall_textures(tokens, textures) == -1)
		return (NULL);
	if (fill_floor_ceiling(tokens, textures) == -1)
		return (NULL);
	return (textures);
}
