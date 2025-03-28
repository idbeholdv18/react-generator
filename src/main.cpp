#include <iostream>
#include "generate_component.h"

int main()
{
    std::cout << "Enter component name: ";
    std::string component_name;
    std::cin >> component_name;

    generate_component::GenerateComponent generator(component_name);
    generator.generate();

    return 0;
}