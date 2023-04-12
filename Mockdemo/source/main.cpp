#include <iostream>
#include "DependencyImpl.h"
#include "MyServiceUsingDepency.h"
int main() {

    std::unique_ptr<Dependency> impl{new DependencyImpl()};
    MyServiceUsingDepency service{std::move(impl)};



	std::cout << service.square() << std::endl;
}