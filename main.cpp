#include "FordJohnsonAlgorithm.hpp"

#include <ctime>

int main(int ac, char *av[])
{
	clock_t timeVec;
	clock_t timeDeq;
	FordJohnsonAlgorithm::PmergeVector pmVec;
	FordJohnsonAlgorithm::PmergeDeque pmDeq;

	if (ac == 1)
	{
		std::cerr << "usage: " << av[0] << " ...numbers" << std::endl;
		return (1);
	}

	try
	{
		timeVec = clock();
		pmVec.applyMergeInsertSort(av);
		timeVec = clock() - timeVec;

		timeDeq = clock();
		pmDeq.applyMergeInsertSort(av);
		timeDeq = clock() - timeDeq;

		std::cout << "Before: ";
		pmVec.printBefore();
		std::cout << std::endl;

		std::cout << "After: ";
		pmVec.printAfter();
		std::cout << std::endl;

		std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << (float)timeVec * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << (float)timeDeq * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
