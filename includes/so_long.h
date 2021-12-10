#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libraries/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include "../libraries/mlx/mlx.h"
# define SPRITE_SIZE 40
# include <fcntl.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_map
{
	int				x;
	int				y;
	char			content;
	struct s_map	*next;
}	t_map;

typedef enum e_keys
{
	ARROW_UP	= 126,
	ARROW_DOWN	= 125,
	ARROW_LEFT	= 123,
	ARROW_RIGHT	= 124,
	ESC			= 53,
	KEY_W		= 13,
	KEY_A		= 0,
	KEY_S		= 1,
	KEY_D		= 2,
}	t_keys;

typedef struct s_bugs
{
	int				x;
	int				y;
	char			content;
	t_data			bug;
	struct s_bugs	*next;
}	t_bugs;

typedef struct s_info
{
	int		info_h;
	int		info_w;
	t_data	num[10];
	t_data	bugs[4];
	t_data	moves[5];
	t_data	blank;
}	t_info;

typedef struct s_tarantulas
{
	t_data	up[4];
	t_data	down[4];
	t_data	left[4];
	t_data	right[4];
}	t_tarantulas;

typedef struct s_player
{
	int		x;
	int		y;
	int		new_x;
	int		new_y;
	int		diff_x;
	int		diff_y;
	int		mv_pxl;
	int		mv_x;
	int		mv_y;
	int		cur_img;
	t_data	*img;
}	t_player;

typedef struct s_img_t_hawk
{
	t_data	img[4];
}	t_img_t_hawk;

typedef struct s_t_hawk_list
{
	t_player				*t_hawk;
	struct s_t_hawk_list	*next;
}	t_t_hawk_list;

typedef struct s_tools
{
	t_vars			*vars;
	t_map			*map;
	int				map_w;
	int				map_h;
	int				map_pxl_w;
	int				map_pxl_h;
	t_data			canvas;
	t_map			*walls;
	t_data			sand;
	t_data			cactus;
	t_tarantulas	tarantulas;
	t_player		player;
	t_t_hawk_list	*t_hawks;
	int				num_t_hawks;
	t_data			hovel;
	int				e_x;
	int				e_y;
	t_data			bug[3];
	t_bugs			*bugs;
	t_data			yummy[3];
	int				yum;
	int				num_bugs;
	int				t_x;
	int				t_y;
	int				moves;
	t_info			info;
	int				empty;
}	t_tools;

//so_long
int				ft_strlen_c(char *str, char c);
void			clear_map(t_map	*map);

//t_map utils
t_map			*ft_mapnew(int x, int y, char content);
void			ft_mapadd_back(t_map **lst, t_map *new);
void			ft_mapadd_front(t_map **lst, t_map *new);
void			ft_mapclear(t_map **lst);
t_map			*ft_maplast(t_map *map);

//t_bugs utils
t_bugs			*ft_bugsnew(int x, int y, char content);
void			ft_bugsadd_back(t_bugs **lst, t_bugs *new);
void			ft_bugsadd_front(t_bugs **lst, t_bugs *new);
void			ft_bugsclear(t_bugs **lst);
t_bugs			*ft_bugslast(t_bugs *bugs);

//generate_map
int				generate_map(char *input, t_tools *tools);
int				convert_map(char *init, t_map **map, int y);
int				check_invalid(t_map	*map, int x, int y);

//my pxl put
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			canvas_p_pixel_put(t_data *canvas, int x, int y, t_player *player);
void			canvas_pixel_put(t_data *canvas, int x, int y, t_data *sprite);
void			canvas_info_pixel_put(int w, int x_y[2], t_data *canvas, t_data *sprite);

//create_img
t_data			convert_xpm(char *rel_p, t_vars vars);
t_data			create_img(t_tools *tools, int w, int h);
void			draw_map(t_tools *tools);
void			draw_t_hawks(t_tools *tools, t_t_hawk_list *t_hawks);

//init_info
void			color_box(int x_y[2], int i_j[2], t_data *img);
void			initialize_numbers(t_info *info, t_vars *vars);
void			initialize_info(t_tools *tools);

//draw_info
void			draw_info(t_tools *tools, t_info *info);
void			draw_moves_info(t_tools *tools, t_info *info, int x_y[2], int moves);
void			draw_bug_info_double(t_tools *tools, t_info *info, int x_y[2], int bugs);
void			draw_bug_info(t_tools *tools, t_info *info, int x_y[2], int bugs);

//tools_tools.c
void			initiate_tools(t_tools *tools);
void			initialize_yum(t_tools *tools);
void			create_canvas(t_tools *tools);
int				find_start(t_tools **tools);
void			find_walls(t_tools **tools);

//bugs
void			assign_bugs(t_tools *tools);
void			initiate_bug(t_tools *tools);
void			find_bugs(t_tools **tools);
void			yummy(t_tools *tools);
int				change_coordinate(t_tools *tools);

//tarantula
void			initiate_tarantula(t_tools *tools);
void			initiate_tarantula_r_l(t_tools *tools);
int				check_tarantula(t_player *player, t_tools *tools);

//key_hook
int				check_wasd(int keycode, t_tools *tools);

//loop
int				loop(t_tools *tools);

//t_hawk_utils
t_t_hawk_list	*ft_t_hawk_listnew(t_player *t_hawk);
void			ft_t_hawk_listadd_back(t_t_hawk_list **lst, t_t_hawk_list *new);
void			ft_t_hawk_listadd_front(t_t_hawk_list **lst, t_t_hawk_list *new);
void			ft_t_hawk_listclear(t_t_hawk_list **lst);
t_t_hawk_list	*ft_t_hawk_listlast(t_t_hawk_list *bugs);

//initiate_t_hawk
void			initiate_t_hawk(t_tools *tools, t_player *t_hawk);
int				determine_num_t_hawks(int empty);
int				create_t_hawk_list(t_tools *tools);
void	find_start_pos_t_hawk(t_tools *tools, t_player *t_hawk);

//t_hawk
int				**assign_pos(t_player *t_hawk);
int				check_not_all_neg(int **pos);
void			find_new_pos_t_hawk(t_tools *tools, t_player *t_hawk);
int				check_pos(t_map	*walls, t_t_hawk_list *l_t_hawk, int x, int y);
int				check_t_hawk(t_player *t_hawk, t_tools *tools);

//utils_bonus
int				ft_rand(int weight);
int				determine_empty_space(t_map *map);

#endif