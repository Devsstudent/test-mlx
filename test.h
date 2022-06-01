#ifndef TEST_H
# define TEST_H

# include <mlx.h>

typedef struct s_data{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_var{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img2;
	int		x;
	int		y;
}			t_var;

#endif
