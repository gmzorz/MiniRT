/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_bonus.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 16:44:04 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/08 17:32:34 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_BONUS_H
# define ERROR_BONUS_H
# if IS_BONUS == 1
#  define ERR_AA_EXISTS "Anti Aliasing can only be set once in scene"
#  define ERR_SUN_EXISTS "Sun can only be set once in scene"
#  define ERR_TF_CONDITION "Parameter input should either be 0 or 1"
#  define WARN_AA_SAMPLES "Illogical AA sample count, consider clamping to 64"
#  define ERR_BAD_MAT "Could not find .mat file"
#  define ERR_BAD_LINE "Line could not be parsed"
#  define ERR_XPM_NOIMG "Failed to load image into buffer"
#  define ERR_BAD_PREFIX "Invalid parameter (missing -mat prefix?)"
#  define ERR_MAT_PROP "Bad material property in .mat file"
#  define ERR_BAD_TEX "Could not locate texture file"
#  define ERR_ADD_TEX "Could not add texture to file collection"
#  define ERR_ALLOC_TEX "Failed to locate or allocate memory for texture"
#  define ERR_TEX_DEF_EXISTS "Texture definition already exists"
#  define ERR_SKY_EXISTS "Skybox can only be set once in scene"
#  define WARN_BRDF_SET "No parameters given for BRDF, setting default.."
#  define ERR_ALLOC_DISK "Failed to allocate memory for disk"
#  define ERR_BRDF_EXISTS "BRDF can only be set once"
#  define ERR_SPP_NEG "Input for sample count can only be > 1 and positive"
#  define ERR_DPT_NEG "Input for depth count can only be > 1 and positive"
#  define ERR_ALLOC_CUBE "Failed to allocate memory for cube"
#  define ERR_ALLOC_PYRAMID "Failed to allocate memory for pyramid"
#  define ERR_WAVE_UV "Wave direction not set (inputs: u, v, uv)"
#  define ERR_ALLOC_THREADS "Failed to allocate memory for threads"
#  define ERR_ALLOC_THR_DATA "Failed to allocate memory for thread data"
#  define ERR_THR_EXISTS "Threading option can only be set once"
#  define ERR_INVALID_THRDNUM "Invalid input for thread count"
#  define ERR_BAD_OBJ "Could not find .obj file"
#  define ERR_ALLOC_MESH "Failed to allocate memory for triangle mesh"
#  define ERR_OBJ_VERTS "Object does not contain any vertices and/or faces"
#  define ERR_ALLOC_FACES "Failed to allocate memory for object faces"
#  define ERR_ALLOC_VERTS "Failed to allocate memory for object vertices"
#  define ERR_IDX_FACES "vertice index does not match object vertex count"
#  define ERR_VERT_FAILURE "Failed to index object vertices"
#  define ERR_FACE_FAILURE "Failed to index object faces"
#  define ERR_VP_SCALE "Undefined viewport scale (full, half, quarter)"
#  define ERR_ALLOC_BVH_BRANCH "Failed to allocate memory for BVH branch"
#  define ERR_ALLOC_BVH_FACES "Failed to allocate memory for branch face list"
#  define WARN_FETCH_DT "Could not fetch time & date, saving as screenshot.bmp\
	instead ("
#  define ERR_MISSING_EMIS "Missing emission parameter"
#  define ERR_MISSING_GMMA "Missing de-gamma parameter"
#  define ERR_DOF_TYPE "Dof type invalid\n	0 = Off/Shapemask\n	1 = Spheric\n\
	2 = Anamorphic"
# endif
#endif
