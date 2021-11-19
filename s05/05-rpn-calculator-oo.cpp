/*
 * A reverse-polish notation calculator.
 */

#include "RPN_calculator.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>


static auto pop_top(std::stack<double>& stack) -> double
{
    if (stack.empty()) {
        throw std::logic_error{"empty stack"};
    }
    auto element = std::move(stack.top());
    stack.pop();
    return element;
}


namespace student { namespace rpn_calculator {
Element::~Element()
{}

Literal::Literal(double const v) : value{v}
{}
auto Literal::evaluate(stack_type& stack) const -> void
{
    stack.push(value);
}

auto Print::evaluate(stack_type& stack) const -> void
{
    std::cout << stack.top() << "\n";
}


auto Addition::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for +"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a + b);
}

auto Subtraction::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for -"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a - b);
} 

auto Multiplication::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for *"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a * b);
} 

auto Devision::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for /"};
    }    
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    if (a == 0) {
        throw std::logic_error{"cant devide by 0"};
    }
    else {
    stack.push(a / b);
    }
} 

auto IntDevision::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for //"};
    }    
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    if (a == 0) {
        throw std::logic_error{"cant devide by 0"};
    }
    else {
    stack.push(floor(a / b));
    }
} 

auto Modulo::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for %"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(fmod(a,b));
} 

auto Pow::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for **"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(pow(a,b));
} 

auto Sqrt::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 1) {
        throw std::logic_error{"not enough operands for sqrt"};
    }    
    auto const a = pop_top(stack);
    stack.push(sqrt(a));
} 

auto Circle::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 1) {
        throw std::logic_error{"not enough operands for circle"};
    }    
    auto const a = pop_top(stack);
    stack.push(M_PI * a *2);
} 

Calculator::Calculator(stack_type s) : stack{std::move(s)}
{}

auto Calculator::push(std::unique_ptr<Element> op) -> void
{
    ops.push(std::move(op));
}

// FIXME implement Calculator::push(std::string)

auto Calculator::evaluate() -> void
{
    while (not ops.empty()) {
        auto op = std::move(ops.front());
        ops.pop();

        op->evaluate(stack);
    }
}
}}  // namespace student::rpn_calculator


auto make_args(int argc, char* argv[], bool const with_exec = false)
    -> std::vector<std::string>
{
    auto args         = std::vector<std::string>{};
    auto const offset = static_cast<size_t>(not with_exec);
    std::copy_n(argv + offset, argc - offset, std::back_inserter(args));
    return args;
}

auto main(int argc, char* argv[]) -> int
{
    using student::rpn_calculator::Calculator;
    auto calculator = Calculator{};

    for (auto const& each : make_args(argc, argv)) {
        try { 
            using student::rpn_calculator::Addition;
            using student::rpn_calculator::Literal;
            using student::rpn_calculator::Subtraction;
            using student::rpn_calculator::Multiplication;
            using student::rpn_calculator::Devision;
            using student::rpn_calculator::IntDevision;
            using student::rpn_calculator::Modulo;
            using student::rpn_calculator::Pow;
            using student::rpn_calculator::Sqrt;	
            using student::rpn_calculator::Circle;
            using student::rpn_calculator::Print;	

            if (each == "p") {
                calculator.push(std::make_unique<Print>());
            } else if (each == "+") {
                calculator.push(std::make_unique<Addition>());
            } else if (each == "-") {    
				calculator.push(std::make_unique<Subtraction>());
			 } else if (each == "*") {    
				calculator.push(std::make_unique<Multiplication>());
			} else if (each == "/") {    
				calculator.push(std::make_unique<Devision>());
			} else if (each == "//") {    
				calculator.push(std::make_unique<IntDevision>());
			} else if (each == "%") {    
				calculator.push(std::make_unique<Modulo>());
			} else if (each == "**") {    
				calculator.push(std::make_unique<Pow>());
			} else if (each == "sqrt") {    
				calculator.push(std::make_unique<Sqrt>());
			} else if (each == "circle") {    
				calculator.push(std::make_unique<Circle>());
            } else {
                calculator.push(std::make_unique<Literal>(std::stod(each)));
            }
        } catch (std::logic_error const& e) {
            std::cerr << "error: " << each << ": " << e.what() << "\n";
        }
    }

    try {
        calculator.evaluate();
    } catch (std::logic_error const& e) {
        std::cerr << "error: during evaluation: " << e.what() << "\n";
    }

    return 0;
}
