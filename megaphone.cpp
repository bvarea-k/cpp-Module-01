#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < argc; ++i)
    {
        for (int j = 0; argv[i][j]; ++j)
        {
            std::cout << static_cast<char>(std::toupper(argv[i][j]));
        }
    }

    std::cout << std::endl;
    return (0);
}

// static_cast<char> es más seguro que castear con char.
//Sin el casteo, debe imprimir el int porque toupper devuelve un int. Must check
