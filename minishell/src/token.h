/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkang <jihkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:06:32 by jihkang           #+#    #+#             */
/*   Updated: 2022/10/27 19:52:41 by jihkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef enum e_type
{
	TYPE_STR,
	TYPE_PIPE,
	TYPE_QUTOES,
	TYPE_DBQUTOES,
	TYPE_BR_OPEN,
	TYPE_BR_CLOSE,
	TYPE_REDIRIN,
	TYPE_HEREDOC,
	TYPE_TRUNC,
	TYPE_APPEND,	
}t_type;

typedef struct s_token
{
	struct s_token	*next;
	char			*value;
}t_token;

void	add_first(t_token **tkn, char *value);
void	add_last(t_token **tkn, char *value);
void	clear_list(t_token **tkn);
void	print_list(t_token *tkn);

#endif