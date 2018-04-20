/*********************************************************************
 
 === WARNING! ===
 
 The code in this file only contains INTERNAL IMPLEMENTATION code
 for the LPCGraphics library. You SHOULD NOT edit it, and you do NOT
 need to read or understand it in order to use the library.
 
 **********************************************************************/

#include <string>
#include <map>
#include "color.h"
#include "utility.h"
#include <iostream>
using namespace std;

extern const unsigned int keyFAKE = 42;

string _component_names[3] = { "red", "green", "blue" };
map<string, string> * _color_map;
bool _colors_ready = false;

void color_map_init()
{
    if (_colors_ready)
        return;
    
    static string _color_table[296] =
    { "AliceBlue", "#F0F8FF",
        "AntiqueWhite", "#FAEBD7",
        "Aqua", "#00FFFF",
        "Aquamarine", "#7FFFD4",
        "Azure", "#F0FFFF",
        "Beige", "#F5F5DC",
        "Bisque", "#FFE4C4",
        "Black", "#000000",
        "BlanchedAlmond", "#FFEBCD",
        "Blue", "#0000FF",
        "BlueViolet", "#8A2BE2",
        "Brown", "#A52A2A",
        "BurlyWood", "#DEB887",
        "CadetBlue", "#5F9EA0",
        "Chartreuse", "#7FFF00",
        "Chocolate", "#D2691E",
        "Coral", "#FF7F50",
        "CornflowerBlue", "#6495ED",
        "Cornsilk", "#FFF8DC",
        "Crimson", "#DC143C",
        "Cyan", "#00FFFF",
        "DarkBlue", "#00008B",
        "DarkCyan", "#008B8B",
        "DarkGoldenRod", "#B8860B",
        "DarkGray", "#A9A9A9",
        "DarkGrey", "#A9A9A9",
        "DarkGreen", "#006400",
        "DarkKhaki", "#BDB76B",
        "DarkMagenta", "#8B008B",
        "DarkOliveGreen", "#556B2F",
        "DarkOrange", "#FF8C00",
        "DarkOrchid", "#9932CC",
        "DarkRed", "#8B0000",
        "DarkSalmon", "#E9967A",
        "DarkSeaGreen", "#8FBC8F",
        "DarkSlateBlue", "#483D8B",
        "DarkSlateGray", "#2F4F4F",
        "DarkSlateGrey", "#2F4F4F",
        "DarkTurquoise", "#00CED1",
        "DarkViolet", "#9400D3",
        "DeepPink", "#FF1493",
        "DeepSkyBlue", "#00BFFF",
        "DimGray", "#696969",
        "DimGrey", "#696969",
        "DodgerBlue", "#1E90FF",
        "FireBrick", "#B22222",
        "FloralWhite", "#FFFAF0",
        "ForestGreen", "#228B22",
        "Fuchsia", "#FF00FF",
        "Gainsboro", "#DCDCDC",
        "GhostWhite", "#F8F8FF",
        "Gold", "#FFD700",
        "GoldenRod", "#DAA520",
        "Gray", "#808080",
        "Grey", "#808080",
        "Green", "#008000",
        "GreenYellow", "#ADFF2F",
        "HoneyDew", "#F0FFF0",
        "HotPink", "#FF69B4",
        "IndianRed", "#CD5C5C",
        "Indigo", "#4B0082",
        "Ivory", "#FFFFF0",
        "Khaki", "#F0E68C",
        "Lavender", "#E6E6FA",
        "LavenderBlush", "#FFF0F5",
        "LawnGreen", "#7CFC00",
        "LemonChiffon", "#FFFACD",
        "LightBlue", "#ADD8E6",
        "LightCoral", "#F08080",
        "LightCyan", "#E0FFFF",
        "LightGoldenRodYellow", "#FAFAD2",
        "LightGray", "#D3D3D3",
        "LightGrey", "#D3D3D3",
        "LightGreen", "#90EE90",
        "LightPink", "#FFB6C1",
        "LightSalmon", "#FFA07A",
        "LightSeaGreen", "#20B2AA",
        "LightSkyBlue", "#87CEFA",
        "LightSlateGray", "#778899",
        "LightSlateGrey", "#778899",
        "LightSteelBlue", "#B0C4DE",
        "LightYellow", "#FFFFE0",
        "Lime", "#00FF00",
        "LimeGreen", "#32CD32",
        "Linen", "#FAF0E6",
        "Magenta", "#FF00FF",
        "Maroon", "#800000",
        "MediumAquaMarine", "#66CDAA",
        "MediumBlue", "#0000CD",
        "MediumOrchid", "#BA55D3",
        "MediumPurple", "#9370DB",
        "MediumSeaGreen", "#3CB371",
        "MediumSlateBlue", "#7B68EE",
        "MediumSpringGreen", "#00FA9A",
        "MediumTurquoise", "#48D1CC",
        "MediumVioletRed", "#C71585",
        "MidnightBlue", "#191970",
        "MintCream", "#F5FFFA",
        "MistyRose", "#FFE4E1",
        "Moccasin", "#FFE4B5",
        "NavajoWhite", "#FFDEAD",
        "Navy", "#000080",
        "OldLace", "#FDF5E6",
        "Olive", "#808000",
        "OliveDrab", "#6B8E23",
        "Orange", "#FFA500",
        "OrangeRed", "#FF4500",
        "Orchid", "#DA70D6",
        "PaleGoldenRod", "#EEE8AA",
        "PaleGreen", "#98FB98",
        "PaleTurquoise", "#AFEEEE",
        "PaleVioletRed", "#DB7093",
        "PapayaWhip", "#FFEFD5",
        "PeachPuff", "#FFDAB9",
        "Peru", "#CD853F",
        "Pink", "#FFC0CB",
        "Plum", "#DDA0DD",
        "PowderBlue", "#B0E0E6",
        "Purple", "#800080",
        "RebeccaPurple", "#663399",
        "Red", "#FF0000",
        "RosyBrown", "#BC8F8F",
        "RoyalBlue", "#4169E1",
        "SaddleBrown", "#8B4513",
        "Salmon", "#FA8072",
        "SandyBrown", "#F4A460",
        "SeaGreen", "#2E8B57",
        "SeaShell", "#FFF5EE",
        "Sienna", "#A0522D",
        "Silver", "#C0C0C0",
        "SkyBlue", "#87CEEB",
        "SlateBlue", "#6A5ACD",
        "SlateGray", "#708090",
        "SlateGrey", "#708090",
        "Snow", "#FFFAFA",
        "SpringGreen", "#00FF7F",
        "SteelBlue", "#4682B4",
        "Tan", "#D2B48C",
        "Teal", "#008080",
        "Thistle", "#D8BFD8",
        "Tomato", "#FF6347",
        "Turquoise", "#40E0D0",
        "Violet", "#EE82EE",
        "Wheat", "#F5DEB3",
        "White", "#FFFFFF",
        "WhiteSmoke", "#F5F5F5",
        "Yellow", "#FFFF00",
        "YellowGreen", "#9ACD32" };
    
    _color_map = new map<string, string>;
    for (int i = 0; i < 148; i++)
    {
        (*_color_map)[ConvertToLowercase(_color_table[2*i])] = _color_table[2*i + 1];
    }
    _colors_ready = true;
}

