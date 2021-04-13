/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube_construct_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/18 15:02:51 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:33:01 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <init.h>
# include <utils.h>

/*
**	Construct a face based on a local coordinate system, and add corners
**	to bounding volume
*/

static t_square	face_construct(t_cube *cb, t_vec3 coords[3], t_aabb *vol)
{
	t_square	sq;
	t_vec3		corners[4];
	t_real		half_size;

	half_size = cb->size / 2;
	sq.origin = get_point(cb->origin, coords[0], half_size);
	sq.normal = coords[0];
	sq.span_a = coords[1];
	sq.span_b = coords[2];
	sq.size = cb->size;
	corners[0] = vec3_add(sq.origin, vec3_mult_s(sq.span_a, half_size));
	corners[0] = vec3_add(corners[0], vec3_mult_s(sq.span_b, half_size));
	corners[1] = vec3_sub(corners[0], vec3_mult_s(sq.span_b, cb->size));
	corners[2] = vec3_sub(corners[0], vec3_mult_s(sq.span_a, cb->size));
	corners[3] = vec3_sub(corners[2], vec3_mult_s(sq.span_b, cb->size));
	volume_add_vec(vol, corners[0]);
	volume_add_vec(vol, corners[1]);
	volume_add_vec(vol, corners[2]);
	volume_add_vec(vol, corners[3]);
	return (sq);
}

static void	cube_span_construct(t_cube *cb, t_vec3 *span)
{
	if (vec3_cmp_s(cb->span_a, 0.0))
		vec3_local_coords(cb->normal, &cb->span_a, &cb->span_b);
	span[0] = cb->normal;
	span[1] = cb->span_a;
	span[2] = cb->span_b;
	span[3] = vec3_negate(span[0]);
	span[4] = vec3_negate(span[1]);
	span[5] = vec3_negate(span[2]);
}

/*
**	For a cube, we need to provide all the squares required with an origin,
**	normal and size. the orientation is a bit tricky since a square is not
**	entirely defined with just one normal (normal axis orientation may vary).
**	In order to get this right, all the squares should follow the same
**	coordinate system alignment.
**	Compute two coordinate systems, one using the normal and the other as the
**	inverse of the first system, then assign to 6-part coordinate structure and
**	cycle through. we create a face based on the coordinate system of each
**	side of the cube. Computing these systems for each face results in wrong
**	alignments, so we compute them all before hand (which is also cheaper to
**	compute)
*/

t_bool	cube_construct(t_shapes *catch)
{
	t_cube		*cb;
	t_vec3		span[6];
	t_vec3		coords[3];
	int			idx;

	cb = catch->shape;
	cube_span_construct(cb, span);
	idx = 0;
	volume_init(&catch->volume);
	while (idx < 6)
	{
		coords[0] = span[idx % 6];
		coords[1] = span[(idx + 1) % 6];
		coords[2] = span[(idx + 2) % 6];
		cb->face[idx] = face_construct(cb, coords, &catch->volume);
		idx += 1;
	}
	return (true);
}

#endif
