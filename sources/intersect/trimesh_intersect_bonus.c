/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trimesh_intersect_bonus.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 10:34:45 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:35:07 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <utils.h>
#include <math.h>

static t_vec3	face_get_normal(t_meshtri *face, t_triangle_vars *vars)
{
	t_vec3	nml[3];
	t_vec3	hitnml;

	nml[0] = vec3_mult_s(face->vert[2]->normal, 1 - vars->u - vars->v);
	nml[1] = vec3_mult_s(face->vert[0]->normal, vars->u);
	nml[2] = vec3_mult_s(face->vert[1]->normal, vars->v);
	hitnml = vec3_add(vec3_add(nml[0], nml[1]), nml[2]);
	return (hitnml);
}

static t_bool	face_tests(t_meshtri *face, t_triangle_vars *vars, t_vec3 *nml)
{
	t_vec3		diff[3];
	t_real		test[3];

	diff[0] = vec3_sub(vars->p, face->vert[0]->point);
	test[0] = vec3_dot(face->normal, vec3_cross(face->edge[0], diff[0]));
	if (test[0] < 0)
		return (false);
	diff[1] = vec3_sub(vars->p, face->vert[1]->point);
	test[1] = vec3_dot(face->normal, vec3_cross(face->edge[1], diff[1]));
	if (test[1] < 0)
		return (false);
	vars->u = test[1] * face->denom;
	diff[2] = vec3_sub(vars->p, face->vert[2]->point);
	test[2] = vec3_dot(face->normal, vec3_cross(face->edge[2], diff[2]));
	if (test[2] < 0)
		return (false);
	vars->v = test[2] * face->denom;
	*nml = face_get_normal(face, vars);
	return (true);
}

static t_bool	face_intersect(t_meshtri *face, t_hitrecord *rec)
{
	t_triangle_vars	vars;

	vars.pl = vec3_dot(face->normal, rec->ray.dir);
	if (fabs(vars.pl) < M_EPSILON)
		return (false);
	vars.t = - (vec3_dot(face->normal, rec->ray.origin) + face->traverse)
		/ vars.pl;
	if (vars.t < M_EPSILON || vars.t > rec->distance)
		return (false);
	vars.p = get_point(rec->ray.origin, rec->ray.dir, vars.t);
	if (!face_tests(face, &vars, &rec->normal))
		return (false);
	rec->normal = vec3_unit(rec->normal);
	if (vars.pl > 0)
		rec->normal = vec3_negate(rec->normal);
	rec->tex.u = vars.u;
	rec->tex.v = vars.v;
	rec->point = vars.p;
	rec->distance = vars.t;
	return (true);
}

static t_bool	bvh_intersect(t_bvhnode *root, t_hitrecord *rec)
{
	int		idx;
	t_bool	hit;

	idx = 0;
	if (!root || root->size == 0 || !aabb_test(rec->ray, root->volume, NULL))
		return (false);
	hit = false;
	if (root->depth == 0)
	{
		while (idx < root->size)
		{
			if (aabb_test(rec->ray, root->faces[idx]->volume, NULL)
				&& face_intersect(root->faces[idx], rec))
				hit = true;
			idx += 1;
		}
		return (hit);
	}
	while (idx < 8)
	{
		if (bvh_intersect(&root->branch[idx], rec))
			hit = true;
		idx += 1;
	}
	return (hit);
}

t_bool	trimesh_intersect(t_shapes *catch, t_hitrecord *rec)
{
	t_trimesh	*mesh;
	t_bool		hit;
	int			idx;

	hit = false;
	idx = 0;
	mesh = catch->shape;
	if (bvh_intersect(&mesh->root, rec))
	{
		rec->ref = catch;
		return (true);
	}
	return (false);
	if (hit)
		rec->ref = catch;
	return (hit);
}
