#include "Karen.hpp"

int main(int argc, char **argv)
{
	Karen karen;

	if (argc == 1)
	{
		karen.complain("DEBUG");
		karen.complain("INFO");
		karen.complain("WARNING");
		karen.complain("ERROR");
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			karen.complain(argv[i]);
		}
	}
}
