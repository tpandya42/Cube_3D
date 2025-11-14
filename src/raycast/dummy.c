# include "cub.h"

void    fill_colors(t_game *game)
{
    //floor -> gray
    game->floor.r = 128;
    game->floor.g = 128;
    game->floor.b = 128;
    game->floor.hex = (game->floor.r << 16)
        | (game->floor.g << 8) | game->floor.b;
    
    //ceiling light blue
    game->ceiling.r = 135;
    game->ceiling.g = 206;
    game->ceiling.b = 250;
    game->ceiling.hex = (game->ceiling.r << 16) 
        | (game->ceiling.g << 8) | game->ceiling.b;
}

void    dummy_map(t_game *game)
{
    static char *dummy_map[10] = {
        "1111111111",
        "1000000001",
        "1011111101",
        "1000000001",
        "1011111101",
        "1001000001",
        "1011111101",
        "1000000001",
        "1111111111",
        "1111111111"
    };
    game->map.rows = 10;
    game->map.cols = 10;
    game->map.grid = dummy_map;
}

void    dummy_player(t_game *game)
{
    game->player.ini_x = 1.5;
    game->player.ini_y = 1.5;
    game->player.x = game->player.ini_x;
    game->player.y = game->player.ini_y;
}

void    fill_dummy(t_game *game)
{
    fill_colors(game);
    dummy_map(game);
    dummy_player(game);
}