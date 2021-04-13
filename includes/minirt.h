/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:14:37 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 00:06:29 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define RT_TITLE "miniRT"
# define SCENE_INIT "Initializing scene"
# define WIN_INIT "Setting up window"
# define BUF_INIT "Setting up main image buffer"
# define MLX_INIT "Initializing minilibX functions"
# define RT_READY "Ready"
# define RT_EXIT "Shutting down miniRT"
# define RT_FREE_CAM "Cleaning up cameras"
# define RT_FREE_SHAPES "Cleaning up shapes"
# define RT_FREE_SCENE "Cleaning up scene"
# define RT_DESTROY "Destroying image(s) and window"
# define RT_SS "Saving screenshot: "
# define RT_RENDER "Rendering scene..."
# define RT_AA_PASS "Applying sassaa (AA) pass"
# include <scene.h>

void	console_put(char *message);
void	console_putnn(char *message);
void	console_putstr(char *message, char *str);
void	destroy_mlx(t_scene *scene);
void	free_cameras(t_camlist **list);
void	free_shapes(t_shapes **shapes);
void	free_lights(t_lights **lights);
void	free_scene(t_scene *scene);

#endif
