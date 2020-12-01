/*============================================================================*/
#include "Color.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
        : r(red), g(green), b(blue), a(alpha)
        { }

/*----------------------------------------------------------------------------*/

uint8_t multiply(const uint8_t& a, const uint8_t& b) {
    return static_cast<uint8_t>(
            static_cast<uint16_t>(a) * static_cast<uint16_t>(b) / 255
    );
}

uint8_t add(const uint8_t& a, const uint8_t& b) {

    uint16_t sum = static_cast<uint16_t>(a) + static_cast<uint16_t>(b);

    return static_cast<uint8_t>(sum > 255 ? 255 : sum);
}

Color& Color::operator*=(const uint8_t& intensity) {
    r = multiply(r, intensity);
    g = multiply(g, intensity);
    b = multiply(b, intensity);
    return *this;
}

Color Color::operator*(const uint8_t& intensity) {
    return (Color{*this} *= intensity);
}

Color& Color::operator*=(const Color& right) {
    r = multiply(r, right.r);
    r = multiply(g, right.g);
    r = multiply(b, right.b);
    return *this;
}

Color Color::operator*(const Color& right) {
    return (Color{*this} *= right);
}

Color& Color::operator+=(const Color& right) {
    r = add(r, right.r);
    g = add(g, right.g);
    b = add(b, right.b);
    return *this;
}

Color Color::operator+(const Color& right) {
    return (Color{*this} += right);
}


/*============================================================================*/

