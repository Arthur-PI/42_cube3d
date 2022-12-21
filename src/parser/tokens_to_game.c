#include "parser.h"

static t_texture	*get_textures(t_list *tokens)
{
	t_texture	*textures;

	(void)tokens;
	textures = NULL;
	return (textures);
}

static t_map	*get_map(t_list *tokens)
{
	t_map	*map;

	(void)tokens;
	map = NULL;
	return (map);
}

static t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(*game));
	if (!game)
		return (DEBUG(MSG_MALLOC_ERROR), NULL);
	game->map = NULL;
	game->textures = NULL;
	return (game);
}

t_game	*tokens_to_game(t_list *tokens)
{
	t_game	*game;

	(void)tokens;
	game = init_game();
	if (!game)
		return (NULL);
	game->map = get_map(tokens);
	game->textures = get_textures(tokens);
	if (!game->map || !game->textures)
		return (free_game(game), NULL);
	if (!can_escape_map(game->map))
		return (free_game(game), NULL);
	return (game);
}
