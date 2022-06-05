#include "test.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_exit(t_var *var);

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*img2;
	void	*img3;
	int		x;
	int		y;
	char	*img_path = "test.xpm";
	char	*img2_path = "icons8-42-50.xpm";
	char	*img3_path = "coins.xpm";
	t_var	var;

	x = 0;
	y = 0;
	var.key.up = FALSE;
	var.key.down = FALSE;
	var.key.left = FALSE;
	var.key.right = FALSE;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "im the name of the window");
	var.mlx = mlx;
	var.win = mlx_win;
	img = mlx_xpm_file_to_image(mlx, img_path, &x, &y);
	img2 = mlx_xpm_file_to_image(mlx, img2_path, &x, &y);
	img3 = mlx_xpm_file_to_image(mlx, img3_path, &x, &y);
	var.img = img;
	var.img2 = img2;
	var.img3 = img3;
	var.x = x;
	var.y = y;
	if (!img)
		return (0);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop_hook(var.mlx, &display, &var);
	mlx_hook(var.win, 2, 1L<<0,  &key_press, &var);
	mlx_hook(var.win, 3, 1L<<1,  &key_release, &var);
	mlx_hook(var.win, 33, 1L<<0, &ft_exit, &var);
	mlx_loop(mlx);
}

void	ft_apply(t_var *var)
{
	if (var->key.left)
		var->x -= 5;
	else if (var->key.right)
		var->x += 5;
	else if (var->key.up)
		var->y -= 5;
	else if (var->key.down)
		var->y += 5;
}

int	key_release(int code, t_var *var)
{
	if (code == 65307)
	{
		ft_exit(var);
		return (0);
	}
	if (code == 97)
		var->key.left = FALSE;
	else if (code == 119)
		var->key.up = FALSE;
	else if (code == 100)
		var->key.right = FALSE;
	else if (code == 115)
		var->key.down = FALSE;
	return (0);
}

int	display(t_var *var)
{
		static int i;
		void *img;

		var->end.x = 32*(i + 1);
		var->end.y = 32;
		var->start.x = 32*i;
		var->start.y = 32;
		if (i == 2)
		{
			var->end.x = 32;
			var->end.y = 32;
			var->start.x = 0;
			var->start.y = 0;
		}
		ft_apply(var);
		mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
		mlx_put_image_to_window(var->mlx, var->win, var->img2, var->x, var->y);
		img = mlx_new_image(var->mlx, 32, 32);
		ft_animate_object(var->img3, img, var);
		mlx_put_image_to_window(var->mlx, var->win, var->img3, 500, 500);
		mlx_destroy_image(var->mlx, img);
		return (0);
}

int	key_press(int code, t_var *var)
{
	if (code == 97)
		var->key.left = TRUE;
	if (code == 119)
		var->key.up = TRUE;
	if (code == 100)
		var->key.right = TRUE;
	if (code == 115)
		var->key.down = TRUE;
	return (0);
}
//Je decal de 32  start et end 
//SRC = BIG LOAD L'image entiere
//Dest = l'adresse de limage cree de 32 par 32

void	ft_animate_object(void *src, void *dest, t_var *var)
{
	int	size_line;
	int	bpp;
	int	endian;
	int	i;

	(void) dest;
	mlx_get_data_addr(var->img3, &bpp ,&size_line, &endian);
	while ()
	{

	}
	//fair appel a get data addr 
	//ou lire a partir de start de combien pixel il faut avancer en fonction de start et end formule
	//read les 1024 pixels 
	//copier dans dests
	//return la nouvelle image
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
