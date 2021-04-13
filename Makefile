# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: goosterl <goosterl@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/20 14:14:46 by goosterl      #+#    #+#                  #
#    Updated: 2021/04/13 15:36:29 by goosterl      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#-----------------------#
# COMPILATION ASSETS	#
#-----------------------#
NAME		=	MiniRT
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
FRAMEW  	=	-framework OpenGl -framework AppKit
LIBINC		=	libft.a						\
				libmlx.a

#-----------------------#
# HEADERS				#
#-----------------------#
HEADERS_DIR	=	./includes/
HEADERS_BON =	./includes_bonus/

#-----------------------#
# BONUS HEADERS			#
#-----------------------#
BON_INC		=	./includes_bonus/

#-----------------------#
# SOURCE FILES			#
#-----------------------#
SRC			=	./sources/minirt.c								\
				\
				./sources/init/scene_init.c						\
				./sources/init/buffer_init.c					\
				./sources/init/hook_init.c						\
				./sources/init/camera_ray_init.c				\
				./sources/init/aabb_init.c						\
				\
				./sources/bitmap/bmp_headers.c					\
				./sources/bitmap/bmp.c							\
				\
				./sources/close/free_scene.c					\
				./sources/close/free_cameras.c					\
				./sources/close/free_shapes.c					\
				./sources/close/free_lights.c					\
				./sources/close/destroy_mlx.c					\
				\
				./sources/events/free_and_exit.c				\
				./sources/events/close_program.c				\
				./sources/events/handler.c						\
				./sources/events/render_flat.c					\
				./sources/events/render_unlit.c					\
				./sources/events/render_aabb.c					\
				./sources/events/render_scene.c					\
				./sources/events/switch_cam.c					\
				\
				./sources/console/message.c						\
				\
				./sources/parse/parser.c						\
				./sources/parse/parse_id.c						\
				./sources/parse/parse_fail.c					\
				./sources/parse/parse_skip.c					\
				./sources/parse/parse_vector.c					\
				./sources/parse/parse_normal.c					\
				./sources/parse/parse_color.c					\
				./sources/parse/parse_material.c				\
				./sources/parse/parse_real.c					\
				./sources/parse/parse_int.c						\
				./sources/parse/parse_unused.c					\
				./sources/parse/parse_resolution.c				\
				./sources/parse/parse_ambience.c				\
				./sources/parse/parse_camera.c					\
				./sources/parse/parse_camera_push.c				\
				./sources/parse/parse_shape.c					\
				./sources/parse/parse_light.c					\
				./sources/parse/parse_light_push.c				\
				./sources/parse/parse_sphere.c					\
				./sources/parse/parse_plane.c					\
				./sources/parse/parse_square.c					\
				./sources/parse/parse_cylinder.c				\
				./sources/parse/parse_triangle.c				\
				\
				./sources/scene/update.c						\
				./sources/scene/trace.c							\
				./sources/scene/render.c						\
				\
				./sources/shader/shader.c						\
				./sources/shader/unlit.c						\
				./sources/shader/flat.c							\
				./sources/shader/shaded.c						\
				./sources/shader/aabb.c							\
				\
				./sources/intersect/hit.c						\
				./sources/intersect/aabb.c						\
				./sources/intersect/aabb_test.c					\
				./sources/intersect/construct.c					\
				./sources/intersect/intersect.c					\
				./sources/intersect/sphere_construct.c			\
				./sources/intersect/sphere_intersect.c			\
				./sources/intersect/plane_construct.c			\
				./sources/intersect/plane_intersect.c			\
				./sources/intersect/square_construct.c			\
				./sources/intersect/square_intersect.c			\
				./sources/intersect/cylinder_construct.c		\
				./sources/intersect/cylinder_intersect.c		\
				./sources/intersect/triangle_construct.c		\
				./sources/intersect/triangle_intersect.c		\
				\
				./sources/vector/add.c							\
				./sources/vector/sub.c							\
				./sources/vector/mult.c							\
				./sources/vector/div.c							\
				./sources/vector/cross.c						\
				./sources/vector/dot.c							\
				./sources/vector/unit.c							\
				./sources/vector/magnitude.c					\
				./sources/vector/compare.c						\
				./sources/vector/greater.c						\
				./sources/vector/less.c							\
				./sources/vector/zero.c							\
				./sources/vector/abs.c							\
				./sources/vector/clamp.c						\
				./sources/vector/negate.c						\
				./sources/vector/reflect.c						\
				./sources/vector/average.c						\
				./sources/vector/local_coords.c					\
				./sources/vector/id.c							\
				\
				./sources/matrix/mat4_add_vec.c					\
				./sources/matrix/mat4_get.c						\
				./sources/matrix/mat4_identity.c				\
				./sources/matrix/mat4_lookat.c					\
				./sources/matrix/mat4_mult_dir.c				\
				./sources/matrix/mat4_mult.c					\
				./sources/matrix/mat4_rot_around.c				\
				./sources/matrix/mat4_rotation.c				\
				./sources/matrix/mat4_sub_vec.c					\
				./sources/matrix/mat4.c							\
				\
				./sources/buffer/get_addr_loc.c					\
				./sources/buffer/get_color_at.c					\
				./sources/buffer/new_buffer.c					\
				./sources/buffer/destroy_buffer.c				\
				./sources/buffer/write_color_at.c				\
				\
				./sources/color/rgb_to_data.c					\
				./sources/color/data_to_rgb.c					\
				./sources/color/check.c							\
				\
				./sources/jump/parse.c							\
				./sources/jump/key.c							\
				./sources/jump/intersect.c						\
				./sources/jump/shader.c							\
				./sources/jump/construct.c						\
				\
				./sources/utils/write.c							\
				./sources/utils/clamp.c							\
				./sources/utils/pow_2.c							\
				./sources/utils/welcome.c						\
				./sources/utils/get_point.c						\
				./sources/utils/setcnd.c						\
				./sources/utils/scene_completion.c				\
				\
				./sources/error/error_msg.c						\
				./sources/error/error_free.c					\
				./sources/error/error_close_fd.c				\
				./sources/error/error_set_null.c				\
				./sources/error/error_free_and_exit.c			\
				./sources/error/error_exit.c					\
				./sources/error/warning.c						\
				\
				./sources/get_next_line/get_next_line.c			\
				./sources/get_next_line/get_next_line_utils.c	\

