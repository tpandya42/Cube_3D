
# include "cub.h"
# include "dummy.h"

int	main(void)
{
	t_game	game;

	//PARSING
	if(init_init(&game)) //init mlx and win
	{
		print_error("Error: Game init failed");
		return (1);
	}
    fill_dummy(&game);
	if (!create_win(&game.disp))
		return (1);
	//render_scene(&data);
	mlx_hook(game.disp.win, 17, 0, close_winx, &game);//events to close
	//mlx_key_hook(data.win, key_handle, &data);//events
	DEBUG_LOG("Player position: (%.2f, %.2f)", game.player.x, game.player.y);
	DEBUG_LOG("Window size: %dx%d", WIN_WIDTH, WIN_HEIGHT);
	mlx_loop(game.disp.mlx);
	return (0);
}
