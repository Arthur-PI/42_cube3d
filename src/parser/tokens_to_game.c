#include "parser.h"

static t_texture	*get_textures(t_list *tokens)
{
	t_texture	*textures;

	(void)tokens;
	textures = NULL;
	DEBUG("malloc error");
	return (textures);
}

t_game	*tokens_to_game(t_list *tokens)
{
	t_game	*game;

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