OBJ			=	$(SRC:.c=.o)

#-----------------------#
# BONUS SOURCE FILES	#
#-----------------------#
BON_SRC		=	./sources/console/message_bonus.c				\
				\
				./sources/init/hook_init_bonus.c				\
				./sources/init/buffer_init_bonus.c				\
				./sources/init/scene_init_bonus.c				\
				./sources/init/camera_ray_init_bonus.c			\
				./sources/init/thread_init_bonus.c				\
				./sources/init/material_init_bonus.c			\
				\
				./sources/close/free_shapes_bonus.c				\
				./sources/close/free_textures_bonus.c			\
				./sources/close/destroy_mlx_bonus.c				\
				\
				./sources/parse/parse_material_bonus.c			\
				./sources/parse/parse_texture_bonus.c			\
				./sources/parse/parse_id_bonus.c				\
				./sources/parse/parse_aa_bonus.c				\
				./sources/parse/parse_skybox_bonus.c			\
				./sources/parse/parse_light_parallel_bonus.c	\
				./sources/parse/parse_camera_bonus.c			\
				./sources/parse/parse_cylinder_cap_bonus.c		\
				./sources/parse/parse_disk_bonus.c				\
				./sources/parse/parse_brdf_bonus.c				\
				./sources/parse/parse_cube_bonus.c				\
				./sources/parse/parse_pyramid_bonus.c			\
				./sources/parse/parse_sun_bonus.c				\
				./sources/parse/parse_wfobj_bonus.c				\
				./sources/parse/parse_wfobj_utils_bonus.c		\
				./sources/parse/parse_wave_bonus.c				\
				./sources/parse/parse_bool_bonus.c				\
				./sources/parse/parse_threads_bonus.c			\
				./sources/parse/parse_viewport_bonus.c			\
				\
				./sources/scene/update_bonus.c					\
				./sources/scene/render_bonus.c					\
				./sources/scene/sassaa_bonus.c					\
				./sources/scene/selected_bonus.c				\
				./sources/scene/trace_bonus.c					\
				./sources/scene/skybox_bonus.c					\
				./sources/scene/brdf_render_bonus.c				\
				./sources/scene/brdf_trace_bonus.c				\
				./sources/scene/brdf_threading_bonus.c			\
				\
				./sources/textures/set_diffuse_bonus.c			\
				./sources/textures/set_normals_bonus.c			\
				./sources/textures/set_gloss_bonus.c			\
				./sources/textures/set_reflection_bonus.c		\
				./sources/textures/set_specularity_bonus.c		\
				./sources/textures/set_textures_bonus.c			\
				./sources/textures/set_roughness_bonus.c		\
				./sources/textures/set_emission_bonus.c			\
				\
				./sources/filter/sobel_bonus.c					\
				./sources/filter/sobel_kernel_bonus.c			\
				\
				./sources/shader/normals_bonus.c				\
				./sources/shader/units_bonus.c					\
				./sources/shader/uvs_bonus.c					\
				./sources/shader/shaded_bonus.c					\
				./sources/shader/dof_bonus.c					\
				\
				./sources/intersect/plane_construct_bonus.c		\
				./sources/intersect/plane_intersect_bonus.c		\
				./sources/intersect/sphere_intersect_bonus.c	\
				./sources/intersect/square_intersect_bonus.c	\
				./sources/intersect/triangle_intersect_bonus.c	\
				./sources/intersect/triangle_construct_bonus.c	\
				./sources/intersect/cylinder_intersect_bonus.c	\
				./sources/intersect/cylinder_construct_bonus.c	\
				./sources/intersect/disk_intersect_bonus.c		\
				./sources/intersect/disk_construct_bonus.c		\
				./sources/intersect/cube_intersect_bonus.c		\
				./sources/intersect/cube_construct_bonus.c		\
				./sources/intersect/pyramid_intersect_bonus.c	\
				./sources/intersect/pyramid_construct_bonus.c	\
				./sources/intersect/trimesh_construct_bonus.c	\
				./sources/intersect/trimesh_intersect_bonus.c	\
				./sources/intersect/bvh_construct_bonus.c		\
				\
				./sources/buffer/copy_buffer_bonus.c			\
				./sources/buffer/new_tex_buffer_bonus.c			\
				./sources/buffer/get_uv_color_at_bonus.c		\
				\
				./sources/jump/key_bonus.c						\
				./sources/jump/shader_bonus.c					\
				./sources/jump/mouse_bonus.c					\
				./sources/jump/parse_bonus.c					\
				./sources/jump/intersect_bonus.c				\
				./sources/jump/construct_bonus.c				\
				./sources/jump/translate_bonus.c				\
				\
				./sources/events/transform_x_bonus.c			\
				./sources/events/transform_y_bonus.c			\
				./sources/events/transform_z_bonus.c			\
				./sources/events/render_brdf_bonus.c			\
				./sources/events/render_normals_bonus.c			\
				./sources/events/render_units_bonus.c			\
				./sources/events/render_uvs_bonus.c				\
				./sources/events/render_dof_bonus.c				\
				./sources/events/mouse_handler_bonus.c			\
				./sources/events/select_shape_bonus.c			\
				./sources/events/screenshot_bonus.c				\
				./sources/events/shape_translate_set_bonus.c	\
				./sources/events/shape_axis_set_bonus.c			\
				./sources/events/shape_translate_bonus.c		\
				./sources/events/deselect_bonus.c				\
				./sources/events/translate_bonus.c				\
				./sources/events/rotate_bonus.c					\
				./sources/events/cube_translate_bonus.c			\
				./sources/events/plane_translate_bonus.c		\
				./sources/events/sphere_translate_bonus.c		\
				./sources/events/square_translate_bonus.c		\
				./sources/events/cylinder_translate_bonus.c		\
				./sources/events/disk_translate_bonus.c			\
				./sources/events/triangle_translate_bonus.c		\
				./sources/events/pyramid_translate_bonus.c		\
				./sources/events/trimesh_translate_bonus.c		\
				./sources/events/dof_adjust_bonus.c				\
				./sources/events/fov_adjust_bonus.c				\
				./sources/events/free_and_exit_bonus.c			\
				\
				./sources/vector/hemisphere_bonus.c				\
				./sources/vector/bounds_bonus.c					\
				\
				./sources/utils/random_bonus.c					\
				./sources/utils/trim_path_bonus.c				\
				./sources/utils/tiling_bonus.c					\
				./sources/utils/greyscale_bonus.c				\

