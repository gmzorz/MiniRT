/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pyramid_construct_bonus.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 16:40:05 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:33:41 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <init.h>
# include <utils.h>

static t_square	pyr_base_construct(t_pyramid *pyr, t_vec3 *corners, t_aabb *vol)
{
	t_square	sq;

	sq.origin = pyr->origin;
	sq.normal = pyr->normal;
	sq.span_a = pyr->span_a;
	sq.span_b = pyr->span_b;
	sq.size = pyr->base_size;
	corners[0] = vec3_add(sq.origin, vec3_mult_s(sq.span_a, sq.size / 2));
	corners[0] = vec3_add(corners[0], vec3_mult_s(sq.span_b, sq.size / 2));
	corners[1] = vec3_sub(corners[0], vec3_mult_s(sq.span_b, sq.size));
	corners[2] = vec3_sub(corners[1], vec3_mult_s(sq.span_a, sq.size));
	corners[3] = vec3_add(corners[2], vec3_mult_s(sq.span_b, sq.size));
	volume_add_vec(vol, corners[0]);
	volume_add_vec(vol, corners[1]);
	volume_add_vec(vol, corners[2]);
	volume_add_vec(vol, corners[3]);
	return (sq);
}

static t_triangle	pyr_face_construct(t_vec3 apex, t_vec3 v1, t_vec3 v2)
{
	t_triangle	tri;

	tri.vert[0] = apex;
	tri.vert[1] = v1;
	tri.vert[2] = v2;
	tri.edge[0] = vec3_sub(tri.vert[1], tri.vert[0]);
	tri.edge[1] = vec3_sub(tri.vert[2], tri.vert[1]);
	tri.edge[2] = vec3_sub(tri.vert[0], tri.vert[2]);
	tri.normal = vec3_cross(tri.edge[2], tri.edge[0]);
	tri.denom = 1 / vec3_dot(tri.normal, tri.normal);
	tri.traverse = -vec3_dot(tri.normal, tri.vert[0]);
	tri.dot_aa = vec3_dot(tri.edge[0], tri.edge[0]);
	tri.dot_ab = vec3_dot(tri.edge[0], tri.edge[1]);
	tri.dot_bb = vec3_dot(tri.edge[1], tri.edge[1]);
	return (tri);
}

t_bool	pyramid_construct(t_shapes *catch)
{
	t_pyramid	*pyr;
	t_vec3		corners[4];
	t_vec3		apex;
	int			idx;

	pyr = catch->shape;
	if (vec3_cmp_s(pyr->span_a, 0.0))
		vec3_local_coords(pyr->normal, &pyr->span_b, &pyr->span_a);
	volume_init(&catch->volume);
	pyr->base = pyr_base_construct(pyr, corners, &catch->volume);
	idx = 0;
	apex = get_point(pyr->origin, pyr->normal, pyr->height);
	volume_add_vec(&catch->volume, apex);
	while (idx < 4)
	{
		pyr->face[idx] = pyr_face_construct(apex, corners[idx % 4],
				corners[(idx + 1) % 4]);
		idx += 1;
	}
	return (true);
}

#endif
