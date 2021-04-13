/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wfobj_utils_bonus.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 14:42:14 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 18:01:20 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>
#include <stdlib.h>
#include <unistd.h>

/*
**	Translate origin to the bottom of the object
**	Then compare to centroid and construct accordingly
*/

void	wfobj_set_origin(t_trimesh *mesh)
{
	mesh->centroid = vec3_avg(mesh->volume.min, mesh->volume.max);
	mesh->origin = vec3_add(mesh->origin,
			(t_vec3){mesh->centroid.x, mesh->volume.max.y, mesh->centroid.z});
	mesh->construct = true;
}

void	wfobj_close_and_free(int fd, char *line)
{
	close(fd);
	if (line)
		free(line);
}

t_bool	wfobj_face_assign(char **line, t_trimesh *mesh, int num)
{
	if (!parse_int(line, &mesh->face[num].idx[0])
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_int(line, &mesh->face[num].idx[1])
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_int(line, &mesh->face[num].idx[2])
		|| !parse_eol(line))
		return (false);
	if (mesh->face[num].idx[0] > mesh->verts || mesh->face[num].idx[0] < 0
		|| mesh->face[num].idx[1] > mesh->verts || mesh->face[num].idx[1] < 0
		|| mesh->face[num].idx[2] > mesh->verts || mesh->face[num].idx[2] < 0)
		return (error_msg(ERR_IDX_FACES));
	mesh->face[num].vert[0] = &mesh->vert[mesh->face[num].idx[0] - 1];
	mesh->face[num].vert[1] = &mesh->vert[mesh->face[num].idx[1] - 1];
	mesh->face[num].vert[2] = &mesh->vert[mesh->face[num].idx[2] - 1];
	return (true);
}

t_bool	wfobj_error_free(t_trimesh *mesh, char *msg)
{
	if (mesh->vert)
		free(mesh->vert);
	if (mesh->face)
		free(mesh->face);
	if (mesh)
		free(mesh);
	if (msg)
		return (error_msg(msg));
	return (false);
}

t_bool	parse_wfobj_vector(char **line, t_vertex *vertex, t_aabb *volume)
{
	if (!parse_real(line, &vertex->point.x)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_real(line, &vertex->point.y)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_real(line, &vertex->point.z)
		|| !parse_unused(line))
		return (error_msg(ERR_VEC_FAILURE));
	volume_add_vec(volume, vertex->point);
	return (true);
}
