/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_camera_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 15:02:02 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:39:48 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <error.h>
# include <libft.h>
# include <parse.h>
# include <math.h>

static t_bool	parse_dof(t_scene *scene, char **line, t_dof *params)
{
	char			*id;

	id = parse_id(line);
	if (id == NULL)
		return (true);
	if (!ft_match(id, DOF_FLAG))
		return (error_free(ERR_UNUSED_PARAM, id));
	params->enable = true;
	free(id);
	if (!parse_int(line, &params->shape_type)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_real(line, &params->aperture)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_real(line, &params->focal_dist))
		return (false);
	if (params->shape_type > 2 || params->shape_type < 0)
		return (error_msg(ERR_DOF_TYPE));
	*line += ft_strspn(*line, DELIM_SPACE);
	if (**line == '\0')
		return (true);
	return (parse_tex(scene, line, &params->shape));
}

t_bool	parse_camera(t_scene *scene, char **line)
{
	t_camera		*cam;

	cam = (t_camera *)ft_calloc(1, sizeof(t_camera));
	if (cam == NULL)
		return (error_msg(ERR_ALLOC_CAM));
	if (!parse_vector(line, &cam->origin)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_normal(line, &cam->normal)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_real(line, &cam->fov)
		|| !parse_dof(scene, line, &cam->dof)
		|| !parse_eol(line))
		return (parse_failure(cam));
	if (cam->fov <= 0 || cam->fov >= 180)
		warning_msg(WARN_FOV_RANGE);
	cam->view_range = tan((cam->fov * 0.5) * (M_PI / 180));
	cam->world = mat4_lookat(cam->origin, vec3_add(cam->origin, cam->normal));
	scene->cam_count += 1;
	if (scene->cam_count == 1)
		scene->camera = cam;
	return (cam_push_back(&scene->cameras, cam, scene->cam_count));
}

#endif
