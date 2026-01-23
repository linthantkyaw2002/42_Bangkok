/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* animation_utils_bonus.c                            :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: lkyaw <lkyaw@student.42.fr>                +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/01/24 00:50:00 by lkyaw             #+#    #+#             */
/* Updated: 2026/01/24 00:50:00 by lkyaw            ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "so_long_bonus.h"

/* ** Creates an animation object from an array of XPM paths.
** Reuses your mandatory load_img to set up t_img textures.
*/
void	update_exit_anim(t_game *g)
{
	t_anim	*a;

	a = g->exit_anim;
	if (!a)
		return ;
	a->tick++;
	if (a->tick < a->speed)
		return ;
	a->tick = 0;
	if (g->exit_open && a->current < a->frame_count - 1)
		a->current++;
	else if (!g->exit_open && a->current > 0)
		a->current--;
}

t_anim	*anim_create(t_game *g, char **paths, int speed)
{
	t_anim	*anim;
	int		i;

	anim = malloc(sizeof(t_anim));
	if (!anim)
		return (NULL);
	anim->frame_count = 0;
	while (paths[anim->frame_count])
		anim->frame_count++;
	anim->frames = malloc(sizeof(t_img) * anim->frame_count);
	if (!anim->frames)
	{
		free(anim);
		return (NULL);
	}
	i = -1;
	while (++i < anim->frame_count)
		load_img(g, &anim->frames[i], paths[i]);
	anim->current = 0;
	anim->speed = speed;
	anim->tick = 0;
	return (anim);
}

/* ** Increments the animation frame based on the 'speed' (tick) value.
*/
void	update_anim(t_anim *anim)
{
	if (!anim)
		return ;
	anim->tick++;
	if (anim->tick >= anim->speed)
	{
		anim->current = (anim->current + 1) % anim->frame_count;
		anim->tick = 0;
	}
}

/* ** Properly destroys all MLX images in the animation before freeing.
*/
void	free_anim(t_game *g, t_anim *anim)
{
	int	i;

	if (!anim)
		return ;
	i = 0;
	while (i < anim->frame_count)
	{
		if (anim->frames[i].ptr)
			mlx_destroy_image(g->mlx, anim->frames[i].ptr);
		i++;
	}
	free(anim->frames);
	free(anim);
}