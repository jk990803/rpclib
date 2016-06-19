#include <iostream>

#include "rpc/client.h"
#include "rpc/rpc_error.h"

int main() {
    rpc::client c("localhost", 8080);
    try {
        std::cout << "add(2, 3) = ";
        double five = c.call("add", 2, 3).as<double>();
        std::cout << five << std::endl;

        std::cout << "sub(3, 2) = ";
        double one = c.call("sub", 3, 2).as<double>();
        std::cout << one << std::endl;

        std::cout << "mul(5, 0) = ";
        double zero = c.call("mul", five, 0).as<double>();
        std::cout << zero << std::endl;

        std::cout << "div(3, 0) = ";
        double hmm = c.call("div", 3, 0).as<double>();
        std::cout << hmm << std::endl;
    } catch (rpc::rpc_error &e) {
        std::cout << std::endl << e.what() << std::endl;
        std::cout << "in function " << e.get_function_name() << ": "
                  << std::endl;
        std::cout << e.get_error().get() << std::endl;
    }
}