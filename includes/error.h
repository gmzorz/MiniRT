/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 16:44:04 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 11:43:05 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# if IS_BONUS == 1
#  include <error_bonus.h>
# endif
# include <alias.h>
# include <buffer.h>
# include <scene.h>
# define WARN_RES_MAX_RES "Resolution will be fixed to monitor max"
# define WARN_FOV_RANGE "Field of view is out of range (1 ... 180)"
# define ERR_SCENE_ALLOC_FAILED "Scene allocation failed"
# define ERR_SCENE_INIT_FAILED "Scene initialization failed"
# define ERR_MLX_INIT_FAILED "MLX initialization failed"
# define ERR_BMP_HEADER "Failed to write BMP header(s)"
# define ERR_BMP_BUFFER "Failed to write BMP data"
# define ERR_WRONG_FD "Wrong file descriptor"
# define ERR_PAR_EXT "File extension does not match required format (.rt)"
# define ERR_PAR_REAL "Cannot parse real number"
# define ERR_PAR_INT "Cannot parse integer"
# define ERR_PAR_UNIT "Unit double out of range (-1.0/0.0 ... 1.0)"
# define ERR_PAR_COL "Color value out of range (0 ... 255)"
# define ERR_PAR_NOID "Bad identifier in .rt file"
# define ERR_PAR_DELIM "Bad delimiter (Missing parameter)"
# define ERR_RES_EXISTS "Resolution can only be set once in scene"
# define ERR_RES_NEG "Resolution cannot be negative or zero"
# define ERR_AMB_EXISTS "Ambience can only be set once in scene"
# define ERR_UNUSED_PARAM "Unused paremeter"
# define ERR_VEC_FAILURE "Cannot convert string to vector3"
# define ERR_SCENE_FAILURE "Could not compute scene"
# define ERR_INVALID_NORMAL "Normal value out of range (-1.0 ... 1.0)"
# define ERR_ZERO_NORMAL "Normal vector does not have a precise direction"
# define ERR_CAM_ADD "Failed to add camera to list (is NULL)"
# define ERR_SHAPE_ADD "Failed to add shape to list (is NULL)"
# define ERR_ALLOC_CAM "Failed to allocate memory for camera"
# define ERR_ALLOC_SHAPE "Failed to allocate memory for shape"
# define ERR_ALLOC_LIGHT "Failed to allocate memory for light"
# define ERR_ALLOC_SPHERE "Failed to allocate memory for sphere"
# define ERR_ALLOC_PLANE "Failed to allocate memory for plane"
# define ERR_ALLOC_SQUARE "Failed to allocate memory for square"
# define ERR_ALLOC_CYLINDER "Failed to allocate memory for cylinder"
# define ERR_ALLOC_TRIANGLE "Failed to allocate memory for triangle"
# define ERR_ALLOC_HITRECORD "Failed to allocate memory for hitrecord"
# define ERR_UNDEF_RES "Resolution not set"
# define ERR_UNDEF_CAM "Camera(s) not set"

void	error_exit(char *message);
t_bool	error_msg(char *message);
t_bool	error_free(char *message, void *ptr);
t_bool	error_line(char *line);
t_bool	error_close_fd(int fd, char *message);
t_bool	error_set_null(void *set, char *message);
t_bool	error_free_and_exit(t_scene *scene, char *message);
t_bool	warning_msg(char *message);
t_bool	warning_line(char *line, char *message);

#endif