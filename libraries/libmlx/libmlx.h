/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libmlx.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 00:49:12 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/09 10:28:50 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/** 
 * Written by W2.Wizard
 * Library for easy using of the shitty weak ass minilibx.
 * 
 * All files are according to the norme of 42 (V3)
 */
#ifndef LIBMLX_H
# define LIBMLX_H
# include "libft.h"
# include "mlx.h"
# include <math.h>

//= Key Inputs =//

typedef enum e_mask
{
	KEY_PRESS		= 0x02,
	KEY_RELEASE		= 0x03,
	MOUSE_PRESS		= 0x04,
	MOUSE_RELEASE	= 0x04,
	MOUSE_MOVE		= 0x06,
	DESTROY_NOTIFY	= 0x11,
}	t_masks;

typedef enum e_mouse
{
	MOUSE_LEFT_BUTTON		= 1,
	MOUSE_RIGHT_BUTTON		= 2,
	MOUSE_SCROLL_UP			= 4,
	MOUSE_SCROLL_DOWN		= 5,
}	t_mouse;

typedef enum e_keys
{
	ARROW_UP				= 126,
	ARROW_DOWN				= 125,
	ARROW_LEFT				= 123,
	ARROW_RIGHT				= 124,
	KEY_ESC					= 53,
	KEY_UP					= 116,
	KEY_DOWN				= 121,
	KEY_0					= 29,
	KEY_Q					= 12,
	KEY_E					= 14,
	KEY_W					= 13,
	KEY_A					= 0,
	KEY_S					= 1,
	KEY_D					= 2,
	KEY_LESS				= 43,
	KEY_MORE				= 47,
}	t_keys;

//= Types =//

/** 
 * @param mlx Pointer to the mlx instance.
 * @param win Pointer to the mlx window instance.
 */
typedef struct s_mlx
{
	void		*mlx;
	void		*win;
}	t_mlx;

typedef enum s_color
{
	WHITE		= 0xFFFFFF,
	BLACK		= 0x000000,
	RED			= 0xFF0000,
	GREEN		= 0x00FF00,
	BLUE		= 0x0000FF,
	BRICK_RED	= 0xC2294E,
}	t_color;

/** 
 * @param mlx Pointer to the mlx instance.
 * @param win Pointer to the mlx window instance.
 */
typedef struct s_point
{
	t_i32	x;
	t_i32	y;
}	t_point;

/**
 * @param width The Width
 * @param height The Height
 * @param pixels The literal pixel array data
 * @param bit_per_pixel kinda useless ? (just devide by 8 somewhere ?)
 * @param line_length The length of a single line of the canvas of pixels, 
 * line_length * {num to skip} + {index} 
 * @param endian Useless shit for reading the bmp (incase of colors)
 * 
 * The term canvas refers to "image" in mlx.
 */
typedef struct s_canvas
{
	void	*img;
	char	*pixels;
	t_i32	width;
	t_i32	height;
	t_i32	bits_per_pixel;
	t_i32	line_length;
	t_i32	endian;
}	t_canvas;

//= Functions =//

/** 
 * Initilizes a new instance of MLX and a window.
 * @param mlx_out The creates instance
 * @param width The width
 * @param height The height
 * @param title The title of the window
 * @returns Has the initilization succeeded or failed.
 */
t_bool		ft_init(t_mlx *mlx_out, t_u32 width, t_u32 height, char	*title);

/** 
 * TODO: Descr
 * @param mlx
 * @param event
 * @param func
 * @param param
 */
t_i32		ft_hook(t_mlx *mlx, t_u32 event, int (*func)(), void *param);

/** 
 * TODO: Descr
 * @param mlx
 * @param func
 * @param param
 */
t_i32		ft_key_hook(t_mlx *mlx, t_i32 (*func)(), void *param);

/** 
 * Puts a string onto the screen (without buffering).
 * @param mlx The mlx instance.
 * @param pos The position.
 * @param color The color.
 * @param text The text to display.
 */
void		ft_set_string(t_mlx *mlx, t_point pos, t_i32 color, char *text);

/** 
 * Creates a new canvas to paint on.
 * @param mlx The MLX pointer.
 * @param width	In pixels, the width of the canvas.
 * @param height In pixels, the height of the canvas.
 * @returns A new allocated canvas to draw on.
 */
t_canvas	*ft_create_canvas(t_mlx *mlx, t_i32 width, t_i32 height);

/** 
 * Displays the canvas
 * @param mlx The MLX pointer.
 * @param width	In pixels, the width of the canvas.
 * @param height In pixels, the height of the canvas.
 * @returns Some random int???.
 */
t_i32		ft_put_canvas(t_mlx *mlx, t_canvas *canvas, t_point pos);

/** 
 * Clears the window.
 * @param mlx The MLX pointer.
 * @returns Wheter clearing was executed.
 */
t_bool		ft_clear_window(t_mlx *mlx);

/** 
 * Sets the pixel of the given canvas to a color.
 * @param canvas The canvas to paint on.
 * @param point The pixel coordinate.
 * @param color The ARGB color.
 */
void		ft_set_pixel(t_canvas *canvas, t_point point, t_i32 color);

/** 
 * Gets the pixel of the given canvas to a color in ARGB.
 * @param canvas The canvas to paint on.
 * @param point The pixel coordinate.
 */
t_i32		*ft_get_pixel(t_canvas *canvas, t_point point);

/** 
 * Draws a single line from start (s) to end (e) with a given color.
 * @param canvas The canvas to paint on.
 * @param s The source point.
 * @param e The target point.
 * @param color The color to used to draw the line.
 * @returns A new allocated canvas to draw on.
 */
void		ft_draw_line(t_canvas *canvas, t_point s, t_point e);

/** 
 * Creates an ARGB color out of 4 individual color channels.
 * @param A The alpha channel, for mlx this is transparency.
 * @param R The red channel.
 * @param G The green channel.
 * @param B The blue channel.
 * @returns All four color channels into a single int. e.g: (0xFF00FF00)
 */
t_i32		ft_ARGB(t_u8 A, t_u8 R, t_u8 G, t_u8 B);

/** 
 * Point constructor.
 * @param X The X coordinate.
 * @param Y The Y coordinate.
 * @returns A new point with the specified X, Y coordinates.
 */
t_point		ft_point(t_i32 X, t_i32 Y);
#endif