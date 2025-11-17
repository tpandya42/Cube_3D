#include "cub.h"

char	**read_all(const char *path, int *total_lines)
{
	int		fd;
	char	**grid;
	char	*line;
	int		count;
	char	**tmp;
	int		len;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	grid = NULL;
	count = 0;
	len = 0;
	while ((line = get_next_line(fd)))
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		tmp = malloc(sizeof(*tmp) * (count + 1));
		if (grid)
		{
			ft_memcpy(tmp, grid, sizeof(*tmp) * count);
			free(grid);
		}
		grid = tmp;
		grid[count++] = line;
	}
	close(fd);
	*total_lines = count;
	return (grid);
}
