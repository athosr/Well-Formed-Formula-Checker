// Write an algorithm that, given a sequence of characters, determine whether it is a propositional logic formula

#include <iostream>
#include <string>

void recursive_loop(std::string);
bool is_letter(char);
bool is_symbol(char);
bool is_open_brackets(char);
bool is_close_brackets(char);
bool is_not(char);

char letters[] = { 'p', 'q', 'r', 's' };
char symbols[] = { '>', '^', '=', 'v' };
char open_brackets = '(';
char close_brackets = ')';
char NOT = '~';

// If invalid_logic is greater than 0, then it's a invalid propositional logic
int invalid_logic = 0;

unsigned int index = 0;
int open_brackets_count = 0;
int close_brackets_count = 0;

int main()
{
	// Enter the formula to be checked
	std::string formula = "(p>~q)>~(p=q)";

	recursive_loop(formula);

	if (!invalid_logic && open_brackets_count == close_brackets_count)
		std::cout << "This is a valid propositional logic! \n";
	else
		std::cout << "This is a invalid propositional logic. \n";

	std::cout << "----> " << formula << std::endl;

	std::cin.ignore();
	return 0;
}

void recursive_loop(std::string formula)
{
	if (index <= formula.length())
	{
		// Checks if letter
		if (is_letter(formula[index]))
		{
			if (index + 1 < formula.length())
			{
				// Checks if the next character is a symbol
				if (is_symbol(formula[index + 1]))
				{
					index++;
					recursive_loop(formula);
				}
				// Checks if the next character is a close brackets
				else if (is_close_brackets(formula[index + 1]))
				{
					index++;
					recursive_loop(formula);
				}
				else { invalid_logic++; }
			}
		}
		// Checks if symbol
		else if (is_symbol(formula[index]))
		{
			if (index + 1 < formula.length())
			{
				// Checks if the next character is a letter
				if (is_letter(formula[index + 1]))
				{
					index++;
					recursive_loop(formula);
				}
				// Checks if the next character is a NOT
				else if (is_not(formula[index + 1]))
				{
					index++;
					recursive_loop(formula);
				}
				// Checks if the next character is a open brackets
				else if (is_open_brackets(formula[index + 1]))
				{
					index++;
					recursive_loop(formula);
				}
				else { invalid_logic++; }
			}
			else { invalid_logic++; }
		}
		// Checks if open brackets
		else if (is_open_brackets(formula[index]))
		{
			open_brackets_count++;
			if (index + 1 < formula.length())
			{
				// Checks if the next character is a letter
				if (is_letter(formula[index + 1]))
				{
					index++;
					recursive_loop(formula);
				}
				// Checks if the next character is a NOT
				else if (is_not(formula[index + 1]))
				{
					index++;
					recursive_loop(formula);
				}
				else { invalid_logic++; }
			}
			else { invalid_logic++; }
		}
		//Checks if close brackets
		else if (is_close_brackets(formula[index]))
		{
			close_brackets_count++;
			if (index + 1 < formula.length())
			{
				// Checks if the next character is a NOT
				if (is_not(formula[index + 1]))
				{
					index++;
					recursive_loop(formula);
				}
				// Checks if the next character is a open brackets
				else if (is_open_brackets(formula[index + 1]))
				{
					index++;
					recursive_loop(formula);
				}
				// Checks if the next character is a symbol
				else if (is_symbol(formula[index + 1]))
				{
					index++;
					recursive_loop(formula);
				}
				else { invalid_logic++; }
			}
		}
		// Checks if NOT
		else if (is_not(formula[index]))
		{
			if (index + 1 < formula.length())
			{
				// Checks if the next character is a letter
				if (is_letter(formula[index + 1]))
				{
					index++;
					recursive_loop(formula);
				}
				// Checks if the next character is a open brackets
				else if (is_open_brackets(formula[index + 1]))
				{
					index++;
					recursive_loop(formula);
				}
				else { invalid_logic++; }
			}
			else { invalid_logic++; }
		}
	}
}

bool is_letter(char c)
{
	for (char l : letters)
	{
		if (c == l) { return true; }
	}
	return false;
}

bool is_symbol(char c)
{
	for (char s : symbols)
	{
		if (c == s) { return true; }
	}
	return false;
}

bool is_open_brackets(char c)
{
	if (c == open_brackets) { return true; }
	else { return false; }
}

bool is_close_brackets(char c)
{
	if (c == close_brackets) { return true; }
	else { return false; }
}

bool is_not(char c)
{
	if (c == NOT) { return true; }
	else { return false; }
}