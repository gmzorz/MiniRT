/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bvh_construct_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/11 16:06:26 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 12:50:29 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <libft.h>
#include <error.h>
#include <vector_bonus.h>
#include <init.h>

static t_bool	bvh_set_elements(t_bvhnode *root, t_bvhnode *branch)
{
	int			root_idx;
	int			branch_idx;

	branch->faces = (t_meshtri **)ft_calloc(1, sizeof(t_meshtri *)
			* branch->size);
	if (!branch->faces)
		return (error_msg(ERR_ALLOC_BVH_FACES));
	root_idx = 0;
	branch_idx = 0;
	while (root_idx < root->size && branch_idx < branch->size)
	{
		if (vec3_is_bounds(root->faces[root_idx]->volume.centroid,
				branch->volume))
		{
			branch->faces[branch_idx] = root->faces[root_idx];
			branch_idx += 1;
		}
		root_idx += 1;
	}
	return (true);
}

/*
**	Get root branch volume, divide by two to get new branch volume size
**	Multiply center_offset by pre-defined offset mask to compute center of
**	branch volume based on index
*/

static t_bool	bvh_set_branch(t_bvhnode *root, t_bvhnode *branch, int idx)
{
	static t_vec3	offset[8] = {
		{-1, 1, -1}, {-1, 1, 1}, {1, 1, -1}, {1, 1, 1},
		{-1, -1, -1}, {-1, -1, 1}, {1, -1, -1}, {1, -1, 1}};
	t_vec3			base_offs;
	t_vec3			center_offset;
	int				r_idx;

	r_idx = 0;
	base_offs = vec3_mult_s(vec3_sub(root->volume.max,
				root->volume.centroid), 0.5);
	center_offset = vec3_mult(offset[idx], base_offs);
	branch->volume.centroid = vec3_add(root->volume.centroid, center_offset);
	branch->volume.max = vec3_add(branch->volume.centroid, base_offs);
	branch->volume.min = vec3_sub(branch->volume.centroid, base_offs);
	while (r_idx < root->size)
	{
		if (vec3_is_bounds(root->faces[r_idx]->volume.centroid, branch->volume))
			branch->size += 1;
		r_idx += 1;
	}
	if (branch->size > 0)
		return (bvh_set_elements(root, branch));
	branch->depth = 0;
	return (true);
}

/*
**	for every branch (and root), assign the vertices based on their centroid
**	if the centroid lies within the bounding volume of the branch, add!
**	if there are none or < 2, we set the end of our branch
**	intersection tests for volumes are still heaps faster than triangle tests
*/

static t_bool	bvh_root_set(t_bvhnode *root)
{
	int			idx;

	if (root->depth == 0)
		return (true);
	root->volume.centroid = vec3_avg(root->volume.min, root->volume.max);
	root->branch = (t_bvhnode *)ft_calloc(1, sizeof(t_bvhnode) * 8);
	if (!root->branch)
		return (error_msg(ERR_ALLOC_BVH_BRANCH));
	idx = 0;
	while (idx < 8)
	{
		root->branch[idx].depth = root->depth - 1;
		if (!bvh_set_branch(root, &root->branch[idx], idx))
			return (false);
		if (root->branch[idx].size > 1
			&& !bvh_root_set(&root->branch[idx]))
			return (false);
		if (root->branch[idx].size < 2)
			root->branch[idx].depth = 0;
		idx += 1;
	}
	return (true);
}

/*
**	After adding vertices, we compute the volume of each node here:
*/

void	set_aggr_volume(t_bvhnode *root)
{
	int	idx;

	idx = 0;
	volume_init(&root->volume);
	while (idx < root->size)
	{
		volume_add_vec(&root->volume, root->faces[idx]->volume.min);
		volume_add_vec(&root->volume, root->faces[idx]->volume.max);
		idx += 1;
	}
	if (root->depth == 0)
		return ;
	idx = 0;
	while (idx < 8)
	{
		if (root->branch[idx].size > 1)
			set_aggr_volume(&root->branch[idx]);
		idx += 1;
	}
}

/*
**	Construct intersection tree for faster intersection results
**	divide mesh into 8 squares, then traverse down the square of intersection,
**	consisting of 8 squares (fractal/octree structure)
*/

t_bool	bvh_construct(t_trimesh *mesh)
{
	int	idx;

	if (mesh->root.faces)
		free_bvh_nodes(&mesh->root);
	mesh->root.size = mesh->faces;
	mesh->root.faces = (t_meshtri **)ft_calloc(1, sizeof(t_meshtri *)
			* mesh->root.size);
	if (!mesh->root.faces)
		return (error_msg(ERR_ALLOC_FACES));
	idx = 0;
	while (idx < mesh->root.size)
	{
		mesh->root.faces[idx] = &mesh->face[idx];
		idx += 1;
	}
	mesh->root.volume = mesh->volume;
	mesh->root.depth = 12;
	if (!bvh_root_set(&mesh->root))
	{
		free_bvh_nodes(&mesh->root);
		return (false);
	}
	set_aggr_volume(&mesh->root);
	return (true);
}
