#include <iostream>
#include <vector>
#include <fstream>
#include <random>

std::vector<std::string> read_file(std::string path);
void print_title(std::string title);
int get_random_in_range(int from, int to);

int main(int, char**) {
    print_title("Name Generator");

    auto names = read_file("names.txt");
    auto last_names = read_file("last_names.txt");    

    auto name = names[get_random_in_range(0, names.size())];
    auto last_name = last_names[get_random_in_range(0, last_names.size())];

    std::cout << "Your random name is: " << name << " " << last_name << "\n";
}

void print_title(std::string title)
{
    std::cout << "\n    #    " << title << "    #\n\n";
}

std::vector<std::string> read_file(std::string path)
{
    std::ifstream file(path.c_str());

    std::vector<std::string> content;

    if(!file)
    {
        throw std::runtime_error("Cannot open the file");
    }

    std::string tmp;
    while(std::getline(file, tmp))
        content.push_back(tmp);

    file.close();
            
    return content;
}

int get_random_in_range(int from, int to)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribution(from, to);

    return distribution(gen);
}