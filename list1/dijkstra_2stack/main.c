#include "stack.h"

int main(int argc, char **argv)
{
	int nOperands = 0;
	int nOperators = 0;

	for (int i = 0; i < argc; i++)
	{
		if (*argv[i] != '(' && *argv[i] != ')' && is_operator(argv[i]))
		{
			nOperators++;
		}
		else
		{
			nOperands++;
		}
	}

	double *operandDoubles = malloc(sizeof(double) * nOperators);

	Stack *operators = create_stack();
	Stack *operands = create_stack();

	int accessOperands = 0;
	for (int i = 1; i < argc; i++)
	{
		if (*argv[i] != '(' && *argv[i] != ')')
		{
			if (is_operator(argv[i]))
			{
				Item *item = create_item(OPERATOR, argv[i]);
				push(operators, item);
			}
			else
			{
				operandDoubles[accessOperands] = atof(argv[i]);
				Item *item = create_item(OPERAND, &operandDoubles[accessOperands]);
				push(operands, item);
				accessOperands++;
			}
		}
		else
		{
			if (*argv[i] == ')')
			{
				accessOperands -= 2;

				Item *currentOperand1 = pop(operands);
				Item *currentOperand2 = pop(operands);
				Item *currentOperator = pop(operators);

				operandDoubles[accessOperands] = compute_values(currentOperand2, currentOperand1, currentOperator);
				Item *newItem = create_item(OPERAND, &operandDoubles[accessOperands]);

				push(operands, newItem);

				free(currentOperand1);
				free(currentOperand2);
				free(currentOperator);

				accessOperands++;
			}
		}
	}

	print_stack(operands);
	print_stack(operators);

	free(operandDoubles);
	free_stack(operands);
	free_stack(operators);
}
