/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wfobj_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 11:49:30 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:43:25 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <get_next_line.h>
#include <libft.h>
#include <fcntl.h>
#include <error.h>
#include <utils.h>
#include <init.h>

/*
**	count vertices
*/

static void	obj_count(char **file, int *verts, int *faces)
{
	t_fileinf	inf;
	char		*id;

	*verts = 0;
	*faces = 0;
	inf.fd = open(*file, O_RDONLY);
	while (get_next_line(inf.fd, &inf.line) > 0)
	{
		inf.line_cpy = inf.line;
		id = parse_id(&inf.line);
		if (id)
		{
			if (ft_match(id, "v"))
				*verts += 1;
			else if (ft_match(id, "f"))
				*faces += 1;
			free(id);
		}
		free(inf.line_cpy);
	}
	free(inf.line);
	close(inf.fd);
}

static t_bool	add_mesh_faces(char **file, t_trimesh *mesh)
{
	t_fileinf	inf;
	int			num;
	char		*id;

	inf.fd = open(*file, O_RDONLY);
	inf.success = true;
	num = 0;
	while (get_next_line(inf.fd, &inf.line) > 0)
	{
		inf.line_cpy = inf.line;
		id = parse_id(&inf.line);
		if (id && ft_match(id, "f"))
		{
			if (!wfobj_face_assign(&inf.line, mesh, num))
				inf.success = false;
			num += 1;
		}
		free(inf.line_cpy);
		if (id)
			free(id);
	}
	wfobj_close_and_free(inf.fd, inf.line);
	if (!inf.success)
		return (error_msg(ERR_VERT_FAILURE));
	return (true);
}

t_bool	add_mesh_verts(char **file, t_trimesh *mesh)
{
	t_fileinf	inf;
	int			num;
	char		*id;

	inf.fd = open(*file, O_RDONLY);
	inf.success = true;
	num = 0;
	while (get_next_line(inf.fd, &inf.line) > 0)
	{
		inf.line_cpy = inf.line;
		id = parse_id(&inf.line);
		if (id && ft_match(id, "v"))
		{
			if (!parse_wfobj_vector(&inf.line, &mesh->vert[num], &mesh->volume))
				inf.success = false;
			num += 1;
		}
		free(inf.line_cpy);
		if (id)
			free(id);
	}
	wfobj_close_and_free(inf.fd, inf.line);
	if (!inf.success)
		return (error_msg(ERR_VERT_FAILURE));
	return (add_mesh_faces(file, mesh));
}

t_bool	allocate_mesh(t_scene *scene, char **file, char **line)
{
	t_trimesh	*mesh;
	t_material	mat;

	mesh = (t_trimesh *)ft_calloc(1, sizeof(t_trimesh));
	if (!mesh)
		return (error_msg(ERR_ALLOC_MESH));
	obj_count(file, &mesh->verts, &mesh->faces);
	if (mesh->verts == 0 || mesh->faces == 0)
		return (error_free(ERR_OBJ_VERTS, mesh));
	mesh->face = (t_meshtri *)ft_calloc(1, sizeof(t_meshtri) * mesh->faces);
	if (!mesh->face)
		return (wfobj_error_free(mesh, ERR_ALLOC_FACES));
	mesh->vert = (t_vertex *)ft_calloc(1, sizeof(t_vertex) * mesh->verts);
	if (!mesh->vert)
		return (wfobj_error_free(mesh, ERR_ALLOC_VERTS));
	volume_init(&mesh->volume);
	if (!add_mesh_verts(file, mesh)
		|| !parse_vector(line, &mesh->origin)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_material(scene, line, &mat))
		return (wfobj_error_free(mesh, NULL));
	wfobj_set_origin(mesh);
	return (shape_push_back(&scene->shapes, mesh, mat, sh_trimesh));
}

t_bool	parse_wfobj(t_scene *scene, char **line)
{
	int			fd_check;
	char		*file;

	*line += ft_strspn(*line, DELIM_SPACE);
	file = trim_path(line);
	*line += ft_strspn(*line, DELIM_SPACE);
	fd_check = open(file, O_RDONLY);
	if (fd_check < 3 || !ft_matchend(file, ".obj"))
	{
		free(file);
		return (error_msg(ERR_BAD_OBJ));
	}
	close(fd_check);
	if (!allocate_mesh(scene, &file, line))
	{
		free(file);
		return (false);
	}
	free(file);
	return (parse_eol(line));
}
