/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trimesh_construct_bonus.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 10:11:10 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:34:29 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <init.h>

static void	vertnml_reset(t_vertex **in, int count)
{
	t_vertex	*verts;
	int			idx;

	idx = 0;
	verts = *in;
	while (idx < count)
	{
		verts[idx].normal = vec3_zero();
		idx += 1;
	}
}

static void	vertnml_compute(t_vec3 *vn, t_vec3 *surf)
{
	if (vec3_cmp(*vn, vec3_zero()))
		*vn = *surf;
	else
		*vn = vec3_mult_s(vec3_add(*vn, *surf), 0.5);
	*vn = vec3_unit(*vn);
}

static void	mesh_face_construct(t_meshtri *face, t_vec3 *vn1, t_vec3 *vn2,
	t_vec3 *vn3)
{
	face->edge[0] = vec3_sub(face->vert[1]->point, face->vert[0]->point);
	face->edge[1] = vec3_sub(face->vert[2]->point, face->vert[1]->point);
	face->edge[2] = vec3_sub(face->vert[0]->point, face->vert[2]->point);
	face->normal = vec3_cross(face->edge[2], face->edge[0]);
	face->denom = 1 / vec3_dot(face->normal, face->normal);
	face->traverse = -vec3_dot(face->normal, face->vert[0]->point);
	face->dot_aa = vec3_dot(face->edge[0], face->edge[0]);
	face->dot_ab = vec3_dot(face->edge[0], face->edge[1]);
	face->dot_bb = vec3_dot(face->edge[1], face->edge[1]);
	vertnml_compute(vn1, &face->normal);
	vertnml_compute(vn2, &face->normal);
	vertnml_compute(vn3, &face->normal);
	volume_init(&face->volume);
	volume_add_vec(&face->volume, face->vert[0]->point);
	volume_add_vec(&face->volume, face->vert[1]->point);
	volume_add_vec(&face->volume, face->vert[2]->point);
	face->volume.centroid = vec3_avg(face->volume.min, face->volume.max);
}

/*
**	Transform mesh to translated origin, if origin is different to centroid
*/

static void	mesh_set_translate(t_trimesh *mesh)
{
	t_vec3	diff;
	int		idx;

	if (vec3_cmp(mesh->origin, mesh->centroid))
		return ;
	volume_init(&mesh->volume);
	diff = vec3_sub(mesh->centroid, mesh->origin);
	idx = 0;
	while (idx < mesh->verts)
	{
		mesh->vert[idx].point = vec3_sub(mesh->vert[idx].point, diff);
		volume_add_vec(&mesh->volume, mesh->vert[idx].point);
		idx += 1;
	}
	mesh->centroid = vec3_avg(mesh->volume.min, mesh->volume.max);
}

t_bool	trimesh_construct(t_shapes *catch)
{
	t_trimesh	*mesh;
	int			numface;

	mesh = catch->shape;
	if (vec3_cmp_s(mesh->span_a, 0.0))
		vec3_local_coords(mesh->normal, &mesh->span_a, &mesh->span_b);
	mesh_set_translate(mesh);
	catch->volume.using = true;
	catch->volume = mesh->volume;
	numface = 0;
	vertnml_reset(&mesh->vert, mesh->verts);
	while (numface < mesh->faces)
	{
		mesh_face_construct(&mesh->face[numface],
			&mesh->vert[mesh->face[numface].idx[0] - 1].normal,
			&mesh->vert[mesh->face[numface].idx[1] - 1].normal,
			&mesh->vert[mesh->face[numface].idx[2] - 1].normal);
		numface += 1;
	}
	bvh_construct(mesh);
	mesh->construct = false;
	return (true);
}
