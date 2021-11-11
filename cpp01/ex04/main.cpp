#include <fstream>
#include <iostream>

int	read_infile(std::ifstream &ifs, std::string &str)
{
	if (ifs.fail())
	{
		std::cout << "Failed to open file" << std::endl;
		return (-1);
	}
	for (std::string tmp; std::getline(ifs, tmp);)
	{
		str += tmp;
		if (!ifs.eof())
			str += "\n";
	}
	return (1);
}

std::string	&replace(std::string &str, const std::string s1, const std::string s2)
{
	const size_t	len1 = s1.length();
	const size_t	len2 = s2.length();
	size_t			find_pos = 0;

	while (1)
	{
		size_t pos = str.find(s1, find_pos);
		if (pos == std::string::npos)
			break ;
		str.erase(pos, len1);
		str.insert(pos, s2);
		find_pos = pos + len2;
	}
	return (str);
}

void	stream_to_outfile(std::string &str, std::string infilename)
{
	std::string ofname(infilename);

	ofname += ".replace";
	std::ofstream ofs(ofname);
	if (!ofs)
	{
		std::cout << "error" << std::endl;
		return ;
	}
	ofs << str;
	ofs.close();
	std::cout << "success to make " << ofname << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "bad argument" << std::endl;
		return (1);
	}
	else
	{
		std::ifstream	ifs(argv[1]);
		std::string		str;
		
		if (read_infile(ifs, str) == -1)
		{
			return (1);
		}
		str = replace(str, argv[2], argv[3]);
		stream_to_outfile(str, argv[1]);
	}
	return (0);
}
