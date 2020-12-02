#include <utils/utils.h>

std::vector<uint32_t> utils::read_file(std::string fname){
    std::string line{};
    std::vector<uint32_t> buffer{};
    std::ifstream ifs(fname);
    while(std::getline(ifs, line)){
        buffer.push_back(std::stoi(line));
    }
    return buffer;
}

std::ostream&
operator<<(std::ostream& os,
           const std::vector<uint32_t>& file)
{
    uint8_t counter {};
    os << "[";
    for(const auto& n: file){
        os << n;
        if(n != *file.rbegin()){
            os << ", ";
        }
        if(!(++counter%10)){
            os << '\n';
        }
    }
    os << "]\n";
    return os;
}
