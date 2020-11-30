/*============================================================================*/
#ifndef SHISHGL_TEXT_HPP
#define SHISHGL_TEXT_HPP
/*============================================================================*/
#include <string_view>
#include <vector>

#include "ResourceManager.hpp"
/*============================================================================*/
namespace Sh {

    class Text {
    public:

        Text() = delete;

        explicit Text(const std::string_view& filename);

        [[nodiscard]]
        const ResourceManager::Resource& data() const;

        ~Text() = default;

        [[nodiscard]]
        const std::vector<std::string_view>& lines() const { return text_lines; }

    protected:

        const std::string_view filename;

        std::vector<std::string_view> text_lines;

    };

}
/*============================================================================*/
#endif //SHISHGL_TEXT_HPP
/*============================================================================*/