const Color Color::NONE                     (  0,   0,   0,  0);
const Color Color::INDIAN_RED               (205,  92,  92);
const Color Color::LIGHT_CORAL              (240, 128, 128);
const Color Color::SALMON                   (250, 128, 114);
const Color Color::DARK_SALMON              (233, 150, 122);
const Color Color::LIGHT_SALMON             (255, 160, 122);
const Color Color::CRIMSON                  (220,  20,  60);
const Color Color::RED                      (255,   0,   0);
const Color Color::FIRE_BRICK               (178,  34,  34);
const Color Color::DARK_RED                 (139,   0,   0);
const Color Color::PINK                     (255, 192, 203);
const Color Color::LIGHT_PINK               (255, 182, 193);
const Color Color::HOT_PINK                 (255, 105, 180);
const Color Color::DEEP_PINK                (255,  20, 147);
const Color Color::MEDIUM_VIOLET_RED        (199,  21, 133);
const Color Color::PALE_VIOLET_RED          (219, 112, 147);
const Color Color::CORAL                    (255, 127,  80);
const Color Color::TOMATO                   (255,  99,  71);
const Color Color::ORANGE_RED               (255,  69,   0);
const Color Color::DARK_ORANGE              (255, 140,   0);
const Color Color::ORANGE                   (255, 165,   0);
const Color Color::GOLD                     (255, 215,   0);
const Color Color::YELLOW                   (255, 255,   0);
const Color Color::LIGHT_YELLOW             (255, 255, 224);
const Color Color::LEMON_CHIFFON            (255, 250, 205);
const Color Color::LIGHT_GOLDENROD_YELLOW   (250, 250, 210);
const Color Color::PAPAYA_WHIP              (255, 239, 213);
const Color Color::MOCCASIN                 (255, 228, 181);
const Color Color::PEACH_PUFF               (255, 218, 185);
const Color Color::PALE_GOLDENROD           (238, 232, 170);
const Color Color::KHAKI                    (240, 230, 140);
const Color Color::DARK_KHAKI               (189, 183, 107);
const Color Color::LAVENDER                 (230, 230, 250);
const Color Color::THISTLE                  (216, 191, 216);
const Color Color::PLUM                     (221, 160, 221);
const Color Color::VIOLET                   (238, 130, 238);
const Color Color::ORCHID                   (218, 112, 214);
const Color Color::FUCHSIA                  (255,   0, 255);
const Color Color::MAGENTA                  (255,   0, 255);
const Color Color::MEDIUM_ORCHID            (186,  85, 211);
const Color Color::MEDIUM_PURPLE            (147, 112, 219);
const Color Color::BLUE_VIOLET              (138,  43, 226);
const Color Color::DARK_VIOLET              (148,   0, 211);
const Color Color::DARK_ORCHID              (153,  50, 204);
const Color Color::DARK_MAGENTA             (139,   0, 139);
const Color Color::PURPLE                   (128,   0, 128);
const Color Color::INDIGO                   ( 75,   0, 130);
const Color Color::SLATE_BLUE               (106,  90, 205);
const Color Color::DARK_SLATE_BLUE          ( 72,  61, 139);
const Color Color::CORNSILK                 (255, 248, 220);
const Color Color::BLANCHED_ALMOND          (255, 235, 205);
const Color Color::BISQUE                   (255, 228, 196);
const Color Color::NAVAJO_WHITE             (255, 222, 173);
const Color Color::WHEAT                    (245, 222, 179);
const Color Color::BURLY_WOOD               (222, 184, 135);
const Color Color::TAN                      (210, 180, 140);
const Color Color::ROSY_BROWN               (188, 143, 143);
const Color Color::SANDY_BROWN              (244, 164,  96);
const Color Color::GOLDENROD                (218, 165,  32);
const Color Color::DARK_GOLDEN_ROD          (184, 134,  11);
const Color Color::PERU                     (205, 133,  63);
const Color Color::CHOCOLATE                (210, 105,  30);
const Color Color::SADDLE_BROWN             (139,  69,  19);
const Color Color::SIENNA                   (160,  82,  45);
const Color Color::BROWN                    (165,  42,  42);
const Color Color::MAROON                   (128,   0,   0);
const Color Color::BLACK                    (  0,   0,   0);
const Color Color::GRAY                     (128, 128, 128);
const Color Color::SILVER                   (192, 192, 192);
const Color Color::WHITE                    (255, 255, 255);
const Color Color::OLIVE                    (128, 128,   0);
const Color Color::LIME                     (  0, 255,   0);
const Color Color::GREEN                    (  0, 128,   0);
const Color Color::AQUA                     (  0, 255, 255);
const Color Color::TEAL                     (  0, 128, 128);
const Color Color::BLUE                     (  0,   0, 255);
const Color Color::NAVY                     (  0,   0, 128);
const Color Color::GREEN_YELLOW             (173, 255,  47);
const Color Color::CHARTREUSE               (127, 255,   0);
const Color Color::LAWN_GREEN               (124, 252,   0);
const Color Color::LIME_GREEN               ( 50, 205,  50);
const Color Color::PALE_GREEN               (152, 251, 152);
const Color Color::LIGHT_GREEN              (144, 238, 144);
const Color Color::MEDIUM_SPRING_GREEN      (  0, 250, 154);
const Color Color::SPRING_GREEN             (  0, 255, 127);
const Color Color::MEDIUM_SEA_GREEN         ( 60, 179, 113);
const Color Color::SEA_GREEN                ( 46, 139,  87);
const Color Color::FOREST_GREEN             ( 34, 139,  34);
const Color Color::DARK_GREEN               (  0, 100,   0);
const Color Color::YELLOW_GREEN             (154, 205,  50);
const Color Color::OLIVE_DRAB               (107, 142,  35);
const Color Color::DARK_OLIVE_GREEN         ( 85, 107,  47);
const Color Color::MEDIUM_AQUAMARINE        (102, 205, 170);
const Color Color::DARK_SEA_GREEN           (143, 188, 143);
const Color Color::LIGHT_SEA_GREEN          ( 32, 178, 170);
const Color Color::DARK_CYAN                (  0, 139, 139);
const Color Color::CYAN                     (  0, 255, 255);
const Color Color::LIGHT_CYAN               (224, 255, 255);
const Color Color::PALE_TURQUOISE           (175, 238, 238);
const Color Color::AQUAMARINE               (127, 255, 212);
const Color Color::TURQUOISE                ( 64, 224, 208);
const Color Color::MEDIUM_TURQUOISE         ( 72, 209, 204);
const Color Color::DARK_TURQUOISE           (  0, 206, 209);
const Color Color::CADET_BLUE               ( 95, 158, 160);
const Color Color::STEEL_BLUE               ( 70, 130, 180);
const Color Color::LIGHT_STEEL_BLUE         (176, 196, 222);
const Color Color::POWDER_BLUE              (176, 224, 230);
const Color Color::LIGHT_BLUE               (173, 216, 230);
const Color Color::SKY_BLUE                 (135, 206, 235);
const Color Color::LIGHT_SKY_BLUE           (135, 206, 250);
const Color Color::DEEP_SKY_BLUE            (  0, 191, 255);
const Color Color::DODGER_BLUE              ( 30, 144, 255);
const Color Color::CORNFLOWER_BLUE          (100, 149, 237);
const Color Color::MEDIUM_SLATE_BLUE        (123, 104, 238);
const Color Color::ROYAL_BLUE               ( 65, 105, 225);
const Color Color::MEDIUM_BLUE              (  0,   0, 205);
const Color Color::DARK_BLUE                (  0,   0, 139);
const Color Color::MIDNIGHT_BLUE            ( 25,  25, 112);
const Color Color::SNOW                     (255, 250, 250);
const Color Color::HONEYDEW                 (240, 255, 240);
const Color Color::MINT_CREAM               (245, 255, 250);
const Color Color::AZURE                    (240, 255, 255);
const Color Color::ALICE_BLUE               (240, 248, 255);
const Color Color::GHOST_WHITE              (248, 248, 255);
const Color Color::WHITE_SMOKE              (245, 245, 245);
const Color Color::SEASHELL                 (255, 245, 238);
const Color Color::BEIGE                    (245, 245, 220);
const Color Color::OLD_LACE                 (253, 245, 230);
const Color Color::FLORAL_WHITE             (255, 250, 240);
const Color Color::IVORY                    (255, 255, 240);
const Color Color::ANTIQUE_WHITE            (250, 235, 215);
const Color Color::LINEN                    (250, 240, 230);
const Color Color::LAVENDER_BLUSH           (255, 240, 245);
const Color Color::MISTY_ROSE               (255, 228, 225);
const Color Color::GAINSBORO                (220, 220, 220);
const Color Color::LIGHT_GREY               (211, 211, 211);
const Color Color::LIGHT_GRAY               (211, 211, 211);
const Color Color::DARK_GRAY                (169, 169, 169);
const Color Color::DARK_GREY                (169, 169, 169);
const Color Color::GREY                     (128, 128, 128);
const Color Color::DIM_GRAY                 (105, 105, 105);
const Color Color::DIM_GREY                 (105, 105, 105);
const Color Color::LIGHT_SLATE_GRAY         (119, 136, 153);
const Color Color::LIGHT_SLATE_GREY         (119, 136, 153);
const Color Color::SLATE_GRAY               (112, 128, 144);
const Color Color::SLATE_GREY               (112, 128, 144);
const Color Color::DARK_SLATE_GRAY          ( 47,  79,  79);
const Color Color::DARK_SLATE_GREY          ( 47,  79,  79);


/*============================================================================*/