BON_OBJ		=	$(BON_SRC:.c=.o)

ifdef IS_BONUS
ALL_OBJ		=	$(OBJ) $(BON_OBJ)
ALL_INC		=	$(HEADERS_DIR) -I $(HEADERS_BON)
ALL_CFL		=	$(CFLAGS) -D IS_BONUS=1
else
ALL_OBJ		=	$(OBJ)
ALL_INC		=	$(HEADERS_DIR)
ALL_CFL		=	$(CFLAGS)
endif

#-----------------------#
# COMPILING				#
#-----------------------#
all:			$(NAME)

bonus:
				$(MAKE) IS_BONUS=1 clean all
				touch bonus

%.o:			%.c
				$(CC) -I $(ALL_INC) $(ALL_CFL) -c -o $@ $<

$(NAME):		$(ALL_OBJ)
				make -C ./libft/
				make -C ./minilibx_opengl
				cp ./libft/libft.a ./libft.a
				cp ./minilibx_opengl/libmlx.a ./libmlx.a
				$(CC) $(CFLAGS) $(FRAMEW) $(LIBINC) $(ALL_OBJ) -o $(NAME)

clean:
				rm -rf $(OBJ) $(BON_OBJ) bonus

fclean:			clean
				make clean -C ./minilibx_opengl
				make fclean -C ./libft
				rm -rf $(NAME) libmlx.a libft.a bonus

re:				fclean all

.PHONY:			all, clean, fclean, re