static void hex_color_convert(string s, unsigned int components[])
{
    char h;
    s = ConvertToUppercase(s);
    size_t len = s.length();
    if (len != 3 && len != 6)
        Error("Hex triplet for color must have 3 or 6 characters");
    
    for (unsigned int i = 0; i < 3; i++)
    {
        unsigned int value = 0;
        for (unsigned int k = 0; k < 2; k++)
        {
            if (len == 3)
                h = s[i];
            else // len == 6
                h = s[i*2+k];
            
            value *= 16;
            
            if (h >= '0' && h <= '9')
            {
                value += (h - '0');
            }
            else if (h >= 'A' && h <= 'F')
            {
                value += (h - 'A' + 10);
            }
            else
            {
                Error(string("Hex triplet contains invalid value '") + h + "'");
            }
        }
        components[i] = value;
    }
}

static void named_color_convert(string s, unsigned int components[])
{
    map<string, string>::iterator iter = _color_map->find(s);
    if (iter == _color_map->end())
    {
        Error(string("Color name '") + s + "' is unknown");
    }
    else
    {
        hex_color_convert(iter->second.substr(1), components);
    }
}

Color::Color(unsigned int r, unsigned int g, unsigned int b)
{
    color_map_init();
    _components[0] = r;
    _components[1] = g;
    _components[2] = b;
    checkinit();
}

Color::Color(unsigned int gray)
{
    color_map_init();
    for (int i = 0; i < 3; i++)
        _components[i] = gray;
    checkinit();
}

Color::Color(string str)
{
    color_map_init();
    if (str[0] == '#')
        hex_color_convert(str.substr(1), _components);
    else
        named_color_convert(ConvertToLowercase(str), _components);
    checkinit();
}

Color::Color(const char colorName[]) : Color(string(colorName))
{
    
}

Color::Color()
{
    for (int i = 0; i < 3; i++)
        _components[i] = 0;
}

void Color::checkinit()
{
    for (int i = 0; i < 3; i++)
    {
        if (_components[i] > 255)
        {
            string problem = "A color object was created with its ";
            problem += _component_names[i];
            problem += " set to " + IntToString(_components[i]);
            problem += ", which is over the maximum of 255";
            Error(problem);
        }
    }
}



