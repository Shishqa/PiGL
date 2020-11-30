/*============================================================================*/
#include <fstream>
#include <iostream>
#include <cassert>
#include <sys/stat.h>
#include <string_view>

#include "Text.hpp"
#include "ResourceManager.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Text::Text(const std::string_view& file)
    : filename(file) {

    auto& text = ResourceManager::get(filename);
    for (size_t i = 0; i < text.size; ++i) {
        printf("%c", text.data[i]);
    }


    std::string_view buf_str(reinterpret_cast<const char*>(text.data), text.size);

    printf("%s", buf_str.data());

    size_t curr_pos = 0;
    do {
        size_t line_end = buf_str.find('\n', curr_pos);

        printf("%lu -- %lu (%lu)\n", curr_pos, line_end, std::string_view::npos);

        if (line_end == std::string_view::npos) {
            text_lines.emplace_back(buf_str.substr(curr_pos, buf_str.size() - curr_pos));
            curr_pos = line_end;
        } else {
            text_lines.emplace_back(buf_str.substr(curr_pos, line_end - curr_pos));
            text.data[line_end] = '\0';
            curr_pos = line_end + 1;
        }

    } while (curr_pos != std::string_view::npos);

    for (auto& line : lines()) {
        printf("%s\n", line.data());
    }

    printf("text constructed!\n");

}

/*----------------------------------------------------------------------------*/

const ResourceManager::Resource& Text::data() const {
    return ResourceManager::get(filename);
}

/*============================================================================*/
