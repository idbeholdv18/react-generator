#include "generate_component.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;

namespace generate_component
{
    GenerateComponent::GenerateComponent(const std::string &name) : _componentName(name) {}

    void GenerateComponent::generate()
    {
        const std::string js_template_path = "templates/component.js.template";
        const std::string css_template_path = "templates/component.css.template";

        std::ifstream js_template_file(js_template_path);
        std::ifstream css_template_file(css_template_path);

        if (!js_template_file.is_open() || !css_template_file.is_open())
        {
            std::cerr << "Templates open error!" << std::endl;
            return;
        }

        std::stringstream js_template_stream, css_template_stream;
        js_template_stream << js_template_file.rdbuf();
        css_template_stream << css_template_file.rdbuf();

        std::string js_code = js_template_stream.str();
        std::string css_code = css_template_stream.str();

        size_t pos;
        while ((pos = js_code.find("{{component_name}}")) != std::string::npos)
        {
            js_code.replace(pos, 17, _componentName);
        }
        while ((pos = css_code.find("{{component_name}}")) != std::string::npos)
        {
            css_code.replace(pos, 17, _componentName);
        }

        fs::create_directory(_componentName);

        std::ofstream js_output(_componentName + "/" + _componentName + ".js");
        std::ofstream css_output(_componentName + "/" + _componentName + ".css");

        js_output << js_code;
        css_output << css_code;

        std::cout << "Component " << _componentName << " has been created!7" << std::endl;
    }
}
