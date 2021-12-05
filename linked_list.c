#include "main.h"

/**
 * print_list - function that print a linked list
 * @head: address of the first node
 * Return: number of node found
 */

int print_list(const directory_t *head)
{
	int number_of_nodes = 0;

	while (head != NULL)
	{
		if (head->value == NULL)
		{
			_putchar('[');
			_puts_integer(number_of_nodes);
			_puts_string("] (nil)\n");
		}
		else
		{
			_putchar('[');
			_puts_integer(number_of_nodes);
			_puts_string("] ");
			_puts_string(head->value);
			_putchar('\n');
		}
		number_of_nodes++;
		head = head->next;
	}

	return (number_of_nodes);
}


/**
 * add_node - function that adds a new node at the beginning of a directory_t
 * @head: address of the first node
 * @value: new value to add in the list
 * Return: new address of the linked list, NULL if failed
 */

directory_t *add_node(directory_t **head, const char *value)
{
	directory_t *new = NULL;

	new = malloc(sizeof(directory_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->value = malloc(sizeof(char) * (_strlen((char *)value) + 1));
	new->value = _strcpy(new->value, (char *)value);
	new->next = *head;
	*head = new;

	return (*head);
}


/**
 * add_node_end - function that adds a new node at the end of a list_t list
 * @head: address of node
 * @value: new value to add in the list
 * Return: address of the linked list, NULL if failed
 */

directory_t *add_node_end(directory_t **head, const char *value)
{
	directory_t *new_list, *old_list;

	new_list = malloc(sizeof(directory_t));
	if (new_list == NULL)
		return (NULL);

	new_list->value = _strdup((char *)value);

	if (*head == NULL)
		*head = new_list;
	else
	{
		old_list = *head;
		while (old_list->next != NULL)
			old_list = old_list->next;
		old_list->next = new_list;
	}

	return (*head);
}


/**
 * free_list - function that frees a list_t list
 * @head: address of node
 */

void free_list(directory_t *head)
{
	directory_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->value);
		free(tmp);
	}
}
