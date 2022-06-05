#include "test.h"
#include <stdio.h>
#include <stdlib.h>

int	key_hook(int code, t_var *var);
int	ft_exit(t_var *var);

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*img2;
	int		x;
	int		y;
	char	*img_path = "test_anim.xpm";
	char	*img2_path = "icons8-42-50.xpm";
	t_var	var;

	x = 0;
	y = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "im the name of the window");
	var.mlx = mlx;
	var.win = mlx_win;
	img = mlx_xpm_file_to_image(mlx, img_path, &x, &y);
	img2 = mlx_xpm_file_to_image(mlx, img2_path, &x, &y);
	var.img = img;
	var.img2 = img2;
	var.x = x;
	var.y = y;
	if (!img)
		return (0);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img2, var.x, var.y);
	mlx_hook(var.win, 2, 1L<<0,  &key_hook, &var);
	mlx_hook(var.win, 33, 1L<<0, &ft_exit, &var);
	mlx_loop(mlx);
}

int	key_hook(int code, t_var *var)
{
	if (code == 65307)
		ft_exit(var);
	if (code == 97)
	{
		var->x -= 5;
		mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
		mlx_put_image_to_window(var->mlx, var->win, var->img2, var->x, var->y);
	}
	if (code == 119)
	{
		var->y -= 5;
		mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
		mlx_put_image_to_window(var->mlx, var->win, var->img2, var->x, var->y);
	}
	if (code == 100)
	{
		var->x += 5;
		mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
		mlx_put_image_to_window(var->mlx, var->win, var->img2, var->x, var->y);

	}
	if (code == 115)
	{
		var->y += 5;
		mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
		mlx_put_image_to_window(var->mlx, var->win, var->img2, var->x, var->y);
	}
	return (0);
}


int	ft_exit(t_var *var)
{
	mlx_destroy_window(var->mlx, var->win);
	exit(0);
	return (0);
}
/*	while (1)
	{
		while (x < 1000)
		{
			mlx_put_image_to_window(mlx, mlx_win, img2, x, y);
			x++;
			y++;
		}
		while (x < 1800)
		{
			mlx_put_image_to_window(mlx, mlx_win, img2, x, y);
			x++;
			y--;
		}
		while (x > 50)
		{
			if (x % 11 == 0)
				y--;
			mlx_put_image_to_window(mlx, mlx_win, img2, x, y);
			x--;
		}
	}*/
