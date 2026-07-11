#include <iostream>
#include <fstream>
#include <vector>


std::string cleanValue(std::string str) {
    std::string result = "";
    for (char c : str) {
        if (c != '"' && c != ',' && c != '{' && c != '}' && c != '[' && c != ']') {
            result += c;
        }
    }
    size_t start = result.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return "";

    size_t end = result.find_last_not_of(" \t\r\n");
    return result.substr(start, end - start + 1);
}

std::vector<std::string> readJson(std::string filePath)
{
    std::string line;
    std::ifstream r(filePath);
    std::vector<std::string> data;
    if(r.is_open())
    {
        while(std::getline(r, line))
        {
            data.push_back(line);
        }
        r.close();
    }
    else{
        std::cout << "Err: in open a file" << std::endl;
    }
    return data;
}
void jsonIntoTxt(std::vector<std::string> datas)
{
    std::ofstream out("dados.txt");
    if(out.is_open()){
        for(const auto& line : datas)
        {
            size_t fisrtQuote = line.find('"');
            if (fisrtQuote != std::string::npos)
            {
                size_t secondQuote = line.find('"', fisrtQuote + 1);
                if(secondQuote != std::string::npos)
                {
                    std::string key = line.substr(fisrtQuote + 1, secondQuote - fisrtQuote -1);
                    size_t colon = line.find(':', secondQuote);
                    if(colon != std::string::npos)
                    {
                        std::string rawValue = line.substr(colon + 1);
                        std::string value = cleanValue(rawValue);
                        if(!value.empty())
                        {
                            if(!key.empty()) key[0] = toupper(key[0]);
                            out << key << ": " << value << "\n";
                        }
                        else{
                            out << "\n--- " << key << " ---\n";
                        }
                    }
                }
            }
        }
        out.close();
        std::cout << "dados.txt gerado xdd\n";
    }
    else{
        std::cout << "Unable to open file";
    }
}


int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        std::vector<std::string> datas = readJson(argv[1]);
        jsonIntoTxt(datas);
    }     
}
