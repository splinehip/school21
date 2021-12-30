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
	if (type == env)
		return ("env");
	if (type == exit_built)
		return ("exit_built");
	return ("undefind");
}

static inline char	*get_action_type_name(t_actions action)
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
	while (actions[i].end != true)
	{
		ft_printf("\naction: %i\n type: %s\n argv:", i,
			get_action_type_name(actions[i]));
		j = 0;
		while (actions[i].args.argv[j])
			ft_printf(" %s", actions[i].args.argv[j++]);
		ft_printf("\n");
		j = 0;
		if (actions[i].args.redirect)
		{
			while (actions[i].args.redirect[j].end != true)
			{
				ft_printf(" redirect %i: type: %s, target: %s\n", j,
					get_redirect_type_name(actions[i].args.redirect[j]),
					actions[i].args.redirect[j].target);
				j++;
			}
		}
		else
			ft_printf(" redirects: none\n");
		i++;
	}
}
