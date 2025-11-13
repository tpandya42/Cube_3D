#include "cub.h"

static int	map_extension_checker(char *map)
{
	int	i;

	if (!map)
		return (0);
	i = ft_strlen(map) - 1;
	if (map[i] == 'b' && map[i - 1] == 'u'
		&& map[i - 2] == 'c' && map[i - 3] == '.')
		return (1);
	return (0);
}

int	verify(int argc, char **av)
{
	int	fd;

	if (argc != 2)
	{
		ft_printf("Invalid Inputs\n");
		exit(1);
	}
	if (map_extension_checker(av[1]) == 0)
	{
		ft_printf("Invalid Map Extension\n");
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Can't open file\n");
		exit(1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	verify(argc, argv);
	//init_struct(&game);
	//check_map(argv[1], &game);
	//start_game(&game);
	//exit_game(&game);
}
