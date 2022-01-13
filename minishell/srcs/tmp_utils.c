#include "libft.h"
#include "bool.h"
#include "error_msgs.h"
#include "builtins.h"
#include "actions_handler.h"

static inline char	*get_builtins_name(int type)
{
	if (type == echo)
		return ("echo");
	if (type == cd)
		return ("cd");
	if (type == pwd)
		return ("pwd");
	if (type == export)
		return ("export");
	if (type == unset)
		return ("unset");
	if (type == env_built)
		return ("env_built");
	if (type == exit_built)
		return ("exit_built");
	return ("undefind");
}

static inline char	*get_action_type_name(t_action action)
{
	if (action.type == execute)
		return ("execute");
	else
		return (get_builtins_name(action.type));
}

static inline char	*get_redirect_type_name(t_redirect redirect)
{
	if (redirect.type == input)
		return ("input");
	if (redirect.type == read_input)
		return ("read_input");
	if (redirect.type == output)
		return ("output");
	if (redirect.type == output_append)
		return ("output_append");
	return ("undefined");
}

static inline void	print_actions(t_actions *actions, int i, int j)
{
	i = 0;
	while (i < actions->len)
	{
		ft_printf("\naction: %i\n type: %s\n argv:", i,
			get_action_type_name(actions->item[i]));
		j = 0;
		while (actions->item[i].exec.argv[j])
			ft_printf(" %s", actions->item[i].exec.argv[j++]);
		ft_printf("\n");
		ft_printf(" redirect_in: type: %s, target: %s",
			get_redirect_type_name(actions->item[i].redirect_in),
			actions->item[i].redirect_in.target);
		if (actions->item[i].redirect_in.target == NULL)
			ft_printf("\n");
		ft_printf(" redirect_out: type: %s, target: %s\n",
			get_redirect_type_name(actions->item[i].redirect_out),
			actions->item[i].redirect_out.target);
		i++;
	}
}
