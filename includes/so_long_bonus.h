/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long_bonus.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgraaf <mgraaf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 16:21:55 by mgraaf        #+#    #+#                 */
/*   Updated: 2021/12/16 14:33:13 by mgraaf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
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
	KEY_R		= 15,
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
	t_data	err[2];
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

typedef struct s_enemy_list
{
	t_player			enemy;
	struct s_enemy_list	*next;
}	t_enemy_list;

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
	t_enemy_list	*enemys;
	int				num_enemys;
	t_data			enemy[4];
	t_data			hovel;
	t_map			*exit;
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
	int				i;
	int				j;
	t_data			game_over[6];
	t_data			so_long[4];
	int				g_o;
	int				s_o;
}	t_tools;

//so_long
int				extra_keys(int key_code, t_tools *tools);
int				destroy_window(t_tools *tools);
void			free_all(t_tools *tools);

//t_map utils
t_map			*ft_mapnew(int x, int y, char content);
void			ft_mapadd_back(t_map **lst, t_map *new);
void			ft_mapdelone(t_map **lst, char key);
void			ft_mapclear(t_map **lst);
t_map			*ft_maplast(t_map *map);

//t_bugs utils
t_bugs			*ft_bugsnew(int x, int y, char content);
void			ft_bugsadd_back(t_bugs **lst, t_bugs *new);
void			ft_bugsadd_front(t_bugs **lst, t_bugs *new);
void			ft_bugsclear(t_bugs **lst);
t_bugs			*ft_bugslast(t_bugs *bugs);

//generate_map
void			generate_map(char *input, t_tools *tools);
int				convert_map(char *init, t_map **map, int y);
int				check_invalid(t_map	*map, int x, int y);

//my pxl put
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			canvas_p_pixel_put(t_data *canvas, int x,
					int y, t_player *player);
void			canvas_pixel_put(t_data *canvas, int x, int y, t_data *sprite);
void			canvas_info_pixel_put(int w, int x_y[2],
					t_data *canvas, t_data *sprite);

//create_img
t_data			create_img(t_tools *tools, int w, int h);
void			draw_enemys(t_tools *tools, t_enemy_list *enemys);
t_bugs			*locate_bug(t_bugs	*bugs, int x, int y);

//img_utils
t_data			convert_xpm(char *rel_p, t_vars vars);
void			draw_map(t_tools *tools);
void			color_box(int x_y[2], int i_j[2], t_data *img, int color);
void			initiate_end_game(t_tools *tools);

//init_info
void			initialize_numbers(t_info *info, t_vars *vars);
void			initialize_info(t_tools *tools);

//draw_info
void			draw_info(t_tools *tools, t_info *info);
void			draw_moves_info(t_tools *tools, t_info *info,
					int x_y[2], int moves);
void			draw_bug_info_double(t_tools *tools, t_info *info,
					int x_y[2], int bugs);
void			draw_bug_info(t_tools *tools, t_info *info,
					int x_y[2], int bugs);
int				draw_error(t_tools *tools, t_info *info, int x_y[2]);

//tools_tools.c
void			initiate_tools(t_tools *tools);
void			initialize_extra_img(t_tools *tools);
void			create_canvas(t_tools *tools);

//find.c
void			find_exits(t_tools **tools);
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
int				check_death(t_tools	*tools);
int				check_exit(t_tools *tools);

//loop
int				loop(t_tools *tools);
void			clear_player_info(t_player *player);

//enemy_utils
t_enemy_list	*ft_enemy_listnew(t_player *enemy);
void			ft_enemy_listadd_back(t_enemy_list **lst, t_enemy_list *new);
void			ft_enemy_listadd_front(t_enemy_list **lst, t_enemy_list *new);
void			ft_enemy_listclear(t_enemy_list **lst);
t_enemy_list	*ft_enemy_listlast(t_enemy_list *bugs);

//initiate_enemy
void			init_enemy_frames(t_tools *tools);
void			initiate_enemy(t_tools *tools, t_player *enemy);
int				determine_num_enemys(int empty);
void			create_enemy_list(t_tools *tools);
int				find_start_pos_enemy(t_tools *tools, t_player *enemy);

//enemy
t_map			*assign_pos(t_player *enemy);
int				check_not_all_neg(int **pos);
void			find_new_pos_enemy(t_tools *tools, t_player *enemy);
int				check_pos(t_map	*walls, t_tools *tools, int x, int y);
int				check_enemy(t_player *enemy, t_tools *tools);

//utils
int				check_ber(char *input);
int				ft_strlen_c(char *str, char c);
void			clear_map(t_map	*map);
void			ft_error(int i);

//utils_bonus
int				ft_rand(int weight);
int				determine_empty_space(t_map *map);
int				assign_new_number(int x_y);
int				check_start_ok(t_tools *tools, int x, int y);
void			check_fringe(int *x_y, int max);

//end_game
void			end_so_long(t_tools *tools);
void			game_over(t_tools *tools);
void			canvas_end_pixel_put(int x_y[2], t_data *canvas,
					t_data *sprite);

#endif