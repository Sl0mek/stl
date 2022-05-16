#include "compress.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, 32>, 32> input)
{
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    for (size_t i = 0; i < input.size(); i++)
    {
        auto start = 0;
        int count = 0;
        int val = 0;
        int tmp = 0;
        while (start < input[0].size() - 1)
        {
            val = input[i][start];
            count++;
            while (start < 31)
            {
                start++;
                if (input[i][start] == val)
                {
                    count++;
                    if (start == input[0].size() - 1)
                    {
                        break;
                    }
                }
                else
                {
                    vec.push_back(std::pair<uint8_t, uint8_t>{val, count});
                    count = 0;
                    break;
                }
            }
        }
        vec.push_back(std::pair<uint8_t, uint8_t>{val, count});
    }
    return vec;
}
