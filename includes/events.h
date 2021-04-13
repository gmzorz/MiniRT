/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 10:39:01 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 12:31:30 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# include <scene.h>
# define MASK_BUTTON		0L
# define CAM_MOVE			0.5
# define CAM_LOOK			3.6
# define FOV_SCALAR			1
# define KEY_DOWN			2
# define EXIT_WINDOW		17
# define CAM_SWITCH_N		"Switched to next camera"
# define CAM_SWITCH_P		"Switched to previous camera"
# if IS_BONUS == 1
#  include <events_bonus.h>
# endif

typedef enum e_key
{
	Esc = 53,
	Q = 12,
	W = 13,
	E = 14,
	R = 15,
	T = 17,
	Y = 16,
	U = 32,
	I = 34,
	O = 31,
	A = 0,
	S = 1,
	D = 2,
	J = 38,
	K = 40,
	L = 37,
	Z = 6,
	X = 7,
	Enter = 36,
	One = 18,
	Two = 19,
	Three = 20,
	Four = 21,
	Five = 23,
	Six = 22,
	Seven = 26,
	Comma = 43,
	Dot = 47,
	Space = 49,
	Plus = 24,
	Minus = 27,
	Shift = 257,
	Up = 125,
	Down = 126,
	NOKEY = -1
}	t_key;

/*
**	Handlers
*/

int		key_handle(int key, t_scene *scene);
int		close_program(t_scene *scene);

/*
**	Events
*/

t_bool	free_and_exit(t_scene *scene);
t_bool	render_unlit(t_scene *scene);
t_bool	render_flat(t_scene *scene);
t_bool	render_aabb(t_scene *scene);
t_bool	render_scene(t_scene *scene);
t_bool	next_cam(t_scene *scene);
t_bool	prev_cam(t_scene *scene);

#endif
