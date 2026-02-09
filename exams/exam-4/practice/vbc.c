#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

node *factor(char **input);
node *term(char **input);
node *expression(char **input);

node    *new_node(node n)
{
    node *ret = calloc(1, sizeof(node));
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void    destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
}

int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}

//...

node    *parse_expr(char *s)
{
    node *ret = expression(&s);
	if (!ret) return NULL;

    if (*s) 
    {
		unexpected(*s);
        destroy_tree(ret);
        return (NULL);
    }
    return (ret);
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    node *tree = parse_expr(argv[1]);
    if (!tree)
        return (1);
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
}

node *factor(char **input)
{
	node *result;

	while(**input && **input == ' ') (*input)++;

	if(isdigit(**input))
	{
		int digit = **input - '0';
		(*input)++;
		result = new_node((node){.type=VAL, .val=digit});
		if (!result) return NULL;
		return result;
	}
	else if (**input == '(')
	{
		(*input)++;
		result = expression(input);
		if (!result) return NULL;
		if (!expect(input, ')'))
		{
			destroy_tree(result);
			return NULL;
		}
		return result;
	}
	unexpected(**input);
	return NULL;
}

node *term(char **input)
{
	node *l_node = factor(input);
	if (!l_node) return NULL;

	while(**input && **input == ' ') (*input)++;

	while(**input == '*')
	{
		(*input)++;
		node *r_node = factor(input);
		if (!r_node)
		{
			destroy_tree(l_node);
			return NULL;
		}
		node *parent = new_node((node){.type=MULTI, .l=l_node, .r=r_node});
		if (!parent)
		{
			destroy_tree(l_node);
			destroy_tree(r_node);
			return NULL;
		}
		l_node = parent;
		while(**input && **input == ' ') (*input)++;
	}
	return l_node;
}

node *expression(char **input)
{
	node *l_node = term(input);
	if (!l_node) return NULL;

	while(**input && **input == ' ') (*input)++;

	while(**input == '+')
	{
		(*input)++;
		node *r_node = term(input);
		if (!r_node)
		{
			destroy_tree(l_node);
			return NULL;
		}
		node *parent = new_node((node){.type=ADD, .l=l_node, .r=r_node});
		if (!parent)
		{
			destroy_tree(l_node);
			destroy_tree(r_node);
			return NULL;
		}
		l_node = parent;
		while(**input && **input == ' ') (*input)++;
	}
	return l_node;
}