#ifndef TEST_H
# define TEST_H

# include "mlx.h"
# include <stddef.h>
typedef enum e_bool{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_pos{
	int	x;
	int	y;
}		t_pos;

typedef	struct s_key
{
	t_bool	up;
	t_bool	down;
	t_bool	left;
	t_bool	right;
}			t_key;

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
	void	*img3;
	t_pos	start;
	t_pos	end;
	int		x;
	int		y;

	t_key	key;
}			t_var;

int	display(t_var *var);
int	key_press(int code, t_var *var);
void	ft_apply(t_var *var);
int	key_release(int code, t_var *var);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_animate_object(void *src, void *dest, t_var *var);
#endif
