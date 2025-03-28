#ifndef GENERATE_COMPONENT_H
#define GENERATE_COMPONENT_H

#include <string>

namespace generate_component
{
    class GenerateComponent
    {
    public:
        GenerateComponent(const std::string &componentName);
        void generate();

    private:
        std::string _componentName;
    };
}

#endif