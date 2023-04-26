#include <iostream>
#include <vector>
#include <variant>


std::variant<int, std::string, std::vector<int>> get_variant();

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "\tstd::variant\n" << std::endl;

	std::variant<int, std::string, std::vector<int>> value = std::move(get_variant());

	if (std::holds_alternative<int>(value)) {
		std::cout << std::get<int>(value) * 2 << std::endl;
	}
	else if (std::holds_alternative<std::string>(value)) {
		std::cout << std::get<std::string>(value) << std::endl;
	}
	else {
		for (const auto& i : std::get<std::vector<int>>(value)) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	system("pause > nul");
	return 0;
}

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(static_cast<unsigned>(time(nullptr)));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}