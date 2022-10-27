/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkang <jihkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:04:26 by jihkang           #+#    #+#             */
/*   Updated: 2022/10/27 20:13:57 by jihkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include "token.h"

typedef struct s_tree
{
	struct s_tree	*left;
	struct s_tree	*right;
	int				type;
	char			*value;
	t_token			*token;
}t_tree;

#endif