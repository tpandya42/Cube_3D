#include "cub.h"
#include "parsing.h"

int	parse_map(t_game *game, char **argv)
{
	char	*path;
	char	**map;

	path = argv[1];
	map = read_all(path, &game->map.total_lines);
	if (!map)
		return (1);

	game->map.grid = map;
	game->map.rows = game->map.total_lines;
	/* Optionally compute cols as max line length */
	return (0);
}